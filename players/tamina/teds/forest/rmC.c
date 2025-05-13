inherit "room/room";

#include "/players/tamina/defs.h"

object gargoyle;

void reset(int arg) 
{
  ::reset(arg);
  gargoyle = present("gargoyle");
  if (!gargoyle)
  {
    gargoyle = clone_object("obj/monster");
   
    gargoyle->set_name("gargoyle");
    gargoyle->set_race("gargoyle");
    gargoyle->set_long(
  "This is a large, hideous monster, with the ugliest face you have\n"+
  "ever seen !\n");
    gargoyle->set_level(20);
    gargoyle->set_gender(1);
    gargoyle->set_wc(15);
    gargoyle->set_ac(10);
    gargoyle->set_al(-50);
    gargoyle->set_aggressive(1);
    gargoyle->add_money(50 + random(51));

    "/players/tamina/teds/random_armor"->make_item(gargoyle, 20);
    "/players/tamina/teds/random_treasure"->make_item(gargoyle, 17);
    move_object(gargoyle, this_object());
  }
  if (arg) return 0;

    set_light(1);
    short_desc = "Petrified Forest";
    long_desc =
"You continue deeper into the dreaded Petrified Forest.\n"+
"A larger clearing surrounds here, where the trees have been\n"+
"clawed, and shredded.\n";

    dest_dir = ({
      TFOREST + "rmH", "north",
      TFOREST + "rmD", "east"
    });

    items = ({
  "trees",
"They seem to have been partially eaten by some monster..",
    });

}
