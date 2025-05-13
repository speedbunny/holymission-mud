
/* s1e.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "On a dark Shore";
        long_desc = BS(
                    SHOREDESC+" far to the south you can see the outline "+
                    "of a big island.");
        items = ITEMDESC + 
                ({ "island","Far to the south you can see land"});
        dest_dir = ({
        _dir+"s2e","east",
        _dir+"s00","west",
        _dir+"s1e1n","north",
        });
        
      }
}

