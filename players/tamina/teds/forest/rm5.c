inherit "room/room";

#include "/players/tamina/defs.h"

object roc;

void reset(int arg) 
{
  roc = present("roc");
  if (!roc) 
  {
    roc = clone_object("obj/monster");

    roc->set_name("roc");
    roc->set_race("bird");
    roc->set_long(
  "This fey creature has the uppper body of a man, and the legs\n"+
  "of a goat.  It is very mischeivous, and not very easy to kill.\n");
    roc->set_level(23);
    roc->set_wc(26);
    roc->set_ac(12);
    roc->set_al(-200);
    roc->set_aggressive(0);

    "players/tamina/teds/random_treasure"->make_item(roc, 23);
    move_object(roc, this_object());
  }
  if (arg) return 0;
  set_light(1);
  short_desc = "Petrified Forest";
  long_desc =
"You are wandering through the edges of the Petrified Forest.\n"+
"The trees are thinning out here, and you can see the sky above\n"+
"you again.  Bird call can be heard far off.\n";

    dest_dir = ({
    TFOREST + "rm8", "north",
    TFOREST + "rm1", "south",
    TFOREST + "rm6", "east",
    });
}
