inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {

     short_desc = "Topaz's test pit";
     long_desc = "This is where Topaz tests out his creations.\n";

      dest_dir = ({"players/topaz/workroom","up",
 
                     });

       set_light (1);
return 1; }}
