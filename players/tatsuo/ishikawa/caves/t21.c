 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

   set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
	            "This small chamber is very hot.  The granite walls are smooth "+
	        "with the exception of a few words engraved into the rock. "+
	            "A large hole leads up to the next level of the caverns, "+
		       "while a large passage leads to the north.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
            "floor","The floor is rough and covered with little holes",
		      "words","Untold dangers lie ahead!",
	          "engraving","Untold dangers lie ahead!",
            "holes","The holes are very shallow and only appear to threaten unwary ankles"});

dest_dir=({CPATH+"t22","north",CPATH+"t12","up"});
property=({"no_teleport","no_sneak"});
}
init(){
::init();
AA("_read","read");
}
_read(str){
if (str=="words" || str=="engraving"){
write("Untold dangers lie ahead!\n");
return 1;
}
}
