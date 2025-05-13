#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A hall in the dungeon";
    long_desc="You still feel the slope of the floor.  It has become " +
               "rather slippery, and you take care not to go sliding " +
               "away into the darkness.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h13", "north",
               "players/emerald/dungeon/rooms/h15", "south",
               "players/emerald/dungeon/rooms/c7", "east",
             });
  items=({"floor","It is slippery and grades downwards to the south",
          "door","",
  });

  ::reset(arg);

  set_door("door");
  set_door_desc("door","A thick stone-faced door.  On the door is an "+
                       "unbreakable lock");
  set_door_direction("door","east");
  set_lock_status("door",DOOR_LOCKED);
  set_door_key("door","ob3");
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "Suddenly the door swings shut.\n" );
  set_other_door( "door" );

}
