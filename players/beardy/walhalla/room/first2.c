inherit"room/room";
#include "../walhalla.h"

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Floor One",
    long_desc="This is the first floor of Walhalla. The walls are much more dirtier\n" +
              "up here than the floor below. Although the strange fog is gone you\n" +
              "no good feeling about staying here.\n";
    
    items=({"walls","As you found out, they are more dirtier than them below"});

    property =({"no_teleport","no_sneak"});

    dest_dir =({ROOM + "first1","east",
                ROOM + "first3","northwest"});

    smell = "It smells awful up here";
  }
}
