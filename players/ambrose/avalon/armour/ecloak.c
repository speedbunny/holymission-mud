inherit "obj/armour";

reset(arg){
if (arg) return;
  set_name("cloak");
  set_short("Leather Cloak");
  set_long("This leather cloak looks like it might turn away a blow or\n"+
           "two.  As you put it around your shoulders you start to\n"+
           "feel more light.\n");
  set_weight(1);
  set_value(2000);
  set_type("cloak");
  set_ac(1);
  set_size("large");
  modify_stat(1,2);
 }
