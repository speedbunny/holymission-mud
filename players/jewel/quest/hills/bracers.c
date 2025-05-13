inherit "obj/armour";

reset (arg) {
  ::reset(arg);
  if(!arg) {
    set_name("bracers");
    set_type("arm");
    set_ac(2);
    set_weight(1);
    set_value(10000);
    set_short("Bracers");
    set_long("Mage bracers.\n");
  }
}
query_mage_wear() {
 return 1;
}
query_monk_wear() {
return 1;
}

