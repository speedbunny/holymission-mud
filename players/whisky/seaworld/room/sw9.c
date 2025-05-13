
#include "../seaworld.h"

void reset(int arg) 
{
  ::reset(arg);

  if (filter_live(this_object()) < 2)
      CM("carapace");
  
  if (arg) return;

   set_light(1);
   short_desc = "In the sea";

   long_desc = BS(
     "You have now entered one of the eastern corners of the sea. "+
     "The water is warm here and the bottom is sandy. "+
     "There are rocks to the west and south.");

   dest_dir = ({
      PATH+"sw15","east",
      PATH+"sw8","north" });

   items = ({
     "rock","A big black rock",
     "rocks","Big black rocks",
     "bottom","A fine sandy bottom",
     "water","Clear fresh sea water" });
}
