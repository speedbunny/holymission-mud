inherit "room/room";

#include "/players/tamina/defs.h"

object dragon;

void reset(int arg) 
{
  if (!arg) 
  {
    set_light(0);
    short_desc = "Hot Volcanic Cave";
    long_desc =
	"A large pool of molten lava froths and bubbles in\n"+
	"one corner of this cave.\n";

    dest_dir = ({
	  THOT + "red_drag","west"
	});

    items = ({
	  "lava","A pool of molten lava, you can feel the heat from here",
	  "pool","A pool of molten lava, you can feel the heat from here"
	});
    }
    dragon = clone_object("obj/monster");

    dragon->set_name("earth dragon");
    dragon->set_alias("dragon");
    dragon->set_long("A fierce, Earth Dragon.\n");
    dragon->set_level(23);
    dragon->set_wc(30);
    dragon->set_ac(9);
    dragon->set_al(-900);
    dragon->set_aggressive(1);
    dragon->set_spell_mess1("The Earth Dragon spits molten lava !!\n");
    dragon->set_spell_mess2("The Earth Dragon burns you with molten lava !!\n");
    dragon->set_chance(50);
    dragon->set_spell_dam(42);

    call_other("players/tamina/teds/random_magic","make_item", dragon, 23);
    call_other("players/tamina/teds/random_treasure","make_item", dragon, 23);
    move_object(dragon, this_object());
}
