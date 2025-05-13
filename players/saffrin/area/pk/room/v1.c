inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The orc path";
  long_desc = 
        "You are on a path in orc valley.  Limbs are strewn about all "+
        "over the ground.  The path is made up from bones of unfortunate "+
        "victims who trespassed here.  There is an orc fireplace to the north "+
        "and the path leads to the south.\n";
  smell="It smells like blood and guts.\n";
  dest_dir=({
        "room/orc_valley/valley01", "north",
       PK+"room/v2", "south",
  });
  items=({
      "path", "A path made up of bones",
      "limbs", "Bloodied limbs strewn about the ground",
      "ground", "Limbs are stewn about on it",
      "bones", "Bones making up a path",
      "blood", "You cannot see a smell",
      "guts", "You cannot see a smell",
      "smell", "You cannot see a smell",
      "fireplace", "The orc fireplace",
      "victims", "Unfortunate victims that trespassed here",
  });
  clone_list=({
      1, 4, "orc", PK+"npc/orc", 0,
  });
  ::reset();
  replace_program("room/room");
}
