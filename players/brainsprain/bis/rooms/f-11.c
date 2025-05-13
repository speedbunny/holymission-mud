inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {
 
  short_desc = "Bismarck Hunting Reserve";
     long_desc = "There is a large amount of underbrush and pricker bushes here.  Thorns "+
                 "catch on the sleeves of your shirt and pull.  There is a stand of pines "+
                 "to your east.  Old deer tracks lead off to the west.  The air here "+
                 "smells so much more clean than the air in any city.\n";
  set_light(1);
  items = ({
     "bushes","Bushes covered in pricker balls",
     "thorns","Long, thin thorns",
     "underbrush","Scraggly bushes",
     "pines","Medium sized spruce and cedar",
     "tracks","heart shaped foot prints",
  });
  dest_dir = ({
    br+"/f-10.c","west",
    br+"/f-4.c","south",
 }); 
    clone_list=({ 1, 1, "rabbit", "obj/monster", ({"set_name","rabbit",
                                                   "set_alias","monster",
                                                   "set_race","rabbit",
                                                   "set_level",2,
                                                   "set_long",
"This cute rabbit slowly hops along as its powerful hindquarters propel "+
"it to its destination.  Its sleek gray fur is matted to its body in "+
"some places from burrs and thorns.  Its puffy white tail wiggles in the "+
"breeze.\n",
                                                   "set_short","Cotton-tailed Rabbit",
                                                   "set_ac",0,
                                                   "set_wc",6,
                                                  }),
                                                   });
  ::reset(arg);

    replace_program("room/room");
}
