inherit "/room/room";

#include "/room/room_defs.h"

int weapon_hit(object attacker);

void reset(int arg) {
  set_light(1);
  short_desc="The orc treasury";
  long_desc=
    "You are in the orc treasury. It is normally heavily guarded.\n";

  dest_dir=({
    ORC_VALLEY + "fortress", "south",
  });

  items=({
    "treasury", "Maybe there's still some treasure around",
  });

  clone_list = ({
    1, 1, "orc shaman", "obj/monster", ({
      "set_name", "shaman",
      "set_alias", "orc shaman",
      "set_race", "orc",
      "set_level", 10,
      "set_size", 3,
      "set_al", -300,
      "set_short", "An orc shaman",
      "set_wc", 10,
      "set_ac", 1,
      "set_aggressive", 1,
      "set_chance", 20,
      "set_spell_mess1", "You are hit by a magic missile.",
      "set_spell_mess2", "The shaman casts a magic missile.",
      "set_spell_dam", 20,
    }),
    -1, 1, "stick", "obj/staff", 0,
    -1, 1, "sword", "obj/weapon", ({
      "set_name", "sword",
      "set_short", "Short sword",
#if 0
// There is no set_alias_list() fun in weapon.c! Sauron.
      "set_alias_list", ({ "sword", "orc slayer", "blade" }),
#else
      "set_alias", "orc slayer",
      "set_alt_name", "blade",
#endif
      "set_long", "This is a very fine blade " +
        "covered with ancient runes. " + 
        "Engraved on it is a picture of the " +
        "sword slicing an orc.\n",
      "set_read", "The only thing you can read is " +
        "the word 'orc'.\n",
      "set_class", 9,
      "set_weight", 2,
      "set_value", 200,
      "set_hit_func", this_object(),
    }),
  });

  ::reset(arg);
  replace_program("room/room");
}

int weapon_hit(object attacker) {
  if(attacker->query_race() == "orc") {
    write("The orc slayer glows in a cold blue light.\n");
    return 10;
  }
  return 0;
}
