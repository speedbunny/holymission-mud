inherit "/obj/monster";

#include "/players/matt/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mist dragon");
  set_short("Mist Dragon");
  set_long("The nature of this beast is such that you cannot focus on\n" +
	   "it properly; however, you can barely make out a massive\n" +
	   "serpentine form slithering lithely through the mist here.\n");
  set_race("dragon");
  set_level(30);
  set_hp(1000);
  set_wc(20);
  set_ac(20);
  set_al(-500);
  set_chance(10);
  set_spell_mess1("The Mist Dragon sprays forth a cloud of cold mist!\n");
  set_spell_mess2("You are sprayed by a cloud of cold white mist!\n");
  set_spell_dam(50);  
  set_dead_ob(TO);
  load_chat(10, ({
    "The misty form hisses softly.\n",
    "The mist moves and shifts all around you.\n"
  }));
  load_a_chat(20, ({
    "The dragon fades into the mist.\n",
    "You cannot see the dragon clearly.\n"
  }));
}

monster_died() {
  destruct(TO);
  return 1;
}

hit_player(arg) {
  object att;
  if(!random(10)) {
    att = TO->query_attack();
    TELL(att, "Your attack goes right through the dragon's body!\n");
    say(att->NAME + "'s attack passes through the dragon's body!\n", att);
    return;
  }
  return ::hit_player(arg);
}
