 
   /* fixed by haplo on 3-27-95 */
 
inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
   if (filter_live(this_object()) < 3)
       CM("monkey");

   if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
         "You find yourself on the beach. The sun is shining and "
        + "you get the feeling that you might stay here for longer. "
        + "To the north you see some palm-trees swaying. "
        + "and to the east you see a big black rock and you can hear "
        + "the rumbling noise of the volcano.");
    items = ({
            "rock","A big black rock",
            "trees","100 feet high palm trees",
            "palm-teees","100 feet high palm-trees"
           }); 
    dest_dir = 
        ({
        PATH+"island1", "southwest",
        PATH+"island8", "north",
        PATH+"island3", "west",
        });

}
