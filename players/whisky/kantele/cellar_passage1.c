
/* cellar_passage1 */

inherit "/room/room";
#include "defs.h"


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        short_desc = "In a dark passage";
        long_desc = BS(
        "You are standing in a narrow dark passage leading to "+
        "the north and south. Wet drops of stinging water are "+
        "driping from the ruined walls.");

        dest_dir =
        ({ 
           PATH+"cellar_passage","south",
           PATH+"cellar_passage2","north",
        });
     }
}
 
