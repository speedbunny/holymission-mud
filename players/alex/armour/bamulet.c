inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
    if(arg) return;
    set_name("Black amulet");
    set_alias("amulet");
    set_alt_name("bamulet");
    set_short ("A Black amulet");
    set_long ("A Black amulet with a longbow etched on to it.\n");
    set_type ("amulet");
    set_ac(0);
    set_weight(1);
    set_value(500);
}
 
