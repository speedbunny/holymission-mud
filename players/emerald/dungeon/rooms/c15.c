#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="You've entered the cell, but you can't seem to go much further " +
            "than the doorway.  It could be just the size of the cell.  " +
            "Or it could be that all the loose debris in the room has been "+
            "piled in the doorway.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h7", "north",
           });

  items=({"cell", "Dark, dirty, moldy, the basic dungeon cell",
          "doorway","A normal-sized doorway",
          "debris","Bits of this and that, parts of the ceiling and walls..",
        });

  clone_list=({
    1,1,"giant","/players/emerald/dungeon/monster/giant",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
