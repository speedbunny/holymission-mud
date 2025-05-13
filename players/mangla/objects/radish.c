inherit "obj/food";

reset (arg) {
    ::reset (arg);
    if (!arg) {
        set_name("radish");
        set_short("Fresh Radish");
        set_alias("radish");
        set_long("Large radish fresh from the ground.\n");
        set_value(0);
        set_weight(1);
    }
}
