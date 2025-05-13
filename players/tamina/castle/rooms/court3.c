/*  This is the Courtyard  */

#include "/players/tamina/defs.h"

inherit "room/room";
object sentinel;

void reset(int arg) {

   if(!sentinel) {
   sentinel=CLO(CMONS + "sentinel");
   transfer(sentinel,TO);
   }
   if (arg) return ;

      	set_light(1);
	short_desc = "Courtyard of Camelot ";
	long_desc = 
"You are standing in the courtyard of the renowned castle Camelot, \n"+ 
"which looks distinctly odd from what you have heard of the legends.\n"+ 
"This waste-like ground is covered in weeds, with dull-grey walls\n"+ 
"staring at you from either side of the courtyard.  You do not feel \n"+ 
"entirely safe here...\n"; 

	dest_dir = ({
          CROOMS + "reception","north",
          CROOMS + "court2","south",
          CROOMS + "ecourt3","east",
          CROOMS + "wcourt3","west",
     });

	items = ({
  "weeds",
"Not very pleasant plants at all",
  "walls",
"The walls do not look very warming, and do not suggest anything to "+
"you about what Camelot was supposed to look like",
  "courtyard",
"This is a wide, open space of barren ground that looks as though "+
"it has not been kept in good condition for quite some time now",
     });

}
