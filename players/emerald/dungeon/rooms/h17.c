#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A hall in the dungeon";
    long_desc="The murky gloom of the dungeon makes it seem rather " +
              "oppressive.  Growling and snapping noises coming from " +
              "the east are not helping this impression.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h16", "east",
               "players/emerald/dungeon/rooms/h18", "west",
               "players/emerald/dungeon/rooms/c5", "south",
             });
  items=({"gloom","Rather gloomy gloom",
          "door","",
  });

  ::reset(arg);

  set_door("door");
  set_door_desc("door","This is an incredibly strong cell door.  On the "+
                       "door is an unbreakable lock");
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
