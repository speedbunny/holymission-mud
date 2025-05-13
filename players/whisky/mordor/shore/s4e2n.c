
/* s4e2n.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "In the Cove of Mordor";
        long_desc = BS(
                    SHOREDESC+" The Cove continues to the south. ");
        items = ITEMDESC + 
                ({ 
                   "cove","The big dark cove of Mordor",});
        dest_dir = ({
        _dir+"s5e1n","southeast",
        _dir+"s3e1n","southwest",
        _dir+"s3e2n","west",
        _dir+"s5e2n","east",
        });
        
      }
}

