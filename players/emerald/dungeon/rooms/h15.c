#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A hall in the dungeon";
    long_desc="The floor slants more steeply to the south in this section " +
              "of the dungeon.  You can hear a few snarls and snaps coming " +
              "from that direction as well.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h14", "north",
               "players/emerald/dungeon/rooms/h16", "south",
               "players/emerald/dungeon/rooms/c6", "east",
             });
  items=({"floor","It slopes down to the south",
          "door","",
  });

  ::reset(arg);

  set_door("door");
  set_door_desc("door","A normal, ordinary door.  On the door is an "+
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
