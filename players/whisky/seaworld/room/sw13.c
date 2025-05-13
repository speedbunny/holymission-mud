

#include "../seaworld.h"

void reset(int arg) 
{
  ::reset(arg);

  if (filter_live(this_object()) < 2)
      CM("mackerel");

  if (arg) return;
  set_light(1);
  short_desc = "In the sea";
  long_desc = BS(
     "You have now entered a beautiful area of the sea. "+
     "The sun is shining through the water and there are "+
     "sometimes shells lying on the bottom. There are rocks "+
     "to the east and west.");

  dest_dir = ({
      PATH+"sw14","south",
      PATH+"sw12","north" });
  items = ({
      "rock","A big black rock",
      "rocks","Big black rocks",
      "water","Clear sea water",
      "bottom","A sandy sea bottom" });
 }
