inherit "room/room";

reset(arg){
 if(!arg){

  set_light(1);
  short_desc = "Complete newbie area";
  long_desc = 
"I hope you have learned all you need to know about playing on Holy Mission "+
"   Now good luck, and enjoy your stay here.\n";

  property = ({ "no_tport_in", "no_tport_out", "no_steal", "no_kill" });
  dest_dir = ({"players/airborne/new/station", "out" });
	}
}

init(){
 ::init();
  add_action("out", "out");
}

int out(){
  write("You have completed your first quest.\n");
  this_player()->set_quest("total_newbie");
  this_player()->move_player("end#players/airborne/new/station");
  return 1; 
}
