inherit "/obj/armour";
 
reset(arg) {
  ::reset(arg);
  if(!arg) {
     set_name("helmet");
     set_type("helmet");
     set_ac(1);
     set_size(1);
     set_short("A green grasshopper helmet");
     set_long("The strong armour of the green grasshopper.\n");
     set_value(30);
     set_weight(1);
  }
}
 
