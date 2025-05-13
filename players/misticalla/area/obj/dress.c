inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_name("gingham dress");
     set_alias("dress");
     set_type("cloak"); 
     set_ac(0);
     set_size(3);
     set_short("A blue gingham dress");
     set_long("A comfortable blue dress, it would fit you well.\n");
     set_value(25);
     set_weight(1);
  }
}
 
