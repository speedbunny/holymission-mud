inherit "/obj/armour";


reset(arg) {
  ::reset();
if (arg) return 1;
 
    set_name("jacket");
    set_alias("native jacket");
    set_short("A native's jacket");
    set_long("A small but strong monkey-fur jacket.\n");
    set_type("armour");
    set_ac(2);
    set_size(2);
    set_weight(2);
    set_value(80);
return 1;
}
