inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
  if (arg) return 0;

    property = ({ "has_earth", "no_teleport" });
    smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(1);
	short_desc = "In a tunnel";
	long_desc = 
"    You can feel immense waves of heat wash over you now.\n"+
"    Bright, flickering red lights reflect painfully off the shining\n"+
"    walls, the source being from further down this passage...\n"+
"    @@chk_dwarf@@";

     	dest_dir = ({
      EARTH + "rm23", "southeast",
      EARTH + "rm21", "west",
	});

	items = ({
  "lights",
"They seem to be from some sort of fire..",
      });

}

string chk_dwarf()
{
  if (TP->query_race() == "dwarf")
    return "Because of your dwarven blood, you think that the heat source\n"+
           "    to the southeast is some sort of forge...\n";
  else
    return "";
}
