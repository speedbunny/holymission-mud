inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
    if(arg) return;
 
    set_name("Guards helmet");
    set_alias("helmet");
    set_short ("A guards helmet");
    set_long ("A guards helmet with a spike on top.\n");
    set_type ("helmet");
    set_ac(1);
    set_weight(1);
    set_value(500);
}
 
 
