inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
reset(arg){
if(arg) return 1;
set_light(1);
short_desc="Village Hut";
long_desc=break_string(
     "This is a one room hut. It is small and the only furnishings appear to be "+
     "a straw matt and a table with worn cusshions. You can feel a breeze drifting "+
     "through the hut.\n",65);


items = ({
   "mat","It is a small sleeping mat made of straw",
   "table","The table is low to the ground and looks very old. It appears to be made of teak",
    "teak","It is wood",
    "straw","It is used to make mats. Do we have to tell you everything?",
    "cushions","They are worn but look comfortable"
	});
property=({
	});
dest_dir=({
     CPATH+"vill1","out"
   });
}
