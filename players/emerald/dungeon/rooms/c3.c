#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="It's a good thing that the walls are several blocks thick " +
            "in these cells.  Many blocks are strewn all over the floor.  " +
            "It must be from the rock troll's efforts at escape.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h21", "north",
           });

  items=({"cell", "Dark, dirty, moldy, the basic dungeon cell",
          "blocks", "Stones that were once part of the cell walls",
          "floor","It is hidden underneath the blocks",
          "walls","They are missing several stone blocks",
        });

  clone_list=({
    1,1,"troll","/players/emerald/dungeon/monster/troll",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
