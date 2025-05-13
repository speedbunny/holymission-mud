inherit "room/room";
#include "../valhalla.h"

reset(int arg)
{ ::reset(arg);

  if(arg) return 0;

  set_light(1);
  short_desc="Before old Valhalla.",
  long_desc="Before old Valhalla.\n"+
	"	You are standing before the hidden part of Valhalla therefore\n"+
	"it is called Walhalla. To the north you see the entrance of it.\n";

  dest_dir=({ ROOM + "tunnel008","down",
	"/players/beardy/walhalla/room/entrance","north",
        });

  smell="It smells normal in here - Baeh !";
}
