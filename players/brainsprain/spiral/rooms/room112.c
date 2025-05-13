
inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
  
  short_desc = "Odd shaped room";
  long_desc =
    "The walls lie at odd angles in this room.  The northwestern wall comes "+
    "to a v-shaped point about five feet from the ground.  The floor is also "+
    "angular and uneven.  Several, small objects lie on the floor in groups.\n";
  items = ({
    "objects",
    "Hunks of limestone that litter the floor",
    "walls",
    "They are oddly angular",
    "floor",
    "It is angular and uneven",
  });

  set_light(0);
  dest_dir = ({
    sr+"/room111","southwest",
    sr+"/room113","northeast",
  });
  clone_list = ({ 1, 1, "badger", sm+"/badger.c", 0 });
  ::reset(arg);
  replace_program("room/room");
}
