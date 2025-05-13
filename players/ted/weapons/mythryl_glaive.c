inherit "obj/weapon";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Mythryl Glaive");
  set_alias("glaive");
  set_alt_name("mythryl glaive");
  set_long("This long pole arm is tipped with a mythryl blade.\n");
  set_class(15);
  set_weight(3);
  set_value(1500);
}
