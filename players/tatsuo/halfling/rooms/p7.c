inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg) {
 
   if(!present("guard")){ MO(CO(HMON+"guard"),TO); 
                         MO(CO(HMON+"guard"),TO); 
                         MO(CO(HMON+"guard"),TO); 
                         MO(CO(HMON+"guard"),TO); }


  if(arg) return;

           ::reset(arg);  
           long_desc =   "There appears to be less activity here in the southern "+
                      "part of the village.  One lonely hobbit hole graces the "+
                      "eastern hill.  The cobblestone path runs right up to a stone "+
                      "wall erected on the southern border of the village.  A small "+
                      "wooden gate stands sentry in the middle of the wall.\n"
        short_desc = "In the halfling village";
 
  set_light(1);
  
  dest_dir = ({ HPATH+"p8","south", HPATH+"p6","north",
                HPATH+"h6", "east"
                });

  items = ({ ({"holes","Hobbit holes","hobbit holes"}),
             "They lie in all directions to the east",
             "street","Filled with small stuff, ya know, for halflings",
             "town","A quaint halfling village",
             "river","There appears to be a bridge spanning it",
             "wall","Obviously there to keep something out",
             "gate","It has been broken and stands open"          });



   replace_program("room/room");
}





