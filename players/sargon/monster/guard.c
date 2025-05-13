 inherit "obj/npc";
#include "/players/mangla/defs.h"

string func,match,type;
string *gotten;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("darth");
  set_alias("vader");
  set_alt_name("dark side");
  set_level(50);
  set_al(-1000);
  set_race("human");
  set_gender(1);
  set_size(3);
  set_short("Darth Vader");
  set_long("He is dressed in black, has a black mask on his face.\n"+
  "You should fear the power of the Dark Side.\n" +
  "Darth Vader is here to protect the Jedi guild from non-jedi intruders.\n");

  load_chat(5, ({
      "Darth Vader says: You may pass if you are a Jedi.\n",
      "Darth Vader says: You must one with the force to pass by me.\n",
      "Darth Vader breathes heavily.\n",
    }) );

    if(!present("jedisoul"))
      MOVE(clone_object("players/mangla/guild/soul"),TO);
}
attack(ob) {
  if(!attacker_ob) return;

  if(!present("lightsaber",this_object()))  {
    MOVE(clone_object("players/mangla/guild/lightsaber"),TO);
    say("Darth Vader wields his weapon of choice.\n");
    init_command("wield handle");
    init_command("press button");
  }
  if(!random(2)) init_command("cast bolt");

  ::attack(ob);

}
