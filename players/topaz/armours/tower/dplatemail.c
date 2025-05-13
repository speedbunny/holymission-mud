inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("platemail");
  set_short("Demon platemail");
  set_long("A set of dingy platemail.\n" +
           "It still looks like good armour though.\n");
  set_alias("plate");
  set_type("armour");
  set_ac(4);
  set_weight(4);
  set_value(3000);
}
