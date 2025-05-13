inherit "obj/food";

reset (arg) {
    ::reset (arg);
    if (!arg) {
        set_name("cucumber");
        set_short("Fresh Cucumber");
        set_alias("cucumber");
        set_long("Large, green cucumber.\n");
        set_value(0);
        set_weight(1);
    }
}
