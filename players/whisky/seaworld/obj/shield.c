inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
if (arg) return 1;

  set_name("shield");
    set_alias("carapace shield");
    set_type("shield");
    set_short("A carapace shield");
    set_long("The stong armour of the frightend carapace.\n");
    set_ac(2);
    set_value(300);
    set_weight(2);
 return 1;
}
