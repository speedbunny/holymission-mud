/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(0);
  short_desc = "Stone table";
  long_desc =  "In the tunnel into the mines.\n" +
	 "There is a big stone table here.\n";
  items = ({ "table", "You see nothing special about it",
	"stone table", "You see nothing special about it" }); 
  dest_dir = ({ "room/mine/tunnel4", "south",
	 "room/mine/tunnel_room", "north" }); 

replace_program("room/room");
}
