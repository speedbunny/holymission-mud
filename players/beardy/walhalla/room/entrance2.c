inherit"room/room";
#include "/players/beardy/walhalla/walhalla.h"


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

    dest_dir =({"/players/beardy/walhalla/room/floor1","northwest",
                "/players/beardy/walhalla/room/entrance","west",
                "/players/beardy/walhalla/room/floor7","north"});

    CM("entguard");

    smell = "This place smells divine";
  }
}
