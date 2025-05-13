inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("potion");
  set_alias("blue potion");
  set_value(500);
  set_weight(1);
  set_short("A blue potion");
  set_long("A blue potion. Looks like you could drink it.\n");
  set_read("It says: For healing purposes only.\n");
}

init() { ::init(); add_action("drink", "drink"); }

drink(str) {
  if(!id(str)) return 0;
  write("You drink the potion and feel healed. The bottle crumbles to dust.\n");
  say(this_player()->query_name() + " drinks a potion.\n");
  this_player()->heal_self(75+random(51));
  destruct(this_object());
  return 1;
}
