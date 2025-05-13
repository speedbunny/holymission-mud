inherit "room/room";

reset(arg) {
object box;

  ::reset(arg);
  if(!arg) {
    short_desc="In Ianthe's hideout";
    long_desc="You are in a roughly hewn but beautifully designed room,\n"
            + "clearly made for a princess. The walls were once covered with\n"
            + "tapestries, but they have turned to rags. There is a trapdoor\n"
            + "in the floor.\n";
    smell="The air is very old and terrible.";
    dest_dir=({"","down"});
    items=({"room","It used to be very nice",
            "walls","They are made of solid stone",
            "tapestries","You recognize a dragon on them",
            "roof","It's solid too",
            "rags","You feel very sorry that such art has vanished",
            "trapdoor","It opens and closes automagically"});
  }
  if(!present("box",this_object())) {
    box=clone_object("players/cashimor/things/box");
    move_object(box,this_object());
  }
}

init() {
  ::init();
  add_action("down_it","down");
  add_action("open_it","open");
  add_action("open_it","close");
  add_action("enter_it","enter");
  add_action("dig_it","dig");
  add_action("take_it","get");
  add_action("take_it","take");
}

take_it(str) {
  if(!str) {
    notify_fail("Take what?\n");
    return 0;
  }
  if(str!="box") return 0;
  if("players/cashimor/room/trapdoor"->query_full()) return 0;
  while(!"players/cashimor/room/trapdoor"->add_sand());
  tell_room(this_object(),"Something collapses below the trapdoor...\n");
  return 0;
}

open_it(str) {
  if((!str)||(str!="trapdoor")) {
    notify_fail("Open or close what?\n");
    return 0;
  }
  write("The trapdoor opens and closes automagically.\n");
  return 1;
}

enter_it(str) {
  if((!str)||(str!="trapdoor")) {
    notify_fail("Enter what?\n");
    return 0;
  }
  return down_it();
}

down_it(str) {
  if("players/cashimor/room/trapdoor"->query_full()) {
    notify_fail("There is too much sand in that direction!\n");
    return 0;
  }
  this_player()->move_player("down#players/cashimor/room/trapdoor");
  return 1;
}

dig_it(str) {
  if((!str)||(str!="down")) {
    notify_fail("Dig where?\n");
    return 0;
  }
  notify_fail("The trapdoor prevents your digging.\n");
  return 0;
}

roof_walk() {
  tell_room(this_object(),"Something is walking on the roof.\n");
}

subtract_sand() {
  return 1;
}
