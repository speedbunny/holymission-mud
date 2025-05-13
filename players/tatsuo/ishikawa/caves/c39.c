 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

    set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
     "The tunnel is sloping downwards leading you deeper into "+
     "the heart of the mountain. You can see the grooves still "+
     "cut into the floor.\n",65);
  items=({"walls","The walls are dark grey and appear to be made of granite.",
     "floor","The floor is covered with deep grooves.",
        "grooves","Do you really want to know what made them?"});

dest_dir=({CPATH+"c40","west",CPATH+"c38","east"});
}
