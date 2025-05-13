
inherit "room/room";
#include "../garden.h"

void reset(int arg) 
{
  if (filter_live(TO) < 1)
     CM("mous");

  if (arg) return;
   set_light(0);
   short_desc = "In a mousehole";
   long_desc = BS(
      "This is a mousehole of Chantilly's beautiful garden. "+
      "It is dark and very damp in this place. You should hope "+
      "that the mouse isn't around. He doesn't like intruders. "
      "There is a light coming from the south. If I were you I would "+
      "leave this dangerous place as quickly as possible.");

  dest_dir = ({ WIZ+"/hole/room/h2","down",
		ROOM+"/mousehole2","south" });

}
