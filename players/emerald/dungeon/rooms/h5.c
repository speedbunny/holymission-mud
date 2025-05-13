#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A waterlogged passageway in the dungeon";
    long_desc="They don't make castles like they used to.  At least, " +
              "most of them don't have a foot of standing water in " +
              "the dungeon, however nasty it may be otherwise.  " +
              "Stairs lead out of the water, rising up to a door " +
              "in the north wall.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h4", "west",
               "players/emerald/dungeon/rooms/h6", "south",
               "players/emerald/dungeon/rooms/c11", "north",
             });


    items=({"stairs", "Three stone steps leading to a door",
            "water", "Cold water that reaches almost to your knees",
            "door","",
          });

  ::reset(arg);

  set_door("door");
  set_door_desc("door","This is an incredibly strong cell door.  On the "+
                       "door is an unbreakable lock");
  set_door_direction("door","north");
  set_lock_status("door",DOOR_LOCKED);
  set_door_key("door","ob3");
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "Suddenly the door swings shut.\n" );
  set_other_door( "door" );
}
