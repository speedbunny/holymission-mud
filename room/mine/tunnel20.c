/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(0);
  short_desc =  "New tunnel linked";
  long_desc = 
  	"This use to be a dead end, but now a tunnel has been dug here.\n";
  dest_dir = ({ "room/mine/tunnel21", "east",
         "players/moonchild/cave/link","west" });

replace_program("room/room");
}
