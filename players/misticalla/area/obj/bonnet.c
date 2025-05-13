inherit "/obj/armour";
 
reset(arg) {
  ::reset(arg);
  if(!arg) {
     set_name("bonnet");
     set_type("helmet");
     set_ac(1);
     set_size(3);
     set_short("A blue bonnet");
     set_long("A little blue bonnet to wear, it shades you from the sun.\n");
     set_value(10);
     set_weight(1);
  }
}
 
