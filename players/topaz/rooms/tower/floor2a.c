inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {

     short_desc = "A small alcove";
     long_desc = "This small alcove is where the demons keep one of their 'pets'.\n";

      dest_dir = ({"players/topaz/rooms/tower/floor2","west",
 
                     });

     items =({"alcove","There's not that much room in here",
              });
       set_light (0);
return 1; }}
