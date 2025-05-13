inherit"room/room";
#include "../walhalla.h"

reset(arg)
{ if(!arg)
  { set_light(1);
    short_desc="Entrance of Walhalla",
    long_desc="This is the entrance of Walhalla, the big old\n" + 
               "castle of the Germaic gods. You are in the floor\n" +
               "of it. Pictures of the several gods are fixed to\n" +
               "the wall.\n";

    
    items=({"entrance","It has got really huge doors",
            "pictures","Argh ! What an awful style",
            "floor","It's a bit dusty"});

    property =({"no_sneak","no_teleport","no_hide"});

    dest_dir =({"/players/beardy/valhalla/room/entrance-1","south",
                "/players/beardy/walhalla/room/entrance2","east",
                "/players/beardy/walhalla/room/floor7","northeast",
                "/players/beardy/walhalla/room/floor1","north"});

    smell = "This place smells divine";
   CM("entguard");
   CM("entguard");
   CO("entsign");
  }
}
