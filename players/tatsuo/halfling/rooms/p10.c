inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg) {


   if(arg) return;
          
          ::reset(arg);

          long_desc = "The dirt path comes to a dead end in front of a huge "+
                      "rock cleft rising from the forest floor.  A cave stands "+
                      "dark and forboding at the end of the path.\n";
 
          short_desc = "In a dark wood outside the halfling village";
 
  set_light(1);
  
  dest_dir = ({ HPATH+"p9","north", KPATH+"k1","enter"
               
                });

  items = ({ "path","Not important",
             "forest","It surrounds you",
             "cave","just 'enter' the cave",
             "trees","Again not important",
             "boulders","not important" });
 

   replace_program("room/room");
}






