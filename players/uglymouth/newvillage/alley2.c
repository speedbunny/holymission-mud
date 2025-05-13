/*
 * Author : Uglymouth
 * Date   : 5-AUG-1993
 */
#include "path.h"
inherit "room/room";
int hiddencoins,robber_killed;

void reset(int arg) {

  robber_killed = 0;
  if(arg) return;

  set_light(1);
  short_desc="Deep in an obscure alley";
  long_desc="You are in deep in an obscure alley. Almost no light comes in.\n"
	+ "You feel mice running between your feet. Far north Main Street almost\n"
	+ "shines like a star. The alley gets even darker to the south.\n";
  dest_dir=({PATH+"alley1","north",
	PATH+"alley3", "south" });
  items=({
	"alley","The darkness of the alley gives you a creepy feeling",
	"light","There is almost none",
	"mice","In the darkness you see some little creatures scurry around",
	"main street","A haven of safety..",
	});
  hiddencoins = 0;
  robber_killed = 0;
}

void rob_player() {
object ob1,ob2;
int gold;  
  if(!ob1 = present("robber")) {
    ob1 = clone_object("/obj/monster");
    ob1->set_name("robber");
    ob1->set_short("A vile robber");
    ob1->set_level(4);
    ob1->set_al(-75);
    ob1->set_gender(random(2)+1);
    ob1->set_dead_ob(this_object());
    gold = random(hiddencoins);
    if(hiddencoins > 1000) gold = random(1000);
    ob1->add_money(gold);
    hiddencoins -= gold;

    ob2 = clone_object("/obj/weapon");
    ob2->set_name("dagger");
    ob2->set_short("A dagger");
    ob2->set_class(5);
    ob2->set_value(13);
    transfer(ob2,ob1);
    
    ob1->init_command("wield dagger");
    move_object(ob1,this_object());
    }

  write("Suddenly a figure looms up from the shadows and grabs your purse.\n");
  say("Suddenly a figure looms up from the shadows and grabs something from\n"
    + this_player()->query_name() + ".\n");
  gold = 50 + random(200);
  if(gold > this_player()->query_money()) gold = random(this_player()->query_money());
  this_player()->add_money(-gold);
  if((ob1->query_money() + gold) > 1000) {
    hiddencoins += ob1->query_money() + gold - 1000;
    gold = 2000 - ob1->query_money();
    }
  ob1->add_money(gold);
  call_out("hide_robber",60);
  return;
  }

void hide_robber() {
object ob1,*ob2;
int i;
  if(!ob1 = present("robber")) return 0;
  ob2 = all_inventory(ob1);
  for(i=sizeof(ob2) - 1;i >= 0;i--) destruct(ob2[i]);
  hiddencoins += ob1->query_money();
  destruct(ob1);
  tell_room(this_object(),"Someone disappears into the shadows.\n");
  return;
  }

void init() {
  ::init();
  if(!random(5) && !present("robber") && !robber_killed) rob_player();

  add_action("search","search");
}

int search(string str) {
object ob;
  if(ob = present("robber")) {
    write("You are unaware of your surroundings as you search.\n");
    rob_player();
    }
  write("You search the alley, but find nothing of interest.\n");
  return 1;
  }

monster_died() {
  if(find_call_out("hide_robber")!=-1)
      remove_call_out("hide_robber");
  robber_killed = 1;
  return 0;
  }

int query_hidden_coins() {
  return hiddencoins;
  }

set_coins(arg) {
  hiddencoins = arg;
  return 0;
  }

