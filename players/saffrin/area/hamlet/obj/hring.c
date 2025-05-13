inherit "/obj/armour";
      
reset(arg) {

  ::reset(arg);
  if (!arg) {
      set_name("ring");
      set_short("Hamlet's ring");
      set_long("A dark emerald ring embedded into a gold setting worn by the heir to \n"+
                    "the throne of Denmark.\n");
      set_ac(1);
      set_size(3);
      set_type("ring");
      set_value(1000);
      set_weight(1);
  }
}
