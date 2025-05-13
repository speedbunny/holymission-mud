inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="The way out!";
long_desc="This is the way out of the maze!\n" +
          "There is a ladder here leading up.\n";

    dest_dir=({MAZE1 + "v8","west",
               ATTACH + "forest6","up",
    });
    items=({"maze","This is the way out",
            "ladder","It looks old, but sturdy",
    });
    property="no_teleport";
    set_light(1);
return 1;
RR;
}
