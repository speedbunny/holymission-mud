/*  This is the exit in the East Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "East Wing exit (w,s)";
	long_desc = 
"From here, you can see that the western exit leads out onto a brightly\n"+ 
"lit open quadrangle.  Cold draughts of wind bluster around the open area\n"+
"of grass, blowing browned leaves across the cloistered paths, and in\n"+
"through the exit here, mixing with the dust on the floor.\n";

	dest_dir = ({
          CROOMS + "se_corner","west",
          CROOMS + "ewing9","south",
        });

	items = ({
  "quadrangle",
"This is a large square-shaped area of green grass, flanked on all four "+
"sides by a cloistered pathway.  In the distant western part, you can "+
"see a walled-garden of some sort",
  "leaves",
"You see well-browned leaves that have fallen from trees in the Autumn "+
"season",
     });
  
    ::reset (arg);

    RPR("room/room");
}
