inherit "room/room";

#include "/players/tamina/defs.h"

object boar, tusk;

void reset(int arg) 
{
  boar = present("boar");
  if (!boar) 
  {
    boar = clone_object("obj/monster");

    boar->set_name("war boar");
    boar->set_race("boar");
    boar->set_long(
  "This is a huge wild pig.  Its sharp tusks and thick hide help protect it.\n"+
  "The intelligence it has suggests it has been trained.\n");
    boar->set_level(18);
    boar->set_wc(16);
    boar->set_ac(7);
    boar->set_aggressive(1);

      tusk = clone_object("obj/weapon");

    tusk->set_name("tusk");
    tusk->set_short("Wild Boar's Tusk");
    tusk->set_long("A very sharp tusk which once belonged to boar.\n");
    tusk->set_weight(2);
    tusk->set_value(300);
    tusk->set_class(14);

    TR(tusk, boar); 
    move_object(boar, this_object());
  }
  if (arg) return 0;

  set_light(1);
  short_desc = "Dread Forest";
  long_desc =
"The undergrowth here has been rooted up and trampled.\n"+
"Gouge marks as if from large tusks score the ground\n"+
"and hoofprints can be seen in the softer soil.\n"+
"To the east, you see a large cliff wall barring any passage.\n";

    dest_dir = ({
    TFOREST + "rmW", "north",
    TFOREST + "rmK", "south",
    TFOREST + "rmP", "west",
    });
}

