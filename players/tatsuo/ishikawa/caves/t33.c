 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
object ob;

  reset(arg)
{
  if(arg) return;

    set_light(0);
short_desc="Lair of the Blob";
    long_desc= break_string(
	"The stench of reeking protoplasm greets you as you enter "+
	"this filthy chamber.  Decayed remains of just about anything "+
	"you can think of form a puddle on the floor.  The inhabitant "+
	"of this chamber must be something vile and wretched.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
          "hole","The hole is dark and steep. If you climb down you probably won't get back!",
            "floor","The floor is rough and covered with little holes",
            "holes","The holes are very shallow and only appear to threaten unwary ankles"});
dest_dir=({CPATH+"t32","west"});
if(!ob){
MO(CO(MAN+"blob"),TO);

}
}
