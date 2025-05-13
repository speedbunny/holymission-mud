#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A passageway in the dungeon";
    long_desc="It's dark in here.  Really dark.  Too bad the torches " +
              "in the walls decided to burn out.  Maybe this is a hint that " +
              "you ought to go back upstairs.\n";

    dest_dir=({"/players/emerald/dungeon/rooms/h23", "north",
               "/players/emerald/dungeon/rooms/h21", "east",
               "/players/emerald/dungeon/rooms/c2", "southwest",
             });

  items=({"torches","Burnt-out stubs of torches",
          "door","",
  });

    smell="It's musty in here";

  ::reset(arg);

  set_door("door");
  set_door_desc("door","Just a door.  On the door is an unbreakable lock");
  set_door_direction("door","southwest");
  set_lock_status("door",DOOR_LOCKED);
  set_door_key("door","ob3");
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "Suddenly the door swings shut.\n" );
  set_other_door( "door" );

}
