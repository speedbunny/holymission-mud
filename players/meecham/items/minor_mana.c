inherit "obj/treasure";

void reset(status arg) {
  set_id("potion");
  set_short("Potion of minor mana");
  set_long("This is a potion of minor mana, drink or quaff it.\n");
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
  write("You quaff a potion of minor mana.\n");
  this_player()->restore_spell_points(200);
  say(this_player()->query_name() + " quaffs a potion of minor mana.\n");
  destruct(this_object());
  return (1);
}
