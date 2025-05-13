/*  This is the Courtyard  */

#include "/players/tamina/defs.h"

inherit "room/room";

void reset(int arg) 
{
   if (arg) return ;

      	set_light(1);
	short_desc = "Courtyard of Camelot";
	long_desc = 
"You are standing in the middle of the courtyard of the great castle,\n"+ 
"Camelot.  Here the cold sunshine falls down onto a weeded, grassy\n"+
"plain, with the wind blowing tumble-weeds across in front of you.\n"+
"There is nothing to see in this barren place, except the darkened\n"+
"interiors of the castle all around you, and a rather old looking well.\n"+
"Far ahead, you can see a passage leading into Camelot itself.\n";

	dest_dir = ({
          CROOMS + "courtyard","south",
          CROOMS + "court3","north",
          CROOMS + "ecourt2","east",
          CROOMS + "wcourt2","west",
     });

	items = ({
  "weeds",
"Not very pleasant plants at all",
  "rope",
"Perhaps you could give it a pull, or even maybe lower it",
  "bucket",
"A large, iron bucket attached to the rope of the well, filled with "+
"filthy looking water.  You are surprised to think that people had to "+
"drink from this",
     });
        
	clone_list = 
    ({ 1, 1, "well", "/players/tamina/castle/obj/well", 0});

	::reset(arg);

 	RPR("room/room");
}
