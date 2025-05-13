inherit "/obj/monster";

#include "/players/matt/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("black dragon");
  set_short("Black dragon");
  set_long("A manifestation of pure evil, the massive Black Dragon seems\n" +
	   "to radiate pure hatred and wickedness. Its piercing yellow\n" +
	   "eyes stare at you unblinking, its forked tongue flicking\n" +
	   "sinisterly in and out of its wide, tooth-lined mouth. It\n" +
	   "lashes its sharp tail expectantly.\n");
  set_race("dragon");
  set_level(50);
  set_al(-10000);
  set_wc(50);
  set_ac(50);
  set_aggressive(1);
  set_prevent_poison(1);
  set_chance(20);
  set_spell_mess1("A bright bolt of lightning forks from the dragon's mouth!");
  set_spell_mess2("The dragon spits a bolt of lightning at you!");
  set_spell_dam(100);
  set_dead_ob(clone_object(NWFORESTA + "objects/dragoncorpse"));
  add_money(10000);
  load_a_chat(50, ({
    "The dragon roars with fury.\n",
    "The dragon's tail lashes out at you!\n",
    "Claws and fangs tear and bite mercilessly.\n",
    "The Black Dragon screams: You shall die, Mortal!\n"
  }));
  set_heart_beat(1);
}

heart_beat() {
  if(set_light(0) > 0) {
//    set_aggressive(1);
    load_chat(10, ({
      "The Dragon says: Attack me if you dare, tiny one.\n",
      "The Dragon growls: Leave this place now!\n",
      "The Black Dragon eyes you hungrily.\n"
    }));
  }
  else {
/*
    set_aggressive(0);
    if(attacker_ob) attacker_ob->stop_fight();
    stop_fight();
*/
    load_chat(10, ({
      "From the darkness, something hisses: Come, my child. Come to me.\n",
      "You hear something hissing sinisterly in the darkness.\n",
    }));
  }
  ::heart_beat();
}
