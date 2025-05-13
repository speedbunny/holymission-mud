inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {
 
  short_desc = "Bismarck Hunting Reserve";
     long_desc = "The field narrows down here to little more than a path between the high "+
                 "mountainside to the north and a cliff that drops off to the south.  Rocks "+
                 "tumble down from above and skitter over the edge of the cliff.\n";
  set_light(1);
  items = ({
    "mountain","Mount Kladash",
    "field","A green field of gorse grass",
    "path","A little footpath between the mountain and the cliff",
    "cliff","A straight thirty foot drop",
    "rocks","Huge, rolling boulders",
  });
  dest_dir = ({
    br+"/f-50.c","west",
 });
    clone_list=({ 1, 1, "sheep", "obj/monster", ({"set_name","sheep",
                                               "set_alias","monster",
                                               "set_race","sheep",
                                               "set_level",2,
                                               "set_long",
"This poor little sheep looks bewildered, almost as if he does not quite "+
"fit into his body.  He bleats soulfully as he sees you.  There are "+
"several grass stains on his face.  He looks like he needs a trim. ",
                                                "set_short","Sheep",
                                                "set_ac",0,
                                                "set_wc",6,
                                              }),
                                          });

  ::reset(arg);

    replace_program("room/room");
}
