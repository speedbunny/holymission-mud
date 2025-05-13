#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg){

     set_light(-2);
     short_desc = "Junction ";
     long_desc = 
   "You take the passage leading off from the Throne Room.\n"+ 
   "The darkness, you would swear, is getting thicker...so much so\n"+
   "that you can almost touch it...\n";

     dest_dir = ({
   CROOMS + "throne_room","west",
   CROOMS + "bedroom","north",
   CROOMS + "p_1","east",
     });

    ::reset (arg);

    RPR("room/room");
}

