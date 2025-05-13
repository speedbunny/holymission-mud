inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;
    short_desc="A small path";
    long_desc="The path doesn't seem to be well used, but you can tell\n" +
              "that someone or something has been here recently.\n" +
              "There is a little clearing southwest of here.\n";

    dest_dir=({ATTACH + "road6","north",
               ATTACH + "clearing","southwest",
    });
    items=({"path","You see strange footprints in the path",
            "clearing","The trees thin out and form a little clearing",
            "trees","They sway in the gentle breeze",
            "tree","There are many trees",
            "footprints","Normal feet didn't make these footprints",
    });
    set_light(1);
return 1;
RR;
}
