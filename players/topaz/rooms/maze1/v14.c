inherit "room/room";

#include "/players/topaz/defs.h"

object fyoyo;
reset(arg) {
  if(!fyoyo) {
    move_object(fyoyo=clone_object(OBJS + "attach/fyo-yo"),this_object());
  }
  if(arg) return;
    short_desc="A maze";
    long_desc="This part of the maze looks easy.  But be careful!\n";

    dest_dir=({MAZE1 + "v11","northeast",
               MAZE1 + "v10","northwest",
               MAZE1 + "v18","southwest",
               MAZE1 + "v19","southeast",
    });
    items=({"maze","This maze may be tricky",
    });
    property="no_teleport";
    set_light(1);
return 1;
}
