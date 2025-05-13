inherit "/obj/armour";
reset(arg) {  
  ::reset(arg);
  if(!arg) {
    set_name("chainmail");
    set_alias("mail");
    set_type("armour");
    set_ac(4);
    set_short("chainmail");
    set_long("A heavy, expensive full body armour.\n");
    set_value(800);
    set_size(3);
    set_weight(3);
  }
}
