
inherit "/room/room";
#include "../meadow.h"

void reset(int arg) 
{

  if (filter_live(this_object()) < 1)
     CM("pheasant");

  if (arg) return;
  short_desc = "On a meadow";
  set_light(1);
  long_desc = BS(
    "You have now left the stony path and you are standing "+
    "on a big meadow. The grass is fresh and high and there "+
    "are some flowers next to your feet. To the east "+
    "you can hear the rolling of the sea and to the west "+
    "you see a dark forest.");

  items = ({ "forest","A big dark forest",
             "grass","3 feet high grass",
             "flower","Several kinds of flowers" });
  dest_dir = ({
              PATH+"m2","northeast",
              "players/emerald/seaworld/room/sea_way", "south",
              WOOD+"forest1","west" });
}
