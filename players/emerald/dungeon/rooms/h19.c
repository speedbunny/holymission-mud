#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

 if(arg) return;
    set_light(0);
    short_desc="A passageway in the dungeon";
    long_desc="The dungeon hallway continues.  You feel quite alone and " +
              "quite small as you realise the frailty of your mortality.  " +
              "The only sound you can hear if that of your rapidly beating " +
              "heart.\n";

    dest_dir=({"/players/emerald/dungeon/rooms/h18", "east",
               "/players/emerald/dungeon/rooms/h20", "west",
               "/players/emerald/dungeon/rooms/c19", "north",
             });

    smell="It's musty in here";

    items=({"door","",
          });
  ::reset(arg);

  set_door("door");
  set_door_desc("door","The portal to doom, perhaps?  On the door is an "+
                       "unbreakable lock");
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
