
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
     "You have now entered  a warm and bright area in the sea. "+
     "There are sometimes mackerels swimming around. "+
     "There are big black rocks to the east and west.");

  dest_dir = ({
      PATH+"sw11","north",
      PATH+"sw13","south" });

  items = ({       
         "rock","A big black rock",
         "rocks","Big black rocks",
         "water","Clear sea water",
         "bottom","A sandy sea bottom" });
}
