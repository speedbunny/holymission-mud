inherit "obj/food";

reset (arg) {
    ::reset (arg);
    if (!arg) {
        set_name("raddicchio");
        set_short("Fresh Raddicchio");
        set_alias("raddicchio");
        set_long("Large raddicchio fresh from the ground.\n");
        set_value(0);
        set_weight(1);
    }
}
