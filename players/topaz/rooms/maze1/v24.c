inherit "room/room";

#include "/players/topaz/defs.h"

object fcandy;
reset(arg) {
  if(!fcandy) {
    move_object(fcandy=clone_object(OBJS + "attach/fcandy"),this_object());
  }
  if(arg) return;
    short_desc="A maze";
    long_desc="This part of the maze looks easy.  But be careful!\n";

    dest_dir=({MAZE1 + "v22","northeast",
               MAZE1 + "v21","northwest",
               MAZE1 + "v25","southwest",
               MAZE1 + "v8","southeast",
    });
    items=({"maze","This maze may be tricky",
    });
    property="no_teleport";
    set_light(1);
return 1;
}
