inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
reset (arg) {
if (arg) return;

set_light(1);
   short_desc="Midway up the mountain";
long_desc=break_string(
	"You are following a mountain path that twists through "+
	"the tangle of plants and vines that make their home "+
	"on this island. The path continues down and slopes upward to "+
	"the southeast.\n",65);
  dest_dir=({
	MPATH+"m3","southeast",
	IPATH+"jung112","down",
   });
   items=({
      "mountain","A barely climbable mountain",
	"path","A well travelled path, you wonder who uses it",
   });
}
   init(){
   ::init();
    add_action("_climb","climb");
}
 _climb(str){
   if(!str){
    notify_fail("Climb what ?\n");
    return 0;
}
   if(str =="mountain"||str=="towering mountain"||str=="up"){
   MOVE("up#players/tatsuo/ishikawa/m3");
   return 1;
}
   if(str =="down"){
   write("You climb down the mountain carefully.\n");
     MOVE("down#players/tatsuo/ishikawa/jungle/jung112");
  return 1;
}
}
