
inherit "room/room";
#include "../garden.h"

void reset(int arg) 
{
  if (arg) return;
   set_light(0);
  short_desc = "In a mousehole";
  long_desc = BS(
    "This is a mousehole of Chantilly's beautiful garden. "+
    "It's dark and wet here, and the smell of cheese makes you hungry.");

  dest_dir = ({ ROOM+"/mousehole3","north",
		ROOM+"/mousehole1","south" });
}
