

#include "../seaworld.h"

void reset(int arg) 
{
  ::reset(arg);

  if (filter_live(this_object()) < 1)
      CM("carapace");

  if (arg) return;

   set_light(1);
   short_desc = "In the sea";
   long_desc = BS(
     "You have now entered a nice and warm place in the sea. "+
     "The water here is a little bit deeper than in the south. "+
     "Sometimes there are shells lying at the bottom and "+
     "there are rocks to the west and north. "+
     "This place is really a good place for the big carapace "+
     "to find some food.");

items = ({
         "rock","A big black rock",
           "bottom","A fine sandy bottom",
            "water","Crystal clear saltwater" });
dest_dir = ({
  PATH+"sw11", "east",
  PATH+"sw6", "south",
  });
}
