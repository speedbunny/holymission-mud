#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;
    set_light(1);
    short_desc="A passageway in the dungeon";
    long_desc="The torchlight glistens against the damp stones of the " +
              "dungeon walls.  Even with the torches, an oppressive " +
              "gloom fills the passage.  From somewhere around your " +
              "feet you hear the distinctive squeak of a rat.  " +
              "Another cell is off to the east.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h3", "north",
               "players/emerald/dungeon/rooms/h1", "south",
               "players/emerald/dungeon/rooms/c14", "east",
             });

    items=({"stones", "Large slabs of hewn basalt damp with the collected " +
                      "moisture from the air",   
            "torches", "Pitch drips off the nearly-spent torches",
            "door","",
          });


    smell="It's musty in here";


  ::reset(arg);
  set_door("door");
  set_door_desc("door","This is an incredibly strong cell door.  On the "+
                       "door is an unbreakable lock");
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
