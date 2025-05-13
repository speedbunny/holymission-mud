/* Uglymouth, 970721: Recoded to use inheritable door room instead of macro.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

int move(string str) {
  if(!str)
    str = query_verb();
  if(this_player()->query_immortal())
    return ::move(str);
  switch(str) {
    case "north" :
    case "east" :
    case "west" :
      if(present("rug",this_object())) {
        write("You stumble over a bulge in the rug.\n");
        say(this_player()->query_name()+ " stumbles over the rug.\n");
        return 1;
      }
  }
  return ::move(str);
}

void reset(int arg) {
  if(arg) return;

  set_light(1);


  short_desc="The anteroom of the cottage";
  long_desc="You have entered a long drafty hallway.  Several doors line "
            "the passage.  The old wooden floorboards creak ominously " +
            "under your weight. Your creaking footsteps echo through the " +
            "emptiness of the huge hallway.  The crest of the Druid Lakmir " +
            "hangs above the crafted door to the north.  A wooden door leads "+
            "out of the cottage.\n";

  dest_dir=({"/players/emerald/lakmir/clearing","out",
             "/players/emerald/lakmir/sittingroom","north",
             "/players/emerald/lakmir/kitchen","east",
             "/players/emerald/lakmir/office","west"
           });

  items=({"hallway","It is silent and cold",
          "doors","There are four doorways into the hallway",
          "door", "dummy description needed for inheritable door",
          "crafted door","A crafted wooden door",
          "crest","The crest of the Druid Lakmir is a giant oak tree",
          "wooden door","It leads back outside.  It has a skeleton lock",
          "passage","A long hallway",
          "floorboards","Wide oaken floorboards",
        });

  property=({"no_sneak",});

  clone_list=({
    1,1,"rug","/players/emerald/lakmir/rug",0,
  });

  ::reset(arg);
  set_door("crafted door");
  set_door_desc("crafted door","A crafted wooden door.  On the door is a "+
                               "crafted lock");
  set_door_direction("crafted door","north");
  set_lock_status("crafted door",DOOR_LOCKED);
  set_door_key("crafted door","rw1");
  set_door_reset("crafted door",({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg("crafted door","An unseen forced shuts the crafted door.\n");
  set_other_door("crafted door");
}
