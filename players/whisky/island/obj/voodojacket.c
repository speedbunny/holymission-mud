inherit "/obj/armour";


reset(arg) {
  ::reset();
  if (arg) return;
 
    set_name("jacket");
    set_alias("voodojacket");
    set_short("A Voodojacket");
    set_long("The magical armour of\n"+
             "the dangerous Zuluman.\n");
    set_type("armour");
    set_ac(1); /* because its mages wearable */
    set_weight(2);
    set_value(15000);
}
query_mage_wear()
{
  return 1;
}
