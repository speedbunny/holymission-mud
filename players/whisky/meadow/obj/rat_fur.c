inherit "obj/armour";
 
reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("fur");
     set_type("cloak");
     set_alias("rat fur");
     set_ac(1);
     set_size(1);
     set_short("A rat fur");
     set_long("A hairy brown rat fur.\n");
     set_value(20);
     set_weight(1);
  }
}
 
