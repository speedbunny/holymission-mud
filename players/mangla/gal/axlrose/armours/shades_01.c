/* Axlrose - Sunglasses */
inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("shades");
    set_type("glasses");
    set_ac(0);
    set_short("Dark Sunglasses");
    set_long("Axl Rose's shades from one of his concerts!\n");
    set_value(500);
    set_weight(1);
}
