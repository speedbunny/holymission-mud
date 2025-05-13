inherit "obj/torch";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("match");
    set_auto_light(1);
    set_fuel(10);
    set_weight(1);
  }
}

query_value() {
  return 1;
}
