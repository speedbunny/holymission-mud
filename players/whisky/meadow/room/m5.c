

inherit "room/room";
#include "../meadow.h"

void reset (int arg) 
{

  if (filter_live(this_object()) < 1)
     CM("bull");

  if (arg) return;
  set_light(1);
  short_desc = "On a meadow";
  long_desc = BS(
    "You are standing on the big meadow. The grass is "+
    "fresh and high. In all directions the meadow leads "+
    "further. To the far west you see some bushes and to the "+
    "you can hear the rolling of the sea.");
  items = ({ "bushes","10 foot high hazelnut bushes" });
  dest_dir = ({
    PATH+"m8","north",
    PATH+"m2","south",
    PATH+"m4","west",
    PATH+"m6","east",
    PATH+"m7","northeast",
    PATH+"m9","northwest",
    PATH+"m3","southeast",
    WOOD+"forest2","southwest" });
    CO("tree");
}

