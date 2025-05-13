
/* s14e3n.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "On the Shore of Mordor";
        long_desc = BS(
                    SHOREDESC+
                    "Far to the south you can see the outline of a "+
                    "big island. To the northeast you can see a big "+
                    "black Rock.");
        items = ITEMDESC + 
                ({ 
                   "rock","You can see a big black rock to the north",
                   "island","Far to the south you can see the outline\n"+
                            "of a big island",
                });
        dest_dir = ({
        _dir+"s14e4n","north",
        _dir+"s13e3n","west",
        _dir+"s15e4n","northeast",
        _dir+"s13e2n","southwest",
        });
        
      }
}

