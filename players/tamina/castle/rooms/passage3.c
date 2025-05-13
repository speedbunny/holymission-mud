/*Secret Passage*/

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg){

     set_light(-2);
     short_desc = "Secret Passage";
     long_desc = 
"You manage to get past the Shadow Demon, and continue along the passage.\n"+ 
"You see that the corridor is very dark here, darker than anywhere you have\n"+ 
"been before. The passage twists ahead of you here.\n";

     dest_dir = ({
   CROOMS + "passage2","southwest",
   CROOMS + "passage4","east",
     });

    ::reset (arg);

    RPR("room/room");
}

