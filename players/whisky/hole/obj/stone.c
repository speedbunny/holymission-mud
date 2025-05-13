inherit "obj/treasure";
int counter;

reset (arg) {
  if (!arg) {
    set_id("diamond");
    set_alias("black diamond");
    set_short("A black diamond");
    set_long("A strange stone with some healing power, just type <heal>\n");
  }
}

init() { add_action("heal","heal"); }

heal() {
  this_player()->heal_self(100);
  counter++;
  write("You are healed.\n");
  say(this_player()->query_name()+" is healed by the power of "+this_player()->query_name()+"'s diamond.\n");
  if (counter == 3) {
     write("Your diamond crumbles to dust.\n"),
     say(this_player()->query_name()+"'s diamond crumbles to dust.\n");
     destruct(this_object());
  }
  return 1;
}
