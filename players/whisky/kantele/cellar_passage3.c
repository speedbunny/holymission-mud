

/* cellar_passage3 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        short_desc = "The dark end of the passage";
        long_desc = BS(
        "You are standing at the dark end of the narrow passage. "+
        "You are blocked by a huge stonewall. In one of the corners "+
        "you see some human bones.");

        items = 
        ({
           "stonewall","A big stonewall, no way to pass",
           "corner","Just a corner where some human bones are lying around",
           "bones","Nothing of interest, just bones",
        });
         
        dest_dir =
        ({
           PATH+"cellar_passage2","south",
        });
    }
}


