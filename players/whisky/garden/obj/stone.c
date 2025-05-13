inherit "obj/treasure";
int counter;

reset (arg) {
  if (!arg) {
    set_id("saphire");
    set_alias("green saphire");
    set_short("A green saphire");
    set_long("A strange stone with\n"+
             "healing powers.\n");
    set_value(300);
  }
}

init() { add_action("heal","heal"); }

heal() {
  if (this_player()->query_frog()) {
    this_player()->heal_self(80);
    counter++;
    write("You are somewhat healed.\n");
    if (counter == 6) {
      write("Your saphire crumbles to dust.\n"),
      say(this_player()->query_name()+"'s saphire crumbles to dust.\n");
      destruct(this_object());
      return 1;
    }
  return 1;
}
  else {
  write("Only frogs can use that stone.\n");
  return 1;
  }
 }
