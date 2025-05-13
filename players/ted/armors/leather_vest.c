inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("vest");
  set_type("armor");
  set_alias("leather vest");
  set_short("Leather Vest");
  set_long("This leather vest covers the upper chest and arms only.\n");
  set_ac(1);
  set_weight(1);
  set_value(25);
}
