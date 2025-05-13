inherit "obj/food";

reset (arg) {
    ::reset (arg);
    if (!arg) {
        set_name("salad");
        set_short("Fresh Salad");
        set_alias("salad");
        set_long("A large salad someone has forgotten and you have found.\n");
        set_value(0);
        set_weight(1);
    }
}

