inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Sloping floor";
  long_desc =
"The floor slopes down into the darkness that lies below and up to the "+
"northeast.  The smell of orc sweat is apparent in this room and it is "+
"clear that many orcs have been here recently.\n";
   set_light(0);
    items = ({
      "floor","It slopes sharply down into the next level of the cavern",
  });
    dest_dir = ({
    sr+"/room510","northeast",
    sr+"/room601","south",
  });

    clone_list = ({ 
       1, 1, "monster", sm+"/orc_guard.c", 0,
       1,1, "task",sm+"/orc_taskmaster.c",0,
        });
  ::reset(arg);
    replace_program("room/room");
}

