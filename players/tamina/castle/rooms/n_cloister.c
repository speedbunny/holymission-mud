/*  This is the North Pathway  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(1);
	short_desc = "North Path-way ";
	long_desc = 
"You are walking along the path-way that is situated at the north side\n"+
"of the Quadrangle.  Above you is a wooden cloister, sheltering the length\n"+ 
"of the path itself.  Hanging limply from the oak structure are withered\n"+ 
"strands of unattended climbing ivy.\n";

	dest_dir = ({
          CROOMS + "n_junction","north",
          CROOMS + "quad","south",
          CROOMS + "ne_corner","east",
          CROOMS + "nw_corner","west",
        });

	items = ({
  "cloister",
"This is a structure of well-crafted logs standing high above the "+
"path-way.  Entwined in the wood are a few strands of ivy",
  "ivy",
"Strands of brown-green climbing-ivy that have withered and almost "+
"died due to negligence",
     });

    ::reset (arg);

    RPR("room/room");
}
