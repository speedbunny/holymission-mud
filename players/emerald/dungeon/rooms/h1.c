#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;
    set_light(1);
    short_desc="A passageway in the dungeon";
    long_desc="The torchlight flickers dimly against the dark walls of " +
              "the passageway, casting eerie shadows.  The snarling " +
              "heard previously has increased in volume.  You hesitate " + 
              "to think what lies beyond the cell doors.\n";

     dest_dir=({"players/emerald/castle/rooms/stair", "up",
                "players/emerald/dungeon/rooms/h2", "north",
                "players/emerald/dungeon/rooms/h24", "south",
                "players/emerald/dungeon/rooms/c21", "east",
               });
  
   items=({"shadows","Frightening images flicker across the walls",
           "torchlight","The flames slicker in unseen draughts",
           "door","",
           "passageway","A dark passageway through the castle dungeon",
           "doors","There is a door to the east leading into a cell",
           "walls","Solid, smooth basalt walls",
         });

  ::reset(arg);
  set_door("door");
  set_door_desc("door","This is an incredibly strong cell door.  On the door\n"+
                       "is an unbreakable lock");
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
