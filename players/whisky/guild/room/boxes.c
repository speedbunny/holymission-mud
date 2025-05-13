
inherit "/players/whisky/obj/std_boxes";
#include "../guild.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag==0)
     {
       set_light(1);
       short_desc = "The box chamber";
       long_desc = BS(
       "You have entered a small dusty room. There is a counter "+
       "and a big wooden shelf fixed to the wall. Inside the "+
       "shelf you can see a lot of boxes and 'Sleepy' the monk "+
       "counting and cleaning the items stored in the boxes. "+
       "There is a iron sign hanging on the wall.");
    
       items =
       ({
          "bottom","You see an oak wooden bottom",
          "wall","The walls are made of red bricks",
          "walls","The walls are made of red bricks",
          "shelf","The shelf is full with boxes",
          "boxes","The boxes are to store items",
          "sleepy","He is counting and cleaning the items in the boxes",
          "iron sign","There is something written on it",
          "sign","There is something written on it"
       });
       dest_dir =
       ({
         "/players/whisky/guild/room/bar","south" });
        clerk = "Sleepy";
        save_file = "/players/whisky/guild/room/boxes";
        cost = 1000; /* per week */
        ::check_boxes();
    property = ({"no_teleport"});
      }
 }
      
init()
{
  ::init();
}
