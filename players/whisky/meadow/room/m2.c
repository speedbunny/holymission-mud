
inherit "room/room";
#include "../meadow.h"

void reset (int arg) 
{

  if (arg) return;
     short_desc = "On a meadow";
     set_light(1);
     long_desc = BS(
        "You are standing on the big meadow. The grass is "+
        "fresh and high. To the east you can hear the "+
        "rolling of the sea and to the west you see a "+
        "dark forest.");
   items = ({
          "forest","A dark forest",
          "grass","Fresh high grass",
                                   });
    dest_dir = ({
       PATH+"m3","east",
       PATH+"m4","northwest",
       PATH+"m5","north",
       PATH+"m6","northeast",
       PATH+"m1","southwest",
       WOOD+"forest2","west"  });
}
