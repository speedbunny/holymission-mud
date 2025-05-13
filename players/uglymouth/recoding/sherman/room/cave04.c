#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  clone_list = ({ 
    1, 6, "elf zombie", "/obj/monster", ({
      "set_name", "elf zombie",
      "set_alias", "zombie"
      "set_short", "An undead zombie of an elf",
      "set_long", "The awful sight of this corrupted elven undead makes "
        + "you stomach turn. This semi-decayed animated corpse is dressed "
        + "in what used to be mage clothes.\n",
      "set_level", 20,
      "set_ac", 10,
      "set_race", "undead",
      "set_aggressive", 1,
      "set_al", -150,
      "set_chance", 20,
      "set_spell_mess1", 
        "Elf zombie fires a lightning bolt from its rotting finger tips.\n",
      "set_spell_mess2",
        "Elf zombie strikes you with a lightning bolt!\n",
      "set_spell_dam", 30,
      "add_money", 100 + random( 100 ),
    }),
  });

  set_light( -1 );
  short_desc = "In a very dark cave under a dark hill";
  long_desc = "You are walking down a very dark cave in a dark hill. "
    + "It looks like this is a natural cave, eroded into the hard rock "
    + "a long time ago. The cave continues southwest and west.\n";
  dest_dir = ({
    ROOM_DIR + "cave03", "southwest",
    ROOM_DIR + "cave05", "west",
  });
  items=({ 
    "cave", "Just a natural cave. It's fairly dry",
    "hill", "It's oppressing presence is all around you",
    "rock", "Dark grey, hard rock",
  });
  smell = "The rotting smell of decay makes you feel noxious.\n";
  ::reset( arg );
  replace_program( "room/room" );
}
