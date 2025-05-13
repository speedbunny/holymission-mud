

#include "../seaworld.h"

void reset(int arg) 
{
  ::reset(arg);

  if (filter_live(this_object()) < 2)
      CM("thun_fish");
     
  if (arg) return;

  set_light(1);
  short_desc = "In the sea";
  long_desc = BS(
    "You have entered a part of the sea which is colder. "+
    "You can see some big rocks to the east and west. "+
    "This is a very good place for the thun fish, because "+
    "the fishers have a hard time finding him here.");

dest_dir = ({
        PATH+"sw6", "north",
        PATH+"sw8", "south" });
items = ({ "bottom","A warm sandy bottom",
           "sandbank","A little sandbank leading up",
            "rocks","Big black rocks",
            "rock","A big black rock",
            "water","You see clear blue sea water" });
}
