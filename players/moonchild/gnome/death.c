inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A room full of giant spikes";
  long_desc="You are in a room full of giant spikes. Death is near.\n";
  no_obvious_msg="";
  items=({ "spikes", "They will kill you" });
}

init() {
  ::init();
  call_out("kill", 1, 0);
}

kill() {
  if(this_player()->query_level() < 30) {
    write("You are crushed to death by giant spikes!\n");
    shout(this_player()->query_name() + " howls in terror as "
	+ this_player()->query_gender_string()
	+ " is torn to death by giant spikes!\n");
    this_player()->hit_player(100000);
  }
  this_player()->move_player("X#room/church");
}
