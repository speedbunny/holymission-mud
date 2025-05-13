inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg) {




  if(arg) return;
          
         ::reset(arg);

          long_desc = " The dirt path runs north and south here.  Any attempts "+
                      "at deviation from the path seem hopeless.  The trees crowd "+
                      "you as you walk.\n";
          short_desc = "In a dark wood outside the halfling village";
 
  set_light(1);
  
  dest_dir = ({ HPATH+"p8","north", HPATH+"p10","south"
               
                });

  items = ({ "path","Not important",
             "forest","Just go south and see for yourself",
             "trees","Again not important",
             "boulders","not important" });
 

   replace_program("room/room");
}





