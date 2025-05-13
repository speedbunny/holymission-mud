#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="The stench of evil pervades the room.  A nagging twinge in " +
            "the back of your neck makes you think that it might be nice " +
            "to go back home and have a relaxing hot bath and a cup of tea, " +
            "instead of exploring this horrible place.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h8", "south",
           });

  items=({"cell", "Black holes are friendlier",
        });

  clone_list=({
    1,1,"spider","/players/emerald/dungeon/monster/spider",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
