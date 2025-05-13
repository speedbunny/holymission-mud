
/* s4w1n.c */

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
        _dir+"s3w","southeast",
        _dir+"s5w2n","northwest",
        _dir+"s3w1n","east",
        _dir+"s4w2n","north",
        });
        
      }
}

