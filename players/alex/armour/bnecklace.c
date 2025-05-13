inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
 
    if(arg) return;
    set_name("Black necklace");
    set_alias("necklace");
    set_short ("A black necklace");
    set_long ("A black necklace which shows a giant black cat leaping at a humanoid figger.\n");    
    set_type ("necklace");
    set_ac(0);
    set_weight(1);
    set_value(800); 
}
 
