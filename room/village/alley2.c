inherit "room/room";

#include "/room/room_defs.h"

int hiddencoins, robber_killed;

void reset(int arg) {
  robber_killed = 0;
  if(arg) return;

  set_light(1);
  short_desc = "Deep in an obscure alley";
  long_desc =
    "You are in deep in an obscure alley. Almost no light comes "+
    "in. You feel mice running between your feet. Far north "+
    "Main Street almost shines like a star. The alley gets even "+
    "darker to the south.\n";

  dest_dir = ({
    HM_VILLAGE + "alley1","north",
    HM_VILLAGE + "alley3", "south",
  });

  items = ({
    "alley","The darkness of the alley gives you a creepy feeling",
    "light","There is almost none",
    "mice","In the darkness you see some little creatures scurry around",
    "main street","A haven of safety..",
  });

  hiddencoins = 0;
  ::reset(arg);
}

void rob_player() {
  object ob1,ob2;
  int gold;  

  if(TP->INV > 14 || TP->IMM)
    return;

  if(!ob1 = present("robber")) {
    ob1 = clone_object("/obj/monster");
    ob1->set_name("robber");
    ob1->set_short("A vile robber");
    ob1->set_level(14);
    ob1->set_al(-175);
    ob1->set_gender(random(2)+1);
    ob1->set_dead_ob(TO);
    gold = random(hiddencoins);
    if(hiddencoins > 1000)
      gold = random(1000);
    ob1->add_money(gold);
    hiddencoins -= gold;

    ob2 = clone_object("/obj/weapon");
    ob2->set_name("dagger");
    ob2->set_short("A dagger");
    ob2->set_class(14);
    ob2->set_value(113);
    transfer(ob2, ob1);
    
    ob1->init_command("wield dagger");
    move_object(ob1, TO);
  }

  write("Suddenly a figure looms up from the shadows and grabs "+
        "your purse.\n");
  say(lw("Suddenly a figure looms up from the shadows and grabs "+
         "something from " + TP->NAME + ".\n"));

  gold = 500 + random(2000);
  if(gold > TP->query_money())
    gold = TP->query_money()/2 + random(TP->query_money()/2);

  TP->add_money(-gold);
  if((ob1->query_money() + gold) > 1000) {
    hiddencoins += ob1->query_money() + gold - 1000;
    gold = 2000 - ob1->query_money();
  }

  ob1->add_money(gold);
  call_out("hide_robber", 60);
  return;
}

void hide_robber() {
  object ob1,*ob2;
  int i;

  if(!ob1 = present("robber"))
    return;
  ob2 = all_inventory(ob1);
  for(i=sizeof(ob2)-1; i>=0; i--)
    destruct(ob2[i]);

  hiddencoins += ob1->query_money();
  destruct(ob1);
  TELLR(TO, "Someone disappears into the shadows.\n");
  return;
}

void init() {
  ::init();
  if(!random(5) && !present("robber") && !robber_killed)
    rob_player();

  add_action("_search","search");
}

int _search(string str) {
  object ob;

  if(ob = present("robber")) {
    write("You are unaware of your surroundings as you search.\n");
    rob_player();
  }
  write("You search the alley, but find nothing of interest.\n");
  return 1;
}

monster_died() {
  if(find_call_out("hide_robber") != -1)
      remove_call_out("hide_robber");
  robber_killed = 1;
  return 0;
}

int query_hidden_coins() {
  return hiddencoins;
}

void set_coins(int val) {
  hiddencoins = val;
}

