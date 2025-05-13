inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {


  short_desc = "Bismarck Hunting Reserve";
     long_desc = "This area of the woods is dominated by old grown oak trees.  Acorns litter "+
                 "the ground and lie in stacks.  This is the perfect conditions for squirrels "+
                 "to thrive in.  A stand of pines wall off the eastern side.\n";
  set_light(1);
  items = ({
    "woods","An old growth forest",
    "ground","It is littered with acorns",
    "pines","A stand of pine trees",
    "trees","Old growth oak trees",
    "acorns","Tiny nuts",
  });
  dest_dir = ({
    br+"/f-20.c","west",
    br+"/f-4.c","north",
    br+"/f-3.c","northwest",
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
                                                  });
   ::reset(arg);

replace_program("room/room");
}
