/* Axlrose - Barbarian Guild */
/* Severance's Armour */
inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("black dragonscale pieces");
    set_alias("scales");
    set_type("armour");
    set_ac(3);
    set_short("Black Dragonscale Armour");
    set_long
      ("Various shaped and sized pieces of black dragon scales are form-fitted \n" 
      +"to create a suit of armour.  Leather straps and metal bands hold the \n"
      +"scales together, though many gaps are evident in-between the scarred, \n"
      +"weather beaten pieces.\n");
    set_value(13500);
    set_weight(2);
}

