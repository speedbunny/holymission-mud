inherit "/obj/armour";
 
reset(arg) {
  ::reset(arg);
  if(!arg) {
      set_name("tam");
      set_type("helmet");
      set_ac(1);  /**/
      set_short("a bloated dreadlock tam");
      set_long("a bloated dreadlock tam\n");
      set_value(100);
      set_weight(1);
  }
}
 
