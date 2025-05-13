
/* s15e4n.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "Next to a Rock";
        long_desc = BS(
                    SHOREDESC+
                    "Far to the south you can see the outline of a "+
                    "big island. Next to you is a big black Rock "+
                    "blocking your way to the north.");
        items = ITEMDESC + 
                ({ 
                   "rock","Next to you is a big black rock, too steep to climb",
                   "island","Far to the south you can see the outline\n"+
                            "of a big island",
                });
        dest_dir = ({
        _dir+"s14e4n","west",
        _dir+"s14e3n","southwest",
        });
        
      }
}

