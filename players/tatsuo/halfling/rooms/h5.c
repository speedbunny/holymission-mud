#include "/players/tatsuo/def.h"
inherit "room/room";


void reset(int arg)
 if(!present("halfling")){ MO(CO(HMON+"halfling"),TO); 
                       /*  MO(CO(HMON+"halfling"),TO); */ 
                         MO(CO(HMON+"child"),TO); 
                         MO(CO(HMON+"child"),TO);
                         MO(CO(HMON+"child"),TO); 
                         MO(CO(HMON+"child"),TO);
                         MO(CO(HMON+"child"),TO); 
                         MO(CO(HMON+"child"),TO); }
  if(arg) return;
   
  ::reset(arg);
  set_property("has_fire");
  long_desc = "A fire lights up the warm and cheery looking house dug out "+
              "from under the small hill.  All the trappings of comfort and "+
              "family are abundant.  \n";

  short_desc = "In a comfortable hobbit hole";
  set_light(1);
  
  dest_dir = ({ HPATH+"p6","northwest" });

 
   replace_program("room/room");
}


