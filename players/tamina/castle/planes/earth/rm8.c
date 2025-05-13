/*  room 8  */

inherit "/room/room";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  if (arg) return 0;

      property = ({ "has_earth", "no_teleport" });
      smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(0);
	short_desc = "2nd level Underground";
	long_desc = 
"    This is the tunnel of the cave underground.\n"+
"    The roughly hewn walls come to a dead end here in front of you.\n"+
"    It would seem that by the amount of rubble and chipped rock from\n"+
"    the walls that the tunnel here was left deserted, and never \n"+
"    completed.\n";

     	dest_dir = ({
      EARTH + "rm7", "south",
	});

	items = ({
  "rubble",
"You see that it has come from the walls of the tunnel.  You do notice "+
"about them that they are not of the same method of carving, or caving "+
"that you are familiar with..",
  "chipped rock",
"You see that it has come from the walls of the tunnel.  You do notice "+
"about them that they are not of the same method of carving, or caving "+
"that you are familiar with..",
  "rock",
"You see that it has come from the walls of the tunnel.  You do notice "+
"about them that they are not of the same method of carving, or caving "+
"that you are familiar with.  The rock is of the same strange quality "+
"that you started to notice on the upper level",
  "walls",
"They seem to have been semi-caved here, as if the caving were stopped "+
"unexpectedly..",
      });

    ::reset(arg);
    RPR("/room/room");

}
