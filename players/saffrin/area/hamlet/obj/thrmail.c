inherit "/obj/armour";
      
reset(arg) {

  ::reset(arg);
  if (!arg) {
      set_name("chainmail");
      set_short("Noble's chainmail");
      set_long("Chainmail worn by a person of noble personage.  It is made from steel that\n"+
                     "was tempered with a rare metal to appear gold in color.\n");
      set_ac(4);
      set_size(3);
      set_type("armor");
      set_value(1000);
      set_weight(4);
  }
}
