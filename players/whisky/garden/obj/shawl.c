inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_name("shawl");
     set_type("cloak");
     set_ac(0);
     set_size(2);
     set_short("A red shawl");
     set_long("A red shawl with the inscription <Greta>.\n");
     set_value(50);
     set_weight(1);
  }
}
 
