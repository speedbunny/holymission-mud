// moonchild 120893 fixed game-crashing bug involving interactive(0)

inherit "room/room";

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The void";
        long_desc=
  "The void.\n"+
  "You come to the void if you fall out of a room, and have nowhere to go.\n"+
  "\nYou are transferred to the church...\n"+
  "@@leave_here";
	no_obvious_msg="";
    }
}

leave_here() {
  if(present(this_player())) this_player()->move_player("X#room/church");
  return "";
}

clean_room(arg) {
  int i;
  object *ob;
  if(!arg && (find_call_out("clean_room")==-1)) {
    call_out("clean_room",10,1);
    return;
  }
  ob=deep_inventory(this_object());
  for(i=0;i<sizeof(ob);i++) if (ob[i] && !(interactive(ob[i]))) destruct(ob[i]);
  return;
}
