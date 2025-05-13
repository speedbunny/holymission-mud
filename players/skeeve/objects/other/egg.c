inherit "/obj/treasure";

status breaking;

reset(arg) {
  if (!arg) {
    set_id("egg");
    set_alias("golden egg");
    set_short("A golden egg");
    set_long("This egg must be laid by an extraordinary hen.\n");
    set_value(1200);
    set_weight(1);
    breaking = 0;
  }
}

init() {
  ::init();
  add_action("eat","eat");
}

eat(str) {
  if (!str || !id(str)) return 0;
  write("You can't eat a golden egg!\n");
  return 1;
}

get() {
  int g;
  g = ::get();
  if (g && !breaking) {
    call_out("des_test",0,this_player());
  }
  return g;
}

des_test(tp){
  if (!breaking && (environment(this_object()) == tp)){
    call_out("des_egg",300);
    breaking = 1;
  }
}

des_egg() {
  if (environment(this_object())->query_player())
    write("The egg broke. You should have sold it sooner.\n");
  else tell_room(environment(this_object()),
    "The egg brokes into 1000 pieces.\n");
  destruct(this_object());
}
