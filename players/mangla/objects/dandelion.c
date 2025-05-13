inherit "obj/food";

reset (arg) {
    ::reset (arg);
    if (!arg) {
        set_name("dandelion");
        set_short("Fresh Dandelion");
        set_alias("");
        set_long("Large dandelion freshly picked.\n");
        set_value(0);
        set_weight(1);
    }
}
