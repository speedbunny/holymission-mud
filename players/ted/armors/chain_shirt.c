inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("chain shirt");
  set_type("armor");
  set_alias("shirt");
  set_short("A Chainlink Shirt");
  set_long("This chainmail shirt covers the upper body only.\n");
  set_ac(3);
  set_weight(2);
  set_value(150);
}
