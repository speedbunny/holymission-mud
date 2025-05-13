/*  This is the North-West Corner of the quad  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(1);
	short_desc = "North West Corner ";
	long_desc = 
"From where you are, you can see that you stand in the north-west corner\n"+
"of a large Quadrangle in the rear part of Camelot.  This is a large square\n"+ 
"of grass, enclosed by four cloistered path-ways\n";

	dest_dir = ({
          CROOMS + "w_cloister","south",
          CROOMS + "n_cloister","east",
        });

	items = ({
  "quadrangle",
"This is a square-shaped plot of land, grassed over.  However, now the "+
"grass has been left to grow long, and weeds infest the area",
  "cloister",
"This is a wooden structure erected to shelter the path-ways surrounding "+
"the Quadrangle",
  "path-way",
"There are four path-ways at the four cardinal points of a compass, "+
"enclosing the Quadrangle",
  "path-ways",
"There are four path-ways at the four cardinal points of a compass, "+
"enclosing the Quadrangle",
     });

    ::reset (arg);

    RPR("room/room");
}
