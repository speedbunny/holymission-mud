inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  set_light(1);
  short_desc = "The cave entrance";

  long_desc = 
    "This is the entrance into the mines. To the east is the "+
    "cave entrance, while northwest leads further into the "+
    "mines.\n";

  items = ({
    "mines", "Probably they were originally made by dwarves",
    "entrance", "It is to the east and leads outside",
  });

  dest_dir = ({
    MINES + "tunnel01", "northwest",
    PLAIN + "mount_pass","east",
  });

  ::reset(arg);
  replace_program("/room/room");
}

