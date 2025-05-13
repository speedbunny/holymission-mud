inherit "players/cashimor/inherit/sand";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="The trapdoor";
    long_desc="You are hanging in a sandy up/down tunnel. There is a trapdoor\n"
            + "above you, and below you is an empty corridor.\n";
    dest_dir=({"players/cashimor/room/inside","up",
               "players/cashimor/room/corridor","down"});
    items=({"trapdoor","It opens and closes automagically",
            "tunnel","It is old, but not as old as the corridor",
            "corridor","Yes, it would be safer to stand on the floor"});
  }
}

init() {
  ::init();
  add_action("open_it","open");
  add_action("open_it","close");
  add_action("enter_it","enter");
}

open_it(str) {
  if((!str)||(str!="trapdoor")) {
    notify_fail("Open or close what?\n");
    return 0;
  }
  notify_fail("The trapdoor opens and closes automagically.\n");
  return 0;
}

enter_it(str) {
  if((!str)||(str!="trapdoor")) {
    notify_fail("Enter what?\n");
    return 0;
  }
  this_player()->move_player("up#players/cashimor/room/inside");
  return 1;
}
