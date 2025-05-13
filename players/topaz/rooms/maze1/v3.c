inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A maze";
    long_desc="This part of the maze looks easy.  But be careful!\n";

    dest_dir=({MAZE1 + "v2","northeast",
               MAZE1 + "v19","northwest",
               MAZE1 + "v5","southwest",
               MAZE1 + "v6","southeast",
    });
    items=({"maze","This maze may be tricky",
    });
    property="no_teleport";
    set_light(1);
return 1;
RR;
}
