#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A wet hallway in the dungeon";
    long_desc="If you would be outside, you would call it rain.  Since " +
              "you are inside, however, it must just be condensation.  " +
              "Usually, condensation is not such a noticeable " +
              "process.  Huge water drops are commiting suicide by " +
              "falling off the ceiling and on to your head.  The walls " +
              "have verticle rivers of water.  And yes, the water is " +
              "collecting in pools on the floor.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h6", "west",
               "players/emerald/dungeon/rooms/h8", "east",
               "players/emerald/dungeon/rooms/c15", "south",
             });


    items=({"water", "Genuine rehydrated water",
            "pools","A large collection of water molecules",
            "door","",
            "walls", "Black stone walls with sheets of water coursing " +
                    "down them",
            "ceiling","It's quite wet",
            "condensation","A process by which water accumulates into drops",
          });

  ::reset(arg);

  set_door("door");
  set_door_desc("door","An ancient, but tough door.  On the door is an "+
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
