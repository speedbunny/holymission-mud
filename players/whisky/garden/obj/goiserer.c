inherit "/obj/armour";
 
reset(arg) {

  ::reset(arg);
  if (!arg) {
    set_name("goiserers");
    set_type("boot");
    set_ac(1);
    set_long("Heavy moutain boots.\n");
    set_value(100);
    set_weight(1);
  }
}
