inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "An apprentice wizard's studyroom";
  long_desc = "This is an apprentice wizard's studyroom.\n"
    + "A simple wooden chair and table are all the furniture that this study\n"
    + "contains. A door leads back to the Hall of learning.\n"
    + "Type 'help study' for commands here. Peace and quiet fill this place.\n";
  dest_dir = ({
    "/players/uglymouth/guilds/hall", "out",
  });
  items = ({
    "studyroom", "A small cell, where one can study in peace",
    "chair", "A simple wooden chair",
    "table", "A simple wooden table",
    "door", "A simple wooden door",
  });
  smell = "The air is fresh.\n";
}

init() {
  ::init();
  add_action("change_it", "study");
  add_action("study_help", "help");
}

int change_it(string str) {
  string what, how;
  object towhom;
  sscanf(str, "%s %s", what, how);
  if(explode(file_name(this_object()), "#")[1] !=
    "/players/uglymouth/guilds/hall"->query_nr(this_player()->query_real_name())) {
    write("This is not your room. You can't do that here.\n");
    return 1;
  }
  switch(what) {
    case "guild":
    if("/guild/master"->query_number(how) == -1) {
      write("That guild does not exist.\n");
      return 1;
    }
      this_player()->set_guild("/guild/master"->query_number(how));
      write("You study on new knowledge.\n");
    break;
    case "health":
      if(how != "full") {
        write("Healing is meant to restore _full_ health.\n");
        return 1;
      }
      this_player()->heal_self(100000);
      write("You study new healing methods. You feel refreshed.\n");
    break;
    case "teleporting":
      if(!how || !towhom = find_player(how)) {
        write("You can not seem to locate that player.\n");
        return 1;
      }
      if(!towhom->query_immortal()) {
        write("That player does not have enough power to draw yourself to.\n");
        return 1;
      }
      if(towhom->query_newwiz() && file_name(environment(towhom)) != "players/"
        +towhom->query_real_name()+"/workroom") {
        write("That wizard is not at home. You can only teleport to workrooms.\n");
        return 1;
      }
      write("You study on teleporting and feel your surroundings change.\n");
      this_player()->move_player("X#"+file_name(environment(towhom)));
    break;
    default:
      write("You lack the knowledge to do that.\n");
    break;
  }
  return 1;
}

int study_help(string str) {
  if(str != "study") return 0;
  write("Welcome to your new studyroom.\n"
    + "This will be your workroom until you get a proper workroom of your own,\n"
    + "as a newwiz. The command 'home' will always bring you back here.\n"
    + "In this room, you can 'study' various subjects. Each of them will allow\n"
    + "you to perform a simple task.\n"
    + "'study guild <guild name>' will change your guild.\n"
    + "'study health full' will bring you back to full hp and sp.\n"
    + "'study teleporting <name of wizard>' will allow you to teleport to\n"
    + "a certain wizard. You can teleport to any other apprentice wizard,\n"
    + "or to any other wizard if (s)he is in his/her workroom. This to prevent\n"
    + "you from getting accidentally trapped somewhere.\n"
    + "Enjoy it while it lasts. Ideas and complaints can be mailed to Uglymouth.\n");
  return 1;
}
