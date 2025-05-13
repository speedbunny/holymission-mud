inherit "/obj/treasure";

reset(arg) {
  if (!arg) {
    set_id("fillet");
    set_name("fillet");
    set_alias("fillet");
    set_long("A pice of " + name + "\n");
    set_weight(1);
   set_value(0);
  } else {
    if (!environment(environment(this_object()))) 
      destruct(this_object());
} }

init() {
    add_action("eat", "eat");
}

eat (str) {
  if(!str || !id(str)) return 0;
  write("You cannot eat a raw " + short() +"\n"
       +"You must make a fishsoup to eat it.\n");
  return 1;
}
