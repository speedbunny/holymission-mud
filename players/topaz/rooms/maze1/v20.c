inherit "room/room";

#include "/players/topaz/defs.h"

object fbutter;
reset(arg) {
  if(!fbutter) {
    move_object(fbutter=clone_object(OBJS + "attach/fbutter"),this_object());
  }
  if(arg) return;
    short_desc="A maze";
    long_desc="This part of the maze looks easy.  But be careful!\n";

    dest_dir=({MAZE1 + "v17","northeast",
               MAZE1 + "v16","northwest",
               MAZE1 + "v7","southwest",
               MAZE1 + "v23","southeast",
    });
    items=({"maze","This maze may be tricky",
    });
    property="no_teleport";
    set_light(1);
return 1;
}
