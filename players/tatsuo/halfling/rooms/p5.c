inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg) {
  
  if(!present("guard")){ MO(CO(HMON+"guard"),TO); }
  if(!present("halfling")){ MO(CO(HMON+"halfling"),TO); 
                         MO(CO(HMON+"halfling"),TO); 
                         MO(CO(HMON+"halfling"),TO); 
                         MO(CO(HMON+"halfling"),TO); 
                         MO(CO(HMON+"halfling"),TO); }
  if(!present("child")){
                         MO(CO(HMON+"farmer"),TO);  
                         MO(CO(HMON+"child"),TO); 
                         MO(CO(HMON+"child"),TO);  }
                        
  if(arg) return;

    ::reset(arg);  

        long_desc = "The path opens up onto a busy little street.  You "+
                    "note signs of activity all about you, and a series "+
                    "of small holes lead into some of the hills to the "+
                    "east.  They appear to be Hobbit holes.  The village "+
                    "extends to the south along the river.\n";
        short_desc = "On the path to the Halfling village";
 
  set_light(1);
  
  dest_dir = ({ HPATH+"p6","south", HPATH+"p4","north",
                HPATH+"h1","northeast", HPATH+"h2", "east" });

  items = ({ ({"holes","Hobbit holes","hobbit holes"}),
             "There is one to the northeast and one to the east",
             "street","Filled with small stuff, ya know, for halflings",
             "village","A quaint halfling village",
             "river","There appears to be a bridge a little further south"
          });



   replace_program("room/room");
}



