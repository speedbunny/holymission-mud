/*  This is the East Pathway  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(1);
	short_desc = "East Path-Way ";
	long_desc = 
"You are walking along the path-way that is situated at the east side\n"+
"of the Quadrangle.  Above you is a wooden cloister, sheltering the length\n"+ 
"of the path itself.  Hanging limply from the oak structure are withered\n"+ 
"strands of unattended climbing ivy.\n";

	dest_dir = ({
          CROOMS + "ne_corner","north",
          CROOMS + "se_corner","south",
          CROOMS + "egarden","east",
          CROOMS + "quad","west",
        });

	items = ({
  "cloister",
"This is a structure of well-crafted logs standing high above the "+
"path-way.  Entwined in the wood are a few strands of ivy",
  "ivy",
"Strands of brown-green climbing-ivy that have withered and almost "+
"died due to negligence",
     });

    ::reset(arg);

    RPR("room/room");
}
