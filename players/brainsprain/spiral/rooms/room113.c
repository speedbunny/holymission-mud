inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
reset(arg) {

  short_desc = "A dank, dark room.";
  long_desc =
    "The air has grown very humid.  In the distance you can hear the trickle "+
    "flowing water.  The ground is smooth and flat.  The walls show signs of "+
    "erosion.  Swirling designs cover the walls where the limestone has been "+
    "eroded out of the granite.\n";
  set_light(0);
  dest_dir = ({
    sr+"/room112","southwest",
    sr+"/room114","north",
  });
  items = ({
    "granite",
    "It makes swirls in the wall",
    "ground",
    "The floor of this cavern",
    "walls",
    "They show signs of erosion",
    "granite",
    "This granite have formed into weird patterns",
  });
  clone_list = ({ 1, 1, "slug", sm+"/slug.c", 0 });
  ::reset(arg);
  replace_program("room/room");
}
