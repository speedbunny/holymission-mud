inherit "/room/room";
#include "../full.h"
#include "items.h"

reset(arg){
 if (!arg){
 clone_list=({1,1,"wasp","/players/goldsun/sherwood/monster/kilwasp",0});
 set_light(0);
 short_desc=("Sherwood");
 long_desc=
("You are in the Sherwood forest. Whole surroundings is overgrown with\n"
+"dense bushes and huge trees. You cannot see anything else because\n"
+"the forest is dark.\n");

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood26", "south",
           "/players/goldsun/sherwood/room/shwood31", "west",
           "/players/goldsun/sherwood/room/shwood24", "north",
           "/players/goldsun/sherwood/room/shwood23", "east"});
        
 items=({"grass","The grass is waving in the wind"})+ITEMS;
 }
 ::reset();
}

init(){
 ::init();
add_action("climb","climb");
add_action("shake","shake");
add_action("pass","pass");
add_action("tear","tear");
add_action("dig","dig");
add_action("light","light");
add_action("listen","listen");
add_action("cut","cut");
add_action("cut","chop");
}

