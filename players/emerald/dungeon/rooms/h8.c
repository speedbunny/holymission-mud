#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A damp passageway in the dungeon";
    long_desc="Water makes the walls and floor of this passageway " +
              "rather slick.  But with careful footing the bold " +
              "adventurer can easily negotiate the slippery cobbles.\n";

    dest_dir=({"players/emerald/dungeon/rooms/c10", "north",
               "players/emerald/dungeon/rooms/h7", "west",
               "players/emerald/dungeon/rooms/h9", "east",
             });

    items=({"water", "It's wet",
            "walls", "Dark stone walls shiny with moisture",
            "passageway","What you are currently walking through",
            "floor", "Uneven cobbles pave the floor",
            "door","",
            "cobbles", "Rough-hewn blocks of stone embedded in mortar to " +
                       "create the floor.  They glisten with moisture",
          });

  ::reset(arg);

  set_door("door");
  set_door_desc("door","A solid door.  On the door in an unbreakable lock");
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
