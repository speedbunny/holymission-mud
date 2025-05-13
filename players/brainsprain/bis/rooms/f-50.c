inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {
 
  short_desc = "Bismarck Hunting Reserve";
     long_desc = 
"The reserve here is an open grasslands.  To the north and west a mountain "+
"rises up.  The grass rustles noisily in the warm summer breeze.  Small "+
"butterflies flutter about in a beautiful arial dance.  Pollen hangs "+
"heavy on many of the flowers dotting the field.\n";
  set_light(1);
  items = ({
    "reserve","The hunting preserve of Count Bismarck",
    "mountain","Mount Kladash",
    "butterflies","Monarch Butterflies",
    "flowers","Poppy flowers litter the field",
    "grass","Thick, gorse grass",
  });
  dest_dir = ({
    br+"/f-51.c","east",
    br+"/f-30.c","south",
 });
    clone_list=({ 1, 1, "pheasant", "obj/monster", ({
                                                     "set_name","pheasant",
                                                     "set_alias","monster",
                                                     "set_race","pheasant",
                                                     "set_level",1,
                                                     "set_long",
"This pheasant wobbles about through the grass.  Its long tail feathers "+
"sway and bob.  Its head has iridescent green feathers on it.  This bird "+
"appears to be involved in some intricate and complex mating dance.",
                                                     "set_short","Pheasant",
                                                     "set_ac",0,
                                                     "set_wc",5,
                           }),
                          });

  ::reset(arg);

    replace_program("room/room");
}
