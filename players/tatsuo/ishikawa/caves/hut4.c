inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
reset(arg){
if(arg) return 1;
set_light(1);
short_desc="Village Hut";
long_desc=break_string(
      "This hut is larger than the rest with a room to the north. You can see the "+
      "decorations are better and that the cushions in this room are made of fine "+
      "silk. You can see several carvings hanging on the wall. There is a gentle "+
      "breeze drifting through the hut.\n",65);


items = ({
   "mat","It is a small sleeping mat made of straw",
   "table","The table is low to the ground and looks very old. It appears to be made of teak",
    "teak","It is wood",
    "straw","It is used to make mats. Do we have to tell you everything?",
    "cushions","They are worn but look comfortable",
      "silk","It is an oriental fabric",
    "carvings","They are of mighty samurai warriors"
	});
property=({
   "no_teleport"
	});
dest_dir=({
     CPATH+"vill4","out",
     CPATH+"hut5","north"
   });
}
