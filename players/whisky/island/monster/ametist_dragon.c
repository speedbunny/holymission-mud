inherit "/players/whisky/obj/std_dragon";
#include "../island.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       set_colour("ametist");
       set_age(6);
     }
 }
