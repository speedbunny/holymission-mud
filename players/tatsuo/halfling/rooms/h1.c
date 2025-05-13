#include "/players/tatsuo/def.h"
inherit "room/room";


void reset(int arg)

  if(arg) return;
   if(!present("halfling")){ MO(CO(HMON+"halfling"),TO); } 
  ::reset(arg);
  set_property("has_fire");
  long_desc = "A fire lights up the warm and cheery looking house dug out "+
              "from under the small hill.  All the trappings of comfort and "+
              "family are abundant.  A portrait hangs over the fireplace.\n";

  short_desc = "In a comfortable hobbit hole";
  set_light(1);
  
  dest_dir = ({ HPATH+"p5","southwest" });

  items = ({ "portrait","It is a painting of two halflings. The name under "+
             "the portrait reads Yambu & Tritness.\n" });

   replace_program("room/room");
}


