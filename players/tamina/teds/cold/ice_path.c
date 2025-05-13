inherit "room/room";
#include "/players/tamina/defs.h"
void reset(int arg) 
{
  short_desc = "Frozen Path";
  long_desc =
"Snow and ice cover the hills and forests to\n"+
"either side of the path. To the north is deep\n"+
"snow covered forest, while to the south can be\n"+
"seen a snow covered stream. To the west lies a\n"+
"mountain of ice.\n";

    dest_dir = ({
  TCOLD + "frozen_forest", "north",
  TCOLD + "ice_south", "south",
  TCOLD + "ice_path2", "west",
  TCOLD + "cold_path2", "east"
    });

    ::reset(arg);
    replace_program("room/room");
}
