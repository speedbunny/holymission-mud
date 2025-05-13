#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A passageway in the dungeon";
    long_desc="You move along the corridor in eerie silence.  The air is " +
              "thick and stifling in this section.  You tread softly, not " +
              "wishing to disturb the feeling of death.\n";

    dest_dir=({"/players/emerald/dungeon/rooms/h20", "east",
               "/players/emerald/dungeon/rooms/h22", "west",
               "/players/emerald/dungeon/rooms/c3", "south",
             });

  items=({"door","",
        });

    smell="It's musty in here";

  ::reset(arg);

  set_door("door");
  set_door_desc("door","A door which opens and closes.  On the door is "+
                      "an unbreakable lock");
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
