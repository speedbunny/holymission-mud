inherit "room/room";

#include "/players/tamina/defs.h"

object chimera;

void reset(int arg) 
{
  chimera = present("chimera");
  if (!chimera)
  {
    chimera = clone_object("obj/monster");

    chimera->set_name("chimera");
    chimera->set_race("chimera");
    chimera->set_long("This huge monster has three heads:\n"+
		      "  one of a goat, a lion, and a snake !!\n");
    chimera->set_level(21);
    chimera->set_wc(24);
    chimera->set_ac(7);
    chimera->set_aggressive(1);
    chimera->set_spell_mess1("The Chimera burns you with its fire.\n");
    chimera->set_spell_mess2("The Chimera breathes fire !!\n");
    chimera->set_spell_dam(30 + random(15));
    chimera->set_chance(20);

    "/players/tamina/teds/random_treasure"->make_item(chimera, 21);
    "/players/tamina/teds/random_magic"->make_item(chimera, 21);
    move_object(chimera, this_object());
  }
  if(arg) return 0;

  set_light(1);
  short_desc = "Petrified Forest";
  long_desc =
"Large burn marks stain the trees and grass here. One\n"+
"area has been used as a dirt bath. The smell reminds\n"+
"you of burnt sewage.\n";

    dest_dir = ({
    TFOREST + "rmE", "north",
    });
}
