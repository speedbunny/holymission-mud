inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
    if(arg) return;
    set_name("Black helmet");
    set_alias("helmet");
    set_short ("A black helmet");
    set_long ("A black helmet with two horns attached to the sides.\n");
    set_type ("helmet");
    set_ac(1);
    set_weight(1);
    set_value(500);
}
 
