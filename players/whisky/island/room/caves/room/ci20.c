
/* ci19 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(1);
        short_desc = "The eastern orc caves";
        long_desc = BS(
        "You are sneaking through the secret orc caves. To the north "+
        "the corridor leads further where you can hear some noises "+
        "coming from. To the east there is are some tiny holes in "+
        "the cave wall, where some beams of light are beaming in. "+
        "From this holes you can hear the sound of birds and the "+
        "noise of the sea. The passage leads further to the north "+
        "and back to the south.");

        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
         "holes","You see the sandy beach and the sea, with\n"+
                 "seagulls flying over the waves and catching\n"+
                 "fish. What a pity you are on that dark place",
         "hole","You see the sandy beach and the sea, with\n"+
                 "seagulls flying over the waves and catching\n"+
                 "fish. What a pity you are on that dark place",
        });
      }
     dest_dir = 
     ({
       PATH+"ci21","north",
       PATH+"ci19","south",
     });
}
