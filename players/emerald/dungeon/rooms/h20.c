#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A passageway in the dungeon";
    long_desc="The feeling of emminent death persists.  The walls loom " +
              "cold and black on both sides of you.  You shiver to think " +
              "of what other denizens this dungeon contains.\n";

    dest_dir=({"/players/emerald/dungeon/rooms/h19", "east",
               "/players/emerald/dungeon/rooms/h21", "west",
               "/players/emerald/dungeon/rooms/c4", "south",
             });

    smell="It's musty in here";


  items=({"walls","Cold, black stone walls",
          "door","",
  });
  ::reset(arg);

  set_door("door");
  set_door_desc("door","It's a door.  It plugs up a hole in the wall.  On "+
                       "the door is an unbreakable \nlock");
  set_door_direction("door","south");
  set_lock_status("door",DOOR_LOCKED);
  set_door_key("door","ob3");
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "Suddenly the door swings shut.\n" );
  set_other_door( "door" );
}
