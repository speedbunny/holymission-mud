inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
    if(arg) return;
    set_name("Black gloves");
    set_alias("gloves");
    set_short ("A pair of black gloves");
    set_long ("A pair of chain link black gloves.\n");
    set_type ("gloves");
    set_ac(0);
    set_weight(1);
    set_value(500);
}
 
