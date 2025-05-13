inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    set_light(1);
    short_desc = "Hot/Cold Path";
    long_desc =
    "As you walk along this path, you can feel\n"+
    "cold air coming from the west and hot air\n"+
    "flowing from the east.\n";

    dest_dir = ({
      TCOLD + "cold_path","west",
      THOT + "hot_path","east",
      TPATH + "path5","south",
      TPATH + "path6","north",
    });

    ::reset(arg);
    replace_program("room/room");
}
