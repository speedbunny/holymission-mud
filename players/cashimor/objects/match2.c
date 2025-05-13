inherit "obj/torch";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("match");
    set_fuel(10);
    set_weight(1);
  }
}

light(str) {
  set_auto_light(present("matchbox",this_player()));
  return ::light(str);
}

query_value() {
  return 1;
}
