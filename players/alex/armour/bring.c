inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
 
    if(arg) return;
    set_name("Black stone ring");
    set_alias("ring");
    set_short ("A Black stone ring");
    set_long ("A dark ring with a Black stone embedded in it.\n" +
             "There apeares to be runes etched in to the side.\n");
    set_read("To find the Elven bane look at the hirunes.");
    set_type ("ring");
    set_ac(0);
    set_weight(0);
    set_value(10);
}
 
