#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(1);
    short_desc="A passageway in the dungeon";
    long_desc="You have entered the dungeon of the castle.  It " +
              "seems to be everything you ever imagined a dungeon to be in " +
              "the manner of damp and mold, not to mention dirt.  At least " +
              "there are some torches to help guide you through.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h1", "north",
               "players/emerald/dungeon/rooms/h23", "south",
               "players/emerald/dungeon/rooms/c20", "east",
             });

    items=({"torches", "They gutter in unseen air currents",
            "mold","Green mold",
            "door","",
            "dirt","Black dirt",
          });


    smell="It's musty in here";

  ::reset(arg);

  set_door("door");
  set_door_desc("door","An ancient, yet strong door.  On the door is an "+
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
