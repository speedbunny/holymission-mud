inherit "obj/food";

reset (arg) {
    ::reset (arg);
    if (!arg) {
        set_name("cloverleaf");
        set_short("Fresh Cloverleaf");
        set_alias("cloverleaf");
        set_long("Large cloverleaf freshly picked.\n");
        set_value(0);
        set_weight(1);
    }
}
