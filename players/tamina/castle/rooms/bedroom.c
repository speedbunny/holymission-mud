/*  This is the Bedroom */

inherit "room/room";
#include "/players/tamina/defs.h"

object ob;

void reset (int arg) 
{
   ob = present("darkling");
   if ((!ob) || !living(ob))
     MO(CLO(DARK + "prince"), TO);

   if (arg) return 0;

      	set_light(0);
	short_desc = "Grand Bedroom ";
	long_desc = 
"This appears to have been the magnificent Bedroom of the\n"+ 
"King of Camelot.  There is a worn, four-poster-bed standing\n"+
"against the back wall, and a large painting hanging on the west\n"+
"wall.  To your east is another exit.\n";

	dest_dir = ({
    CROOMS + "junction","south",
    CROOMS + "bathroom","east",
     });

	items = ({
  "bed",
"This would have looked splendid when it was in good shape.  "+
"But now is in rather a sorry state, to say the least",
  "painting",
"This is of a beautiful, exuberant young woman sitting astride a "+
"white palfrey.  The wind is gusting through her long, golden hair. "+
"She is wearing a small circlet on her brow, as she looks into "+
"the far distance...  Surprisingly, this portrait is in very good "+
"condition, compared to everything else in Camelot...",
     });

}
