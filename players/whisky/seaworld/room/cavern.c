
#include "../seaworld.h"

void reset(int arg) 
{
  ::reset(arg);

  if (filter_live(this_object()) < 1 || arg == 0 )
     CM("sea_drake");

    if (arg) return;
    set_light(1);
    short_desc = "In the sea";
    long_desc = BS(
    "You are in the cavern of the red sea drake. "+
    "The water is very cold and black here. "+
    "There are big black rocks to the north, south, "+
    "east and west.");
    items = ({
      "rock","A big black rock",
      "rocks","Big black rocks",
      "water","Dark sea water",
      "bottom","A dark stony sea-bottom"
    });
    dest_dir = ({ PATH+"sw25","up" });
}
