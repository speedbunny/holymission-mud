inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("shield");
  set_short("Battered Shield");
  set_long("A shield that, although it's battered, it's still good.\n");
  set_type("shield");
  set_ac(1);
  set_weight(2);
  set_value(800);
}
