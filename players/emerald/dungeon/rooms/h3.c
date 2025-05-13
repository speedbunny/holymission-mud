#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(1);
    short_desc="A passageway in the dungeon";
    long_desc="This is definitely one of the dingiest dungeons that " +
              "you've ever had the misfortune to explore.  The few " +
              "dismal torches on the wall barely fend off the enfolding " +
              "darkness.  The humidity has increased, and now the water " +
              "dribbles down the walls.  And that snarling sound has " +
              "returned to send chills running up and down your spine " +
              "anew.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h4", "north",
               "players/emerald/dungeon/rooms/h2", "south",
               "players/emerald/dungeon/rooms/c13", "west",
             });

    items=({"stones", "Large slabs of hewn basalt slick with the " +
                      "collected moisture from the air",   
            "torches", "Pitch drips off the nearly-spent torches",
            "door","",
            "water", "Rivulets of water racing down the walls",
          });

    smell="It is becoming damper in here.";

  ::reset(arg);

  set_door("door");
  set_door_desc("door","This is an incredibly strong cell door.  On the "+
                       "door is an unbreakable lock");
  set_door_direction("door","west");
  set_lock_status("door",DOOR_LOCKED);
  set_door_key("door","ob3");
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "Suddenly the door swings shut.\n" );
  set_other_door( "door" );


}
