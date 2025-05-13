inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "The north - south part of Main Street";
  long_desc =
    "Main Street takes a north - south course here. To the north the "+
    "road curves east. To the south it heads west again. To the west "+
    "is the entrance to Candy's Confectioner's Shop.  The thick solid wall "+
    "of the church rises to the east.\n";

  dest_dir = ({
    HM_VILLAGE + "street05", "north",
//    HM_VILLAGE + "cakeshop", "west"
    HM_VILLAGE + "street07", "south", 
  });

  items = ({
    "main street","The major road through the village",
    "street","The major road through the village",
    "entrance","Sweet smells waft out of the doorway to the Confectioner's",
    "road","Main Street is a well maintained dirt raod", 
    "wall","The wooden wall of the church holds beautiful windows",
    "windows","You should look at them from inside the church to see "+
      "them well"
  });

  ::reset(arg);
  replace_program("room/room");
}

