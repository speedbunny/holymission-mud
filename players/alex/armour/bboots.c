inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
    if(arg) return;
    set_name("Black woods boots");
    set_alias("boots");
    set_alt_name("bboots");
    set_short ("A pair of black woods boots");
    set_long ("A pair of black woods boots, with these you\n"+
              "could go through the woods as silent as an elf.\n");
    set_type ("boots");
    set_ac(1);
    set_weight(1);
    set_value(100); 
}
 
