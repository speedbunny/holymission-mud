inherit"room/room";
#include "../walhalla.h"

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Floor One",
    long_desc="This is the first floor of Walhalla. The walls are much more dirtier\n" +
              "up here than the floor below. Although the strange fog is gone you\n" +
              "no good feeling about staying here. You see a pit in the south. If \n" +
              "want to go down, take this chance.\n";
    
    items=({"walls","As you found out, they are more dirtier than them below"});

    property =({"no_teleport","no_sneak"});

    dest_dir =({ROOM + "first2","southeast"});

    smell = "It smells awful up here";
  }
}


init()
{ add_action("south","south");
  ::init();
}

south()
{ write("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOAAAAAAAAAAAAAAAAAAAAAA\n" +
        "You jumped down from the first floor...\n");

  transfer(TP,ROOM +"floor9");
  return 1;
}

