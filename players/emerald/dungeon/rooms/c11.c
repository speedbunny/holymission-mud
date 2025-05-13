#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="Something's not quite right here.  You can't put your finger " +
            "on it, but there's something odd about this room.  It's really " +
            "dry in here, for one thing.  None of the water outside has " +
            "seeped in.  The door fits snugly and the walls are smooth.  " +
            "It's an altogether different feeling in here.  It might not be " +
            "so bad, except that the floor is rather squishy.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h5","south",
           });

  items=({"walls", "Smooth walls with no visible cracks or seams",
          "floor", "You can't see the floor.  It's covered in bat guano",
        });

  smell="Ah, the wonderful scent of bat guano...";
  clone_list=({
    1,1,"bat","/players/emerald/dungeon/monster/vbat",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
