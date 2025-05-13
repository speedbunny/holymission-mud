/* 12.15.93 Airborne: changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(0);
  short_desc = "A tunnel in the mountain";
  long_desc =
	"You are in a tunnel deep in the mountain. You can see a red\n"+
	"glow far away. A sign on the door says: 'If the door is\n"+
	"locked, just knock.'\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/mountain", "south",
         "players/topaz/angmar/fairyland/dragonroom", "north" });
}
init(){
 ::init();
   add_action("knock", "knock");
}
knock() {
  write("Ok.\n");
  say(this_player()->query_name(0)+" knocks on the door.\n");
  call_other("players/topaz/angmar/fairyland/mountain", "opendoors", 0);
  return 1;
}
