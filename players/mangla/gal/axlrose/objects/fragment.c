/* Axlrose - Barbarian Guild */
inherit "obj/treasure";

reset(arg) {
    if (arg) return;
    set_name("acid burnt metal fragments");
    set_alt_name("steel scraps");
    set_alias("pieces");
    set_short("corroded steel scrap pieces");
    set_long
    ("Various shaped and sized pieces of both dull and sharp edged corroded \n"
      +"steel scraps.  Closer examination reveals an acid type burnt the metal \n"
      +"fragments - weakening the structure while erasing a dwarven rune.\n");
    set_value(10);
    set_weight(1);
}
