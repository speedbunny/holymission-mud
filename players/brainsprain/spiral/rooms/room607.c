inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "The orc prison";
  long_desc =
"Iron bars line the eastern wall.  Several skeletons lie behind the "+
"bars.  An old, wooden chair leans against the western wall.  A ring "+
"hangs from a peg that is nailed into the wall.  A spiderweb covers "+
"the wall.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room606","southwest",
    sr+"/room608","north",
  });
  items =({
    "peg",
    "A thick peg from which a key ring hangs",
    "ring",
    "An old key ring",
    "spiderweb",
    "An intricate web created by a masive black spider",
    "bars",
    "Iron bars forming a prison",
    "skeletons",
    "the bones of orcs",
    "chair",
    "a wooden chair covered in dust and spiderwebs",
  });
    clone_list = ({ 
       1, 2, "monster", sm+"/orc_guard.c", 0,
        });
  ::reset(arg);
    replace_program("room/room");
}
