inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("seeds");
  set_short("Some seeds");
  set_long("These are some plant seeds. Maybe you could plant them.\n");
  set_value(25);
  set_weight(1);
}

init() { add_action("plant", "plant"); }

plant(str) {
  int loop;
  if(!id(str)) return;
  write("You plant the seeds.\n");
  say(this_player()->query_name() + " plants some seeds.\n");
  move_object(clone_object("players/moonchild/gnome/shop/stalk"),
	environment(this_player()));
  destruct(this_object());
  return 1;
}
