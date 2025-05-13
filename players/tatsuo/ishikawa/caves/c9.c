 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

    set_light(1);
short_desc="Cave of the Serpent";
    long_desc= break_string(
  "You are following a path around an immense stalagmite rising to your east. "+
  "There is a dark and eerie looking tunnel leading off southwest from the path. "+
  "The path continues on around the stalagmite.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
"stalagmite","you can see an immense stalagmite rising to your east"});
  "tunnel","The tunnels look dark and forbidding.",

dest_dir=({CPATH+"c18","north",CPATH+"c8","southeast",CPATH+"c38","southwest"});
}
