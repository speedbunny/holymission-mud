#define HP this_player()->query_hp()
#define MHP this_player()->query_max_hp()

inherit "obj/treasure";

void reset(status arg) {
  set_id("potion");
  set_short("Potion of major healing");
  set_long("This is a potion of mnajor healing, drink or quaff it.\n");
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
  write("You quaff a potion of major healing.\n");
  this_player()->reduce_hit_point(-500);
  if (HP > MHP)
    this_player()->reduce_hit_point(HP - MHP);
  say(this_player()->query_name() + " quaffs a potion of major healing.\n");
  destruct(this_object());
  return (1);
}
