inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A maze";
    long_desc="This part of the maze looks easy.  But be careful!\n";

    dest_dir=({MAZE1 + "v14","northeast",
               MAZE1 + "v1","northwest",
               MAZE1 + "v21","southwest",
               MAZE1 + "v22","southeast",
    });
    items=({"maze","This maze may be tricky",
    });
    property="no_teleport";
    set_light(1);
return 1;
RR;
}
