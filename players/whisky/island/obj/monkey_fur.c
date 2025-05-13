inherit "obj/armour";
 
reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("fur");
     set_alias("monkey fur");
     set_type("cloak");
     set_ac(1);
     set_size(2);
     set_short("A monkey fur");
     set_long("The protection of the.\n"+
              "little island-monkey.\n");
     set_value(60);
     set_weight(1);
  }
}
 
