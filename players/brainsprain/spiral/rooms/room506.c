inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

int found;
int search (string arg){
     object bottle;
     int w;
     if(arg != "alcove") {
          return 0;
     }
     if (arg == "alcove") {
          if(!found) {
               write("You find a bottle in the alcove.\n");
               say(capitalize(this_player()->query_name())+" finds a bottle.\n");
               bottle=clone_object(si+"/bottle");
               transfer(bottle,this_player());
               found=1;
               return 1;
          }
          if(found){
               write("You search the alcove, but find nothing.\n");
               return 1;
          }
     }
}

void reset(int arg){
     short_desc = "A dark room";
     long_desc =
     "This room is absolutely bare with the exception of a set of shackles along the eastern "+
    "wall.  Along the western wall there is an alcove.  Rusted metal bars hang from the ceiling "+
    "and terminate at about head level.  A musty odor lingers in the air.\n";
     set_light(0);
     dest_dir = ({
       sr+"/room507","northwest",
       sr+"/room505","south",
     });
     items = ({
       "bars",
       "One inch thick metal bars",
       "alcove",
       "A small hole in the wall",
       "shackles",
       "A set of sturdy shackles bolted to the wall",
     });
}

void init(){
     ::init();
     add_action("search","search");
}
