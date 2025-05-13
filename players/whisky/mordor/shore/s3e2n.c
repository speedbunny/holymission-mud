
/* s3e2n.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "On a dark Shore";
        long_desc = BS(
                    SHOREDESC+" Far to the north you can see a small path "+
                    "winding itself towards a large mixed forest.");
        items = ITEMDESC + 
                ({ "path","Far to the north you can see a small, dark path",
                   "forst","A large mixed forest, most you can see are big\n"+
                           "strong stemed oaks"});
        dest_dir = ({
        _dir+"s4e2n","east",
        _dir+"s3e1n","south",
        });
        
      }
}

