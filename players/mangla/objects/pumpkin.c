inherit "obj/food";

reset (arg) {
    ::reset (arg);
    if (!arg) {
        set_name("pumpkin");
        set_short("Fresh Pumpkin");
        set_alias("pumpkin");
        set_long("Large pumpkin fresh from the garden.\n");
        set_value(0);
        set_weight(1);
    }
}
