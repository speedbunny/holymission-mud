inherit "obj/food";

reset (arg) {
    ::reset (arg);
    if (!arg) {
        set_name("grass");
        set_short("Fresh Grass");
        set_alias("grass");
        set_long("Freshly gathered grass.\n");
        set_value(0);
        set_weight(1);
    }
}
