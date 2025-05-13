inherit "/obj/armour";
 
reset(arg) {
  ::reset(arg);
  if(!arg) {
     set_name("cap");
     set_type("helmet");
     set_ac(1);
     set_size(3);
     set_short("A baseball cap");
     set_long("A forrest green baseball cap with white lettering.\n");
     set_value(10);
     set_weight(1);
  }
}
 
