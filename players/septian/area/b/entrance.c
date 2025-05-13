//     Coded by Septian@Holy Mission     //
//              May 1997                 //

inherit "room/room";
#include "/players/septian/defs.h"

void reset (int arg)  {
    if (!arg)  {

	set_light(1);

	short_desc = "Inside a strange ruin";

	long_desc =
	"A long stream of light from a crack in the wall illuminates\n" +
	"the room. As the dust settles, you can see that the room is\n" +
	"mostly empty except for the huge spiral stairway leading to\n" +
	"an opening in the floor. Various writing are on the wall in\n" +
	"here and a doorframe exits northerly.\n";

	dest_dir = ({
	  ROOM + "room1","north",
	  ROOM + "stairway","stairs"
	});

	hidden_dir = ({
	  ROOM + "ruin","crack"
	});

