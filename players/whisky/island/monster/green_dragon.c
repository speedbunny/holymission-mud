inherit "/players/whisky/obj/std_dragon";
#include "../island.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       set_colour("green");
       set_age(2+random(7));
       move_object(clone_object(OBJ+"green_star"),this_object());
     }
 }
