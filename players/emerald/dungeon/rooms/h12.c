#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A hall in the dungeon";
    long_desc="The floor has taken a slight grade downwards to the " +
              "south.  There is a rather loud growling sound coming from " +
              "the cell to the east.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h11", "north",
               "players/emerald/dungeon/rooms/c8", "east",
               "players/emerald/dungeon/rooms/h13", "south",
             });
  items=({"floor","It slopes to the south",
          "door","",
  });

  ::reset(arg);

  set_door("door");
  set_door_desc("door","An iron-bound oak door.  On the door is an "+
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
