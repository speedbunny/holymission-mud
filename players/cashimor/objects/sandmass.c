inherit "obj/thing";
#define CN "players/cashimor/room/chimney"
#define TN "room/forest9"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("sand");
    set_alias("spot");
    set_short("A spot of sand");
    set_long("This is a rather large area of sand.\n");
    set_can_get(0);
    move_object(this_object(),TN);
    CN->set_dest_dir(TN);
  }
}

long(str) {
  ::long(str);
  if(!CN->query_full()) {
    write("There is a hole leading down dug in the middle.\n");
  }
}

init() {
  ::init();
  add_action("dig_it","dig");
  add_action("down_it","down");
}

dig_it(str) {
  if((!str)||(str!="down")) {
    notify_fail("Dig where?\n");
    return 0;
  }

  if(CN->subtract_sand()) {
    notify_fail("There is almost no sand left.\n");
    return 0;
  }
  write("You dig a hole in the sand.\n");
  say(this_player()->query_name()+" digs a hole in the sand.\n");
tell_room(environment(this_object()),"The spot of sand grows larger.\n");
  return 1;
}

down_it() {
  if(CN->query_full()) {
    notify_fail("There is too much sand there!\n");
    return 0;
  }
  this_player()->move_player("down#"+CN);
  return 1;
}
