/*  This is the first Earth Room  */

inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if (arg) return 0;

      	set_light(-1);
	short_desc = "Elemental Plane of Earth";
	long_desc = 
"You have just entered the "+short_desc+".\n"+
"There is very little light that you can see here, as you appear to be\n"+
"underground.  The feeling of immense weight pushing down on you is \n"+
"almost over-powering.  You are also finding it very difficult to\n"+
"breathe, and are quite glad that you managed to find some protection\n"+
"for yourself before you dared venture here...\n";

	dest_dir = ({
          EARTH + "rm2","down",     
	 });

	property = ({"no_teleport"});

	smell = "Very musty, and soily, and very earthy!";

  ::reset(arg);
  RPR("room/room");
}
