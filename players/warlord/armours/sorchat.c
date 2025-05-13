inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(!arg) {

    set_name("hat");
    set_short("Sorceror's hat");
    set_alias("sorceror's hat");
    set_long("This hat should only be worn by a magician.\n");
    set_ac(1);
    set_weight(2);
    set_value(1000);
    set_type("helmet");
  }
}

query_mage_wear() {
  return 1;
}
