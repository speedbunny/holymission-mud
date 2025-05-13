/* 12.11.93 Airborne: Changed to use room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc =  "Top of stairs";
  long_desc = 
	"You are at the top of a long staircase going down into the lower\n" 
    	"regions of the castle.\n";
  dest_dir = ({ "players/topaz/angmar/inside","north",
    	"players/topaz/angmar/midstairs","down" });
  
replace_program("room/room");
}
