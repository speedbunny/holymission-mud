
/* dragon_hole */

inherit "/room/room";
#include "../garden.h"

void reset(int flag)
{
     ::reset(flag);
       if (!present("dragon",this_object()))
       {
          move_object(clone_object(MONST+"/dragon"),this_object());
       }
       if (flag == 0)
       {
        set_light(1);
        short_desc = "A big hole in the Garden";
        long_desc = BS(
       "You are in a big hole under the garden. The walls are "+
        "covered with brown earth and it is really damp here. "+
        "On the bottom you can see many human bones. It smells "+
        "awful here.");
        items = ({
        "hole","You are in a big wet hole",
        "walls","They are earthy and wet",
        "bottom","You can see a lot of white human bones",
        "bones","Ihhh how digusting !" });
        dest_dir = ({
        ROOM+"/garden4","up" });
      }
}


      
