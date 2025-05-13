inherit "/obj/monster";

#define TP       this_player()
#define TO       this_object()
#define OBJ      "/players/kryll/obj/"
#define CW(x)     clone_object("/players/kryll/weapons/"+x)
#define MW(x)     move_object(x,TO)

void now_wait(object vict);

string w_name;
object weap;
int i;

void now_wait(object vict) {

  tell_object(vict,"The kobold stabber appears as he backstabs you!\n");
  TO->set_name("Kobold Stabber");
  vict->hit_player(20+random(10));
  TO->attack_object(vict);
  vict->rem_follower(TO);
  return;
}


int attack() {

 object victim;

 victim = TO->query_attack();
 if (objectp(victim))
    i++;
 if (!random(4) && i) {
    TO->stop_fight();
    TO->set_name("");
    victim->stop_fight();
    victim->set_follower(TO);
    call_out("now_wait",9,victim);
    return 0;
  }
  else
     ::attack();
}


void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Kobold Stabber");
  set_level(14);
  set_alias_list(({ "stabber", "kobold stabber", "Kobold stabber",
    "thief", "assassin" }));
  set_short("Kobold Stabber");
  set_race("kobold");
  set_size(2);
  set_al(-100);
  set_ac(1);
  if(!random(2))
    set_gender(2);
  else
    set_gender(1);
  set_wc(7);
  set_no_steal(1);
  set_wimpy(30);
  set_str(15 + random(4));
  set_dex(25 + random(4));
  set_con(15 + random(4));
  set_int(14 + random(4));
  set_wis(14 + random(4));
  set_chr(20 + random(4));
  set_long("This is a cowardly, sadistic humanoid that is " +
           "3 feet tall with scaly dark brown hide. With " +
           "their rat-like tail and raggedy garb, they " +
           "don't look like much of a threat.\n");
  add_money(300 + random(200));
  i=0;
}

void init() {
  ::init();

  switch(TP->query_race()) {
    case "troll":
    case "orc":
    case "giant":
      this_object()->attack_object(TP);
    default: break;
  }
}

