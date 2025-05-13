inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The orc path";
  long_desc = 
        "You are on a path in orc valley.  Limbs are strewn about all "+
        "over the ground.  The path is made up from bones of unfortunate "+
        "victims who trespassed here.  There is a large building with a marble "+
        "staircase to the south of here, "+
        "while the path continues to the north.\n";
  smell="It smells like blood and guts.\n";
  dest_dir=({
       PK+"room/v1", "north",
       PK+"room/d", "south",
  });
  items=({
      "path", "A path made up of bones",
      "limbs", "Bloodied limbs strewn about the ground",
      "ground", "Limbs are stewn about on it",
      "bones", "Bones making up a path",
      "building", "A large building with a marble staircase",
      "staircase", "A marble staircase",
      "marble", "Marble making up a staircase",
      "blood", "You cannot see a smell",
      "guts", "You cannot see a smell",
      "smell", "You cannot see a smell",
      "victims", "Unfortunate victims that trespassed here",
  });
  clone_list=({
      1, 6, "orc", PK+"npc/orc", 0,
  });
  ::reset();
  replace_program("room/room");
}
