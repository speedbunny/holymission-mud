
inherit "room/room";
#include "dragon.c"

reset(arg){        
  if(arg) return;
  set_light(1);

  short_desc = "A deep thick forest";

  long_desc = BS(" HI \n");

  dest_dir = ({
        "players/apollo/area2/rooms/forest25", "north",
        "players/apollo/area2/rooms/forest26", "northeast",
           }); 

}





