inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {
 
  short_desc = "Bismarck Hunting Reserve";
     long_desc = 
"The woods here thin slightly as the area turns into the side of a gradual "+
"hill.   Thick gorse grass sticks up through the ground and sways in the "+
"light breeze.  The grass continues to the north.\n";
  set_light(1);
  items = ({
    "woods","Old growth woods",
    "ground","It is covered in gorse grass",
    "hill","A gradual hill",
  });
  dest_dir = ({
    br+"/f-50.c","north",
    br+"/f-10.c","south",
      });
    clone_list= ({
               1, 2, "squirrel", "obj/monster", ({"set_name","squirrel",
                                                  "set_alias","monster",
                                                  "set_race","squirrel",
                                                  "set_level",1,
                                                  "set_long",
"This chittering red squirrel hops from the ground to the tree and back "+
"down again.  It grabs acorns off of the ground and stuffs it's mouth. "+
"This squirrel has red fur and a scraggly tail.  It is somewhat smaller "+
"than the gray squirrels you might have seen.",
                                                  "set_short","Red squirrel",
                                                  "set_ac",2,
                                                  }),
              2,1, "deer", "obj/monster", ({"set_name","deer",
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
