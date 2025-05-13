inherit "room/room";

#include "/players/skeeve/area.h"

reset(arg) {
  if (!arg)  {
    set_light(1);
    short_desc = "path";
    long_desc = 
         "You are on the path to the cottage of the druid Lakmir.\n"
       + "You can hear some monsters around you.\n";
    dest_dir = ({
        LAND + "forest3", "north",
        LAND + "fork",    "east",
        LAND + "forest2", "south",
        LAND + "clearing","west"
       });
    items = ({
      "clearing","In the middle of the clearing stands druid Lakmirs cottage",
      "path",   "Its a small and lonesome path",
      "forest", "The trees in this forest are old and very high"
    });
   }
}
