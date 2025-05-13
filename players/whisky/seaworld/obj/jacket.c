inherit "/obj/armour";


reset(arg) {
  ::reset(arg);
if (arg) return 1;
 
    set_name("jacket");
    set_alias("sailors jacket");
    set_short("A dirty sailors jacket");
    set_long("The dirty jacket of the drunken sailor.\n");
    set_type("armour");
    set_ac(2);
    set_size(3);
    set_weight(2);
    set_value(120);
return 1;
}
