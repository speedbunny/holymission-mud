inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(arg) return;

     short_desc = "Muddy path";
     long_desc = "You are on a heavily used, muddy path.\n" +
                 "You can see a good sized tree to the north, while\n" +
                 "the path connects with a nice road to the west.\n";

      dest_dir = ({ATTACH + "meadow","north",
                   ATTACH + "road1","west",
                   ROOM + "attach/field2","east",
 
                     });
     items = ({"path","It is quite muddy, from much use",
               "tree","It is a big oak tree",
               "road","It looks like a nice road to the west",
     });

       set_light (1);
return 1;
RR;
}
