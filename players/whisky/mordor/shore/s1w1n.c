
/* s1w1n.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "On a dark Shore";
        long_desc = BS(
                    SHOREDESC+" Far to the north you can see a path"+
                    " winding itself into a big mixed forest.");
        items = ITEMDESC + 
                ({ "forest","Far to the north you can see land"});
        dest_dir = ({
        _dir+"s2w1n","west",
        _dir+"s1n","east",
        _dir+"s1w","south",
        });
        
      }
}

