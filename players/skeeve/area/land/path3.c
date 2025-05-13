inherit "room/room";

#include "/players/skeeve/area.h"

reset(arg) {
  if (!arg)  {
    set_light(1);
    short_desc = "path";
    long_desc = 
        "You are on the path to the pasture of Druid Lakmir.\n"
       + "There a deep footprints of bull at the ground.\n";
    smell = "You smell the aroma of cows";
    dest_dir = ({
        LAND + "fork", "north",
        LAND + "meadow2", "east",
        LAND + "pasture", "south",
        LAND + "forest2", "west"
       });
    items = ({
      "north",  "The fork",
      "east",   "There is a meadow with many flowers",
      "flowers","There are flowers in all colors. \n"
               +"You are not near enough to see more",
      "south",  "There is the pasture of druid Lakmirs cows",
      "west",   "The forrest",
      "path",   "Its a small and lonesome path",
      "forest", "You know, there are monsters in the forest",
      "shore",  "You smell the taste of saltwater",
      "pasture","Druid Lakmirs milkcows and his bull are living there"
    });
   }
}

