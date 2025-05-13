
#include "../seaworld.h"

void reset(int arg) 
{
 ::reset(arg);

 if (filter_live(this_object()) < 2)
    CM("stone_fish");

  if (arg) return;
  set_light(1);
  short_desc = "In the sea";
  long_desc = BS(
     "You have entered a warm and pleasant area in the sea. "+
     "The water here is warm and pleasant. There are big rocks "+
     "to the east and west.");
  dest_dir = ({
     PATH+"sw15","south",
     PATH+"sw13","north" });
  items = ({
     "rocks","Big black rocks",
     "rock","A big black rock",
     "water","Clear sea water",
     "bottom","A fine sandy bottom" });
 }
