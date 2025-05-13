/*  This is the West Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "West wing ";
	long_desc = 
"The corridor here branches so as to allow you to enter into a \n"+
"Bedchamber of sorts, or continue onward, or return back into the \n"+
"Castle itself.\n"+
"Ahead of you, you can see more shafts of light filter through the \n"
"gloom.\n";

	dest_dir = ({
          CROOMS + "wwing5","north",
          CROOMS + "wwing3","east",
          CROOMS + "wbed1","west",
         });

    ::reset (arg);

    RPR("room/room");
}
