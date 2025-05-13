inherit "room/room";

#include "/players/topaz/defs.h"

object fmilk;
reset(arg) {
  if(!fmilk) {
    move_object(fmilk=clone_object(OBJS + "attach/fmilk"),this_object());
  }
  if(arg) return;
    short_desc="A maze";
    long_desc="This part of the maze looks easy.  But be careful!\n";

    dest_dir=({MAZE1 + "v6","northeast",
               MAZE1 + "v5","northwest",
               MAZE1 + "v13","southwest",
               MAZE1 + "v1","southeast",
    });
    items=({"maze","This maze may be tricky",
    });
    property="no_teleport";
    set_light(1);
return 1;
}
