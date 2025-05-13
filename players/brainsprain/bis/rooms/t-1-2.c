#include <doorroom.h>
#include "/players/brainsprain/bis/bisdef.h"
inherit DOOR_ROOM;

void reset(int arg) {
  ::reset(arg);
  
  short_desc = "Second floor of southeastern tower";
  long_desc =
    "The staircase curves around the entire room in a spiral leading up "+
    "and down.  The walls here have been painted in pastels, however the "+
    "room is empty.  A pleasant colored light filters down from above.\n";
  set_light(1);
  hidden_dir = ({ br+"/t-1-3","up", });
  dest_dir = ({ br+"/t-1-1", "down", });
  items = ({
    "spiral",
    "The staircase spirals up to the next floor",
    "room",
    "The second floor of the southeastern tower",
    "tower",
    "The southeastern tower",
    "staircase",
    "A spiral staircase leading up and the tower",
    "walls",
    "Pretty light blue walls",
    "metal door", "", 
  });
  set_door("metal door");
  set_door_desc("metal door", "A pink door that leads to the princesses room");
  set_door_direction("metal door", "up");
  set_lock_status("metal door", DOOR_LOCKED + 1);
  set_door_key("metal door", "brainsprain_metal_door_key");
  set_door_reset(
		 "metal door", 
		 ({   
		   "set_door_status", DOOR_CLOSED,
		     "set_lock_status", DOOR_LOCKED +1,
		     }));
  set_door_reset_msg("metal door", "The metal door swings shut.\n");
  set_other_door("metal door");
  replace_program(DOOR_ROOM);
}
