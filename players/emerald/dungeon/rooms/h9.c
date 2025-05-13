#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A hall in the dungeon";
    long_desc="You are wandering through a hallway in the dungeon of " +
              "castle.  Every now and again a drop of water falls from " +
              "the ceiling, making a pinging sound as it hits the cobbles " +
              "below.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h10", "east",
               "players/emerald/dungeon/rooms/h8", "west",
               "players/emerald/dungeon/rooms/c16", "south",
             });

    items=({"drop", "Small drops of water",
            "ceiling", "It's covered with tiny water droplets",
            "door","",
            "water","Small drops of water",
            "hallway","A connecting passage used to facilitate movement",
            "cobbles", "Rough-hewn, uneven stone cobbles",
          });

  ::reset(arg);

  set_door("door");
  set_door_desc("door","An ancient, yet imposing door.  On the door is an "+
                       "unbreakable lock");
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
