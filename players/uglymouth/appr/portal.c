status vis;

int id(string str) {
  return str == "portal" || str == "apprentice portal";
}

void long() {
  if(vis) write("A field of green fire. Do you dare to enter it?.\n");
}

string extra_look() {
  return vis ? capitalize(environment()->query_pronoun())+" is surrounded by "
    "a field of green fire" : 0;
}

int get() {
  return 1;
}

int drop() {
  return 1;
}

string query_auto_load() {
  string als;
  als = vis ? "vis" : 0;
  return "players/uglymouth/appr/portal:" + als;
}

void init_arg(string str) {
  if(!str) vis = 0;
  else vis = 1;
}

void init() {
  if(!this_player()->query_immortal()) {
    write("You are struck by a flash of green fire.\n");
    destruct(this_object());
    return;
  }
  add_action("conjure", "conjure");
  add_action("fade", "fade");
  add_action("enter", "enter");
  add_action("phelp", "help");
}

int conjure(string str) {
  if(str != "portal") return 0;
  if(vis) {
    notify_fail("You have already conjured a portal.\n");
    return 0;
  }
  write("With a flash of green fire, you are surrounded by a magical portal.\n");
  say(this_player()->query_name() + " draws green fire from the air.\n");
  vis++;
  return 1;
}

int fade(string str) {
  if(str != "portal") return 0;
  if(!vis) {
    notify_fail("You have not conjured a portal, so it can't fade.\n");
    return 0;
  }
  write("The magical portal fades into the fabric of space.\n");
  say(this_player()->query_name() + " sends a green fire into the sky.\n");
  vis = 0;
  return 1;
}

int enter(string str) {
  if(str != "portal") return 0;
  if(!vis) {
    notify_fail("You have not conjured a portal, so you can't enter it.\n");
    return 0;
  }
  write("You step into the field of green fire.\n");
  say(this_player()->query_name() + " is consumed by a burst of green fire.\n");
  move_object(this_player(), "/players/uglymouth/appr/appr1");
  command("look", this_player());
  return 1;
}

int phelp(string str) {
  if(str != "portal") return 0;
  write("A magical portal, by Uglymouth, for you.\n\n"
    + "Here's what it does:\n"
    + "Conjure portal - Opens a portal to the apprentice area.\n"
    + "Fade portal    - Closes the portal.\n"
    + "Enter portal   - Moves you to the appr. area (must be conjured).\n"
    + "While it is conjured, you are surrounded by green flames.\n"
    + "That can be seen when peopl look at you. Have fun with it.\n");
  return 1;
}
