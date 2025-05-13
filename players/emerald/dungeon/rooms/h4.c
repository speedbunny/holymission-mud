#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A soggy passageway in the dungeon";
    long_desc="You have learned new reasons to curse humidity.  Mold " +
              "is growing on the walls and water stands in pools on the " +
              "floor, soaking through your shoes and into your socks.  " +
              "And the friendly torches have disappeared, " +
              "without even inviting you to come with them.  Of course, " +
              "you can always turn around and join them, but then, what " +
              "fun would that be?\n";

    dest_dir=({"players/emerald/dungeon/rooms/h5", "east",
               "players/emerald/dungeon/rooms/h3", "south",
               "players/emerald/dungeon/rooms/c12", "northwest",
             });

    items=({"stones", "Large slabs of hewn basalt covered in molds",
            "mold", "Phosphorescent molds happily growing in the dark, " +                       "humid environment",
            "torches", "They seem to have vanished into thin air",
          "door","",
            "pools", "Depressions in the floor filled with an " +
                     "incredibly wet variety of water",
          });

    smell="If you inhale any deeper, you might drown";
  ::reset(arg);

  set_door("door");
  set_door_desc("door","This is an incredibly strong cell door.  On the "+
                       "door is an unbreakable lock");
  set_door_direction("door","northwest");
  set_lock_status("door",DOOR_LOCKED);
  set_door_key("door","ob3");
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "Suddenly the door swings shut.\n" );
  set_other_door( "door" );

}
