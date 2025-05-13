inherit "obj/armour";

reset (arg) {
  ::reset(arg);
  if(!arg) {
    set_name("demonplate");
    set_alias("plate");
    set_type("armour/leg/arm");
    set_ac(10);
    set_weight(7);
    set_value(10000);
    set_short("Demonplate");
    set_long("A red plate mail with flame symbols.\n");
  }
}
