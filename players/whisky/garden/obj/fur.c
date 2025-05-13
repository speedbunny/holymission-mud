inherit "obj/armour";
 
reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("fur");
     set_type("robe");
     set_ac(1);
     set_short("A lynx fur");
     set_long("The protection of the lynx against enemies.\n");
     set_value(80);
     set_weight(1);
     set_alias("lynx fur");
  }
}
 
