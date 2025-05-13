inherit "obj/food";

reset (arg) {
    ::reset (arg);
    if (!arg) {
        set_name("lettuce");
        set_short("Fresh Lettuce");
        set_alias("lettuce");
        set_long("Large head of lettuce.\n");
        set_value(0);
        set_weight(1);
    }
}
