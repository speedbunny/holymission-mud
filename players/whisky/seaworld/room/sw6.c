
#include "../seaworld.h"

void reset(int arg) 
{
  ::reset(arg);

  if (filter_live(this_object()) < 2)
      CM("ball_fish");

  if (arg) return; 

   set_light(1);
   short_desc = "In the sea";
   long_desc = BS(
      "You have now entered a warm and pleasant place in the sea. "+
      "The water here is a little deeper. "+
      "This is where the Ball Fish likes to eat.");

   dest_dir = ({
      PATH+"sw2", "west",
      PATH+"sw5", "north",
      PATH+"sw7", "south" });

   items = ({ "bottom", "A warm sandy bottom",
              "water", "You see a blue clear water" });
}
