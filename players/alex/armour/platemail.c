inherit "obj/armour";
 
reset(arg) {
    if(arg) return;
  ::reset(arg);
 
    set_name("Black platemail");
    set_alias("platemail");
    set_short ("A Black platemail");
    set_long ("A dull black platemail that belonged to a Death knight.\n");
    set_type ("armour");
    set_ac(6);
    set_weight(5);
    set_value(5000);
}
 
