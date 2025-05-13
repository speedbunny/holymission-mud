#include <doorroom.h>

inherit DOOR_ROOM;
void reset(int arg) {

  if(arg) return;
    set_light(1);
    short_desc="A passageway in the dungeon";
    long_desc="You feel dwarfed and insignificant by the imposing black " +
              "basalt walls of this dungeon.  Judging from the height of " +
              "of the torches in the sconces, you had better find some " +
              "light sources pretty quickly.\n";

    dest_dir=({"/players/emerald/dungeon/rooms/h24", "north",
               "/players/emerald/dungeon/rooms/h22", "south",
               "/players/emerald/dungeon/rooms/c1", "west",
             });

    items=({"torches", "They gutter in unseen air currents",
            "walls","Depressing basalt walls",
            "door","",
          });


    smell="It's musty in here";

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
