inherit "players/cashimor/inherit/sand";

reset(arg) {
object chest;

  ::reset(arg);
  if(!arg) {
    short_desc="Bedroom";
    long_desc="This looks like a bedroom. A structure spans the\n"
            + "southern wall.\n";
    items=({"structure","It resembles a bed",
            "wall","Perhaps made of sandstone"});
    dest_dir=({"players/cashimor/room/livingroom","west"});
    if(!present("chest",this_object())) {
      chest=clone_object("players/cashimor/objects/chest");
      move_object(chest,this_object());
    }
  }
}

init() {
  ::init();
  add_action("enter_it","enter");
  add_action("sleep_here","sleep");
  add_action("break_it","break");
  add_action("break_it","push");
}

enter_it(str) {
  if(!str) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if((str!="structure")&&(str!="bed")) {
    notify_fail("Enter what?\n");
    return 0;
  }
  write("You really don't want to do that. It seems it could collapse any\n"
      + "second.\n");
  say(this_player()->query_name()+" decides not to enter the structure.\n");
  return 1;
}

sleep_here() {
  write("You fall asleep.\n");
  say(this_player()->query_name()+" falls asleep.\n");
  input_to("sleeping");
  write("> ");
  return 1;
}

sleeping(str) {
  if((str=="wake")||(str=="wake up")||(str=="awake")||(str=="get up")) {
    write("You wake up!\n");
    say(this_player()->query_name()+" wakes up from a deep sleep.\n");
    return 1;
  }
  write("You can't do that while you're sleeping!\n");
  say(this_player()->query_name()+" snores.\n");
  write("> ");
  input_to("sleeping");
}

break_it(str) {
  if((!str)||(str!="wall")) {
    notify_fail("Break/push what?\n");
    return 0;
  }
  write("Though it seems rather weak, it won't bulge.\n");
    say(this_player()->query_name()+" fails to destroy the wall.\n");
  return 1;
}
