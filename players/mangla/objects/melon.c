inherit "obj/food";

reset (arg) {
    ::reset (arg);
    if (!arg) {
        set_name("melon");
        set_short("Fresh Melon");
        set_alias("melon");
        set_long("Fresh melon from the garden.\n");
        set_value(0);
        set_weight(1);
    }
}
