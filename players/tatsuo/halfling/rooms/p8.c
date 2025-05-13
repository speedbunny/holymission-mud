inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg) {




     if(arg) return;
          ::reset(arg);


          long_desc = "A the cobblestone path ends at the gate, just to the north, ",
                      "giving way to a narrow dirt path heading south into a "+
                      "dark forest, full of rather twisted trees growing around "+
                      "large boulders.\n";

          short_desc = "In a dark wood outside the halfling village";
 
  set_light(1);
  
  dest_dir = ({ HPATH+"p9","south", HPATH+"p7","north",
              
                });

  items = ({ "path","Not important",
             "forest","Just go south and see for yourself",
             "trees","Again not important",
             "boulders","not important" });
 

   replace_program("room/room");
}





