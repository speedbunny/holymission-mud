inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Sloping floor";
  long_desc =
"The floor here is sloped.  In fact the angle is so steep you are "+
"having problems walking upright.  Along the northwestern wall a "+
"small ledge extrudes from the wall about three feet of off the ground.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room510","southwest",
    sr+"/room508","east",
  });
  items =({
    "ledge",
    "This appears to be a crude, stone railing",
 });
    clone_list = ({ 
       1, 2, "monster", sm+"/orc_guard.c", 0,
        });
  ::reset(arg);
    replace_program("room/room");
}
