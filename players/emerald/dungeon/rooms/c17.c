#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="You have entered a lead-lined cell.  The walls are covered " +
            "with wooden crosses.  You have a vague suspicion that this " +
            "might indicate the lair of a vampire.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h13", "east",
           });

  items=({"walls", "Lead covers every last inch of the walls",
          "cell","It is lined with lead",
          "crosses", "Wooden crosses that are symbols of terror " +
                     "for a vampire",
        });

  clone_list=({
    1,1,"vampire","/players/emerald/dungeon/monster/vamp",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
