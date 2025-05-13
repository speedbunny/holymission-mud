 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

    set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
	"This side passage much smaller the main cavern.  It looks "+
	"as if something ate its way through the rock.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
          "hole","The hole is dark and steep. If you climb down you probably won't get back!",
            "floor","The floor is rough and covered with little holes",
	"rock","Looks as if acid has eaten through the rock",
            "holes","The holes are very shallow and only appear to threaten unwary ankles"});
dest_dir=({CPATH+"c24","west",CPATH+"t33","east"});

}
