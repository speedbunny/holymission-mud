inherit "obj/armour";

reset (arg) {
    ::reset (arg);
    if (arg) return;
    set_alias("helm");
    set_name("helmet");
    set_short("A shiny metal helmet");
    set_long("A shiny French-style metal helmet\n");
    set_value(150);
    set_size("any");
    set_weight(1);
    set_type("helmet");
    set_ac(1);
}
