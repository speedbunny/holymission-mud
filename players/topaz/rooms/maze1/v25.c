inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A maze";
    long_desc="This part of the maze looks easy.  But be careful!\n";

    dest_dir=({MAZE1 + "v24","northeast",
               MAZE1 + "v23","northwest",
               MAZE1 + "v15","southwest",
               MAZE1 + "v12","southeast",
    });
    items=({"maze","This maze may be tricky",
    });
    property="no_teleport";
    set_light(1);
return 1;
RR;
}
