inherit "obj/armour";
 
reset(arg) {
::reset(arg);
    if(arg) return;
    set_name("steel boots");
    set_alias("boots");
    set_short ("A pair of steel boots");
    set_long ("These are a pair of nice steel boots with protective soles.\n");
    set_type("boots");
    set_ac(0);
    set_weight(1);
    set_value(500);
}
