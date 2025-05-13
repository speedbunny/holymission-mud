#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A hall in the dungeon";
    long_desc="Ugh!  Some nasty spider has decided to spin its web " +
              "right through the middle of the hall.  Cobweb fragments " +
              "cling to your hair and clothing.  You feel a tickling " +
              "sensation across your neck, and you assume that it's the " +
              "former owner of the web that you have just ripped apart.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h11", "east",
               "players/emerald/dungeon/rooms/h9", "west",
               "players/emerald/dungeon/rooms/c9", "north",
             });

    items=({"cobweb", "It's currently wrapped around your body",
            "door","",
            "hall","A nasty dank passage through the dungeon",
          });

  ::reset(arg);

  set_door("door");
  set_door_desc("door","A solid oaken door.  On the door is an unbreakable "+
                       "lock");
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
