#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A hall in the dungeon";
    long_desc="You feel an impending sense of doom in this section of " +
              "the dungeon.  It could be just that it is so very dark in " +
              "here.  But it could also be from the red glow emanating " +
              "from the cell door to the north.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h17", "east",
               "players/emerald/dungeon/rooms/h19", "west",
               "players/emerald/dungeon/rooms/c18", "north",
             });
    property=({"no_sneak",
    });

  items=({"glow","An evil red glow",
          "door","",
  });
  ::reset(arg);

  set_door("door");
  set_door_desc("door","This is a curiously strange door.  On the door is "+
                       "an unbreakable lock");
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
