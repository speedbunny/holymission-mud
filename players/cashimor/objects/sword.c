inherit "obj/weapon";

reset(arg) {
  if(!arg) {
    set_name("sword");
    set_short("A sword");
    set_long("A sharp but otherwise normal sword.\n");
    set_class(10);
    set_value(50);
    set_weight(3);
    set_read("General purpose incorperated.");
  }
}

query_non_metal() {
  return 1;
}
