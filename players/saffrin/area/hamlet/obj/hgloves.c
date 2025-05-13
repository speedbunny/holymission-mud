inherit "/obj/armour";

reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("gloves");
     set_short("Hamlet's gloves");
     set_long("A fine pair of hand linked chain gloves perfect for Hamlet to \n"+
                   "use in battle.\n");
     set_ac(1);
     set_size(3);
     set_type("glove");
     set_weight(1);
     set_value(1000);
     set_size(0);
  }
}
