inherit "room/room";

#include "/room/orc/orc.h"

int north() {
     if(present("orc",this_object())) {
          write("An orc bars your way.\n");
        return 1;
     }
     return ::move("north");
}

reset(arg) {

  if(arg) return;
  short_desc="The orc fortress";
  long_desc="This is the local strong point of the orcs.  This is a large " +
            "fortress covered in blood and guts.  The walls are made from "+
            "bones of past victims.  The bones are stained red "+
            "with blood.  There is an entrance " +
            "to a small room made from discarded body parts to the north. " +
            "Orc valley is to the south of here.\n";
  set_light(1);
  items=({
            "fortress","Strong point of the orcs",
            "blood","Covering the walls",
            "guts","Covering the walls",
            "parts", "Discarded body parts",
            "valley", "Orc Valley",
            "point", "It seems this place could flood with orcs",
            "room", "It looks very important",
            "walls", "Made from bones",
            "bones", "Stained with blood",
            "victims", "The bones of past victims",  
            "blood", "Staining the bones",
  });
  smell="It smells of blood and guts.\n";
  dest_dir=({
             ORC+"treasure","north",
             ORC+"orc_vall","south",
  });
  clone_list=({ 
             1, 8, "orc", "obj/orc",0,
  });
  ::reset();
}

init() {
  ::init();
  add_action("north", "north");
}
