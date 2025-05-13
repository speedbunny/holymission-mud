inherit "room/room";

#include "/players/topaz/defs.h"

object beast;
reset(arg) {
  if(!beast) {
      move_object(beast=clone_object(MNST + "demons/beast"),TO);
  }
  if(arg) return;

     short_desc = "Room with a pit";
     long_desc = "There is a dark pit in the middle of this room.\n" +
                 "You hear moaning coming from the pit.\n";

      dest_dir = ({"players/topaz/rooms/demons/pit","down",
                   "players/topaz/rooms/demons/cave6","north",
 
                     });

     items =({"pit","A dark pit.  You wonder what's down there",
              "room","This room is pretty dark",
              });
       set_light (-1);
       smell = "Smells like the demon beast has been here a long time.";
}
