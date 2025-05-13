inherit "room/room";

#include "/players/tamina/defs.h"

object wiz;

void reset(int arg) 
{
    ::reset(arg);
    if (arg) return 0;

    set_light(1);
    short_desc = "Petrified Forest";
    long_desc =
"You enter the dreaded Petrified Forest.\n"+
"Darkness surrounds you, and paths lead in all directions,\n"+
"deeper into the forest.\n";

    dest_dir = ({
    TFOREST + "rmY", "north",
    TFOREST + "rmN", "south",
    TFOREST + "rmU", "east",
    TFOREST + "rmS", "west",
    });

  wiz = present("goblin wizard");
  if (!wiz)
  {
    wiz = CLO ("obj/monster");

    wiz->set_name("goblin wizard");
    wiz->set_alias("wizard");
    wiz->set_race("goblin");
    wiz->set_short("Goblin Wizard");
    wiz->set_long(
  "This looks like a small, squat, perverted wizard, whose experiments\n"+
  "have gone drastically wrong...\n");
    wiz->set_level(23);
    wiz->set_wc(19);
    wiz->set_ac(13);
    wiz->set_aggressive(1);
    wiz->set_spell_mess1("The Goblin Wizards casts one of his spells.\n");
    wiz->set_spell_mess2("The Goblin Wizard casts a foul spell at you !!\n");
    wiz->set_spell_dam(25);
    wiz->set_chance(23);

    "/players/tamina/teds/random_magic"->make_item(wiz, 23);
    "/players/tamina/teds/random_magic"->make_item(wiz, 23);
    move_object(wiz, this_object());
  }
}
