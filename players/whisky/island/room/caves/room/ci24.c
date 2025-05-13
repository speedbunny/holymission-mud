
/* ci24 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 3)
     {
         CM("warrior");
         CM("guard");
     }
     if (flag == 0)
     {
        set_light(1);
        short_desc = "The eastern orc caves";
        long_desc = BS(
        "You are sneaking through the secret orc caves. "+
        "To the east there is are some tiny holes in "+
        "the cave wall, where some beams of light are beaming in. "+
        "From this holes you can hear the sound of birds and the "+
        "noise of the sea. The passage leads further to the north "+
        "and back to the south. To the east there is are 'small steps' "+
        "leading out to some cliffs. On the other side to the north, "+
        "there is a big 'wooden stairway' leading up where you can hear "+
        "grunting voices, but somehow sounding like baby noice coming "+
        "from.");

        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "steps","Small stone steps",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
         "stairway","You see a small wooden stairway leading down",
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
       PATH+"ci22","south",
       PATH+"ci25","up",
       "/players/whisky/island/room/castle/p1","down",
     });
}
