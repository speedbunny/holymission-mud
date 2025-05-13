

#include "../seaworld.h"

void reset(int arg) 
{
   ::reset(arg);

/*
   if (filter_live(this_object()) < 1)
      CM("whale");
*/

   if (arg) return;
   set_light(1);
   short_desc = "In the sea";
   long_desc = BS(
      "You have now entered one of the western parts of the sea. "+
      "The water is a little bit deeper here and you can see the "+
      "sun shining through the water. There are sometimes alges "+
      "swimming around. That's a good place for the whale waiting "+
      "for ships. A little sandbank is leading up.");                 
   items = ({    
      "bottom","A fine sandy sea bottom",
      "sandbank","A little sandbank, seems possible to climb",
      "water","Clear sea water",
   });
   dest_dir = ({
      PATH+"sw11", "south",
           });
}

init() {
  ::init();
    add_action("climb","climb");
  }

int climb(string str) 
{
  if (str=="up" || str=="up the sandbank" || str=="sandbank") 
  {
    write("You are climbing up the sandbank.\n");
  this_player()->
       move_player("up the sandbank#players/whisky/island/room/island25");
  return 1;
 }
 return 0;
}

