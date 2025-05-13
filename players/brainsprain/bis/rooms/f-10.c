inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {
 
  short_desc = "Bismarck Hunting Reserve";
     long_desc = "Fresh deer tracks cover the area here.  They are fairly large.  One of the "+
                 "saplings here has a rub on it and it is obvious that the deer is shedding "+
                 "its velvet.  Several birds flutter through the air.\n";
  set_light(1);
  items = ({
    "birds","Beautiful blue birds",
    "tracks","Heart shaped foot prints",
    "sapling","A beech sapling, with some of the bark peeled off",
  });
  dest_dir = ({
    br+"/f-11.c","east",
    br+"/f-30.c","north",
    br+"/f-3.c","south",
    br+"/f-4.c","southeast",
 });
    clone_list=({ 1, 1, "deer", "obj/monster", ({"set_name","deer",
                                                 "set_alias","monster",
                                                 "set_race","deer",
                                                 "set_level",1,
                                                 "set_long",
"The soft brown fur of this beautiful animal shimmers in the sun.  His "+
"long, white tail hangs limply as he calmly eats some grass.  This deers "+
"antlers have 4 tines, making him a sizeable deer.  His ears prick up as "+
"he notices you.",
                                                 "set_short","A white-tailed deer",
                                                 "set_ac",0,
                                                 "set_wc",5,
                                                 }),
                                                 });
   ::reset(arg);

    replace_program("room/room");
}
