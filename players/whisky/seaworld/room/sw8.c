

#include "../seaworld.h"

reset(arg) 
{
  ::reset(arg);
 
  if (filter_live(this_object()) < 1)
  {
    CM("ball_fish"); 
    CM("crab");
  }

  if (arg) return;

  set_light(1);
  short_desc = "In the sea";
  long_desc = BS(
     "This is the most pleasant area of the sea. The sun is "+
     "shining through the warm water and there are sometimes "+
     "shells lying on the bottom. There is a big rock to the "+
     "east. That's a good place for almost every kind of fish.");

  dest_dir =
  ({   PATH+"sw7","north",
       PATH+"sw9","south",
       PATH+"sw4","west" });

items = ({ "rock","A big black rock",
           "bottom","A warm sandy sea bottom",
           "water","A clear warm sea water" });
}
