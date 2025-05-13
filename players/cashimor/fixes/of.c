inherit "obj/thing";

reset(arg) {
  if(!arg) {
    set_name("object find");
    set_short("An object finder");
    set_can_get(1);
    set_weight(1);
    set_value(10);
  }
}

init() {
  ::init();
  add_action("find_it","find");
}

find_it(str) {
object obj;

  obj=find_object(str);
  write(obj);
  destruct(obj);
  str->load_5317();
  return 1;
}
