inherit "obj/treasure";

string colour;

reset(arg) {
  ::reset(arg);
  if(arg)
    return;
  colour=random(2) ? "orange" : "yellow";
  set_id(colour + " rubber duckie");
  set_alias("duckie");
  set_alt_name("duck");
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
  tell_room(environment(this_player()), short() + " says: Quack!\n");
  return 1;
}
