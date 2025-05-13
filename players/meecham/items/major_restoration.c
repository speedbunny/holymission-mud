inherit "obj/treasure";

void reset(status arg) {
  set_id("potion");
  set_short("Potion of major restoration");
  set_long("This is a potion of major restoration, drink or quaff it.\n");
  set_value(0);
  set_weight(1);
}

void init() {
  ::init();
  add_action("_drink","drink");
  add_action("_drink","quaff");
}

status _drink(string str) {
  if (!str || str != "potion") return (0);
  write("You quaff a potion of major restoration.\n");
  this_player()->heal_self(500);
  say(this_player()->query_name() + " quaffs a potion of major restoration.\n");
  destruct(this_object());
  return (1);
}
