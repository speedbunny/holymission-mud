/*  This is the West corridor  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(-1);
	short_desc = "West corridor ";
	long_desc = 
"The foul stench that you first encountered before is getting distinctly\n"+
"stronger as you head north.  It smells like burnt (or burning) meat.\n"+
"The faint wind that wafts through the corridor here brings with it a\n"+
"mild, disturbing heat in this decidedly drafty castle.\n";

	dest_dir = ({
          CROOMS + "wcorridor2","north",
          CROOMS + "wcorridor","south",
       });

    ::reset (arg);

    RPR("room/room");
}
