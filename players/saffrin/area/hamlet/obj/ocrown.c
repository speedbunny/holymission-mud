inherit "/obj/armour";
      
reset(arg) {

  ::reset(arg);
  if (!arg) {     
      set_name("wreath");
      set_short("A wreath of roses");
      set_long("A beautiful wreath woven from roses of several different colors.  Long ribbons\n"+
                     "trail from each bud.\n");
      set_size(3);
      set_ac(0);
      set_type("helmet");
     set_value(10);
      set_weight(1);
  }
}
