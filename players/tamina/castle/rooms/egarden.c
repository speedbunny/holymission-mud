/*  This is the East Walled Garden  */

#include "/players/tamina/defs.h"

inherit "room/room";
object vine;

void reset(int arg) {

  if (arg) return ;

      	set_light(1);
	short_desc = "East Walled Garden ";
	long_desc = 
"You pass into the walled garden past the east path-way of the Quadrangle.\n"+ 
"The first thing that catches your eye, is a large birch trellis attached\n"+
"to the stone wall, with vines crawling up the wooden framework.  At\n"+
"occasional points, old honeysuckle can be seen trying to poke their way \n"+
"through the forest of vines.  Around the trellis are climbing ivy, and \n"+
"delphinium, dancing a peculiar waltz together, with tall green grass\n"+
"waving in time to their beat, with the light breeze that manages to find\n"+
"its way into the sheltered area.  Mixed in the grass are trails of bindweed\n"+
"and ground elder.  But, despite its obvious poor state, you can imagine \n"+
"that this place would be very calming and idyllic if it were restored\n"+
"to its former glory.\n";

	dest_dir = ({
          CROOMS + "e_cloister","west",
        });

	items = ({
  "trellis",
"A large wooden framework, made of birch, attached to the length of "+
"the stone wall",
  "vine",
"A large plant with perhaps a few remaining white grapes still "+
"to be picked",
  "honeysuckle",
"A creamy-white coloured flower, reminiscent of Camelot's previous "+
"beauty",
     });

  vine=CLO(COBJ + "vine");
  MO(vine,TO);
}
