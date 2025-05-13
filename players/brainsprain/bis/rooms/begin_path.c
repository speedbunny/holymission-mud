inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {

  short_desc = "A well maintained road";
  long_desc = "You stand on a well maintained road leading up the mountain. "+
              "You are surrounded on all sides by a deep, gloomy forest.  On "+
              "the sides of the path are many exotic flowers.  Every fifty "+
              "feet is a pole with a lantern on it.\n";
  set_light(1);
  dest_dir = ({
    br+"/beach","south",
    br+"/mountainside","north",
    br+"/f-1.c","east",
  });
  items = ({
    "castle","Bismarck Keep",
    "mountain","Mount Kladash, on which Bismarck Keep resides",
    "forest","A thick, tropical forest",
    "flowers","Carefully maintained orchids",
    "lantern","An ornate lantern",
    "pole","A tall pole with a lantern hanging from it",
    "lanternpole", "A tall pole with a lantern hanging from it",
    "road","A well maintained road",
    "path","A will maintained road",
  });
  ::reset(arg);
    replace_program("room/room");
}
