inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_name("shirt");
     set_type("cloak"); 
     set_ac(0);
     set_size(3);
     set_short("A flannel shirt");
     set_long("A warm looking comfortable flannel shirt.\n");
     set_value(25);
     set_weight(1);
  }
}
 
