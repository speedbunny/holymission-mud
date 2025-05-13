inherit"room/room";
#include "../walhalla.h"

int i;

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(0);
    short_desc="Catacombs",
    long_desc="You are in the ancient Catacombs. The walls look very\n" +
              "strange and old. Everything is covered with dust and\n" +
              "blood. Strange noise is heard too. Oh, you feel ugly\n" +
              "down here.\n";

    items=({"walls","There seems to be a trapdoor",
           "wall","There seems to be a trapdoor",
            "dust","It's normal dust"});

    property =({"no_teleport"});

    dest_dir =({ROOM + "cat3","west",
                ROOM + "cat5","south"});

    smell = "Oh god ! It smells ugly in here";

    for(i=0;i<=3;i++)
      CM("catamon");

  }
}

init()
{ add_action("open","open");
  ::init();
}


open(str)
{ if(!str) return 0;

  if(str=="trapdoor")
  { write("You open the trapdoor and enter it.\n");
    transfer(TP, ROOM +"cat6");
    return 1;
  }
  else 
   return 0;
}
