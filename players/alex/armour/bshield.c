inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
    if(arg) return;
    set_name("Black shield");
    set_alias("shield");
    set_short ("A  black shield.");
    set_long ("A shiny black shield with a cat as a coat of arms.\n");
    set_type ("shield");
    set_ac(1);
    set_weight(1);
    set_value();
}
 
 
