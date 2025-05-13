inherit "obj/treasure";

string color;

reset(arg) {
  ::reset(arg);
  if(arg)
    return;
  color=random(2) ? "dark grey" : "light grey";
  set_id(color + " penguin");
  set_alias("penguin");
  set_alt_name("penguin");
  set_short(capitalize(query_name()));
  set_long(short() + ".\nYou could squeeze it.\n");
  set_value(25);
}

init() {
  ::init();
  add_action("squeeze", "squeeze");
}

squeeze(str) {
  if(!id(str))
    return;
  write("You squeeze the " + lower_case(short()) + ".\n");
  say(this_player()->query_name() + " squeezes the " + lower_case(short()) + ".\n");
  tell_room(environment(this_player()), short() + " says: Honk! Honk!\n");
  return 1;
}
