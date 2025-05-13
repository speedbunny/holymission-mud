inherit "/room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  property = "no_teleport";
  short_desc = "The Abyss";
  long_desc =
    "    You are floating in Matt's personal Abyss, where he sends\n" +
    "/players he doesn't like very much. Feel lucky he only sent you\n" +
    "here; he could have done much worse.\n";
  no_obvious_msg = "    There is no way out.\n";
}

init() {
  ::init();
  add_action("shyah", "quit");
  add_action("shyah", "shout");
  add_action("shyah", "tell");
  add_action("shyah", "mt");
  add_action("shyah", "race");
  add_action("shyah", "who");
  add_action("shyah", "monk");
  add_action("shyah", "fighters");
  add_action("shyah", "jedi");
  add_action("shyah", "mage");
  add_action("shyah", "ninja");
  add_action("shyah", "rwhere");
}

shyah() {
  write("You can't do that, you're in the Abyss!\n");
  return 1;
}

free(arg) {
  object target;
  target = find_player(arg);
  if(present(arg, this_object())) {
    write("You free " + target->query_name() + ".\n");
    tell_object(target, "\nYou have been freed.\n\n");
    move_object(target, "/room/church");
    say(target->query_name() + " is freed.\n");
    return 1;
  }
}
