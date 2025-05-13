inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
reset (arg) {
if (arg) return;

set_light(1);
   short_desc="Midway up the mountain";
long_desc=break_string(
	"You are nearly at the top of the mountain.  The gentle breeze "+
	"and setting sun give this place a pleasant atmosphere.  The "+
	"path leads north over the final crest.  You can make you way "+
	"down a steep slope following the path down.\n",65);
  dest_dir=({
       "/players/tatsuo/guild/grove/grove","grove",
        "/players/tatsuo/ishikawa/m4","down",
       "/players/tatsuo/ishikawa/m6","up",
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
