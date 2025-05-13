inherit "/obj/treasure";
 
object obj;
int i;
 
reset(arg) {
if (arg) return;
 set_alias("key");
 set_short("A magical key");
 set_long("A magical key made of crystal.\n");
 set_value(1000);
 set_weight(1);
}
 
init() {
  add_action("magic","wave");
}
 
magic(str) {
  if(!id(str)) return;
  write("You wave the key into the air.\n");
  say(this_player()->query_name()+" waves the key in the air.\n");
  call_other(environment(this_player()),"open");
  return 1;
}
