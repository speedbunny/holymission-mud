inherit "/obj/armour";
     
reset(arg) {

  ::reset(arg);
  if (!arg) {
      set_name("shield");
      set_short("Hamlet's shield");
      set_long("A sturdy leather and wooden shield with the coat of arms of the \n"+
                     "house of Denmark on it.\n");
      set_ac(3);
      set_size(3);
      set_type("shield");
      set_value(1000);
      set_weight(3);
      set_size(0);
  }
}
