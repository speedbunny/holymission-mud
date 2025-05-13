inherit"room/room";
#include "../walhalla.h"

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Court Yard",
    long_desc="This is Walhalla's court Yard. You are in the north of the\n" +
              "main place. Here Lord Sif, the god of law and justice, is waiting\n" +
              "for you to send you to prison, because you killed a newbie monster.\n";
    
    property =({"no_teleport","no_hide"});

    dest_dir =({ROOM + "hall3","south"});

     CM("sif");
  }
}

void init()
{  add_action("mykill","kill");
   add_action("mykill","cast");
   ::init();
}

int mykill(string arg)
{ tell_room(TO,"Lord Sif rings a bell and three guard arrive \n" +
               "from the south.\n");
  CM("cguard");
  CM("cguard");
  CM("cguard");
  return 1;
}
