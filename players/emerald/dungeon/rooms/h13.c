#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A hall in the dungeon";
    long_desc="The floor continues to slope to the south.  It is deadly " +
              "silent here, with nothing but the sound of your feet ringing " +
              "against the stones.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h12", "north",
               "players/emerald/dungeon/rooms/h14", "south",
               "players/emerald/dungeon/rooms/c17", "west",
             });
  items=({"cobbles","They join together to form the floor",
          "floor","It slopes to the south",
          "stones","Cut and dressed black basalt stones",
          "door","",
  });
  ::reset(arg);

  set_door("door");
  set_door_desc("door","A massive, lead-lined door.  On the door is an "+
                       "unbreakable lock");
  set_door_direction("door","west");
  set_lock_status("door",DOOR_LOCKED);
  set_door_key("door","ob3");
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "Suddenly the door swings shut.\n" );
  set_other_door( "door" );
}
