#include "/players/tatsuo/def.h"
inherit "room/room";


void reset(int arg){
  if(!present("umber hulk")){
    MO(CO(KMON+"umber_hulk"),TO);
  }

  if(arg) return;
  ::reset(arg);

  set_light(0);

  short_desc ="The end of the tunnel.";
 
  long_desc ="   The passageway ends abrubtly here. The walls are covered\n"
             "in what looks and smells like a green acid.  It looks like\n"
             "what was making its way through the rock was here recently.\n";


  items= ({
    "acid","Looks like someone threw up",     
    "green acid","Looks like someone threw up, smell that way too",
    "walls","They are covered in a green acidic substance",
    "passageway","The passage ends here, you must turn back",
    "rock","It seems almost 'eaten'",
    "debris","Just a collection of smashed rock"
  });

  dest_dir=({
        KPATH+"u3","south"
   });


replace_program("room/room");
}

