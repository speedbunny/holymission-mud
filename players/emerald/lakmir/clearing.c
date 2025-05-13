#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="A clearing in the forest";
  long_desc="You have arrived at a clearing in the center of the forest.  "+
            "A small cottage sits in the middle of the clearing.  " +
            "A wooden door leads into the cottage.  Hanging above the " +
            "door is a skull.\n";

  dest_dir=({"/players/emerald/lakmir/forest6","north",
             "/players/emerald/lakmir/path2","east",
             "/players/emerald/lakmir/forest5","south",
             "/players/emerald/lakmir/forest9","west",
             "/players/emerald/lakmir/anteroom","northeast",
           });

  items=({"cottage","A small wooden cottage",
          "skull","The skull of some unknown creature.  It sits in a " +
                  "small recess and appears to be attached to a spring",
          "forest","A dark and evil forest",
          "spring","It is uncompressed",
          "recess","It is skull shaped.  You notice that the skull is not " +
                   "pushed back in the recess as far as it should be",
          "clearing","There are no trees here",
          "door","",
        });

  property=({"no_sneak",});

  ::reset(arg);

  set_door("door");
  set_door_desc("door","A wooden door.  On the door is a skeleton lock");
  set_door_direction("door","northeast");
  set_lock_status("door",DOOR_LOCKED);
  set_door_key("door","ob1");
  set_door_reset("door", ({    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "Suddenly the door swings shut.\n" );
  set_other_door( "door" );

  ::reset();


}


void init() {
    ::init();
    add_action("_press","press");
    add_action("_press","push");
}

_press(str) {
object skeleton;

  if(str=="skull") {
    write("As you press the skull back into the recess, a strange click\n" +
          "is heard.  Suddenly, a skeleton appears out of nowhere!\n");
    say(this_player()->query_name()+" presses the skull.\n");
    move_object(clone_object("/players/emerald/lakmir/skeleton"),this_object());
    return 1;
  }

  if(str!="skull") {
    write(query_verb()+" what?\n");
    return 1;
  }
} 
