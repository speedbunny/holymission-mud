inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A descending stairwell";
  long_desc =
"Along the eastern wall of the room a stairwell descends into the darkness. "+
"Rubble lies all around the northern wall as if someone was trying to carve "+
"a new passage.  The northern wall itself is covered with ding marks and "+
"scratches.\n";
  set_light(0);
  dest_dir = ({
    sr+"/room213","southwest",
    sr+"/room301","down",
  });
 items = ({
    "rubble",
    "Huge rocks piled in front of the stairwell",
    "stairwell",
    "granite stairs that have been moulded into shape",
    "rocks",
    "Small rocks that cover the floor",
     });
    clone_list = ({ 1, 3, "monster", sm+"/goblin.c", 0 });   
    ::reset(arg);
    replace_program("room/room");
}
