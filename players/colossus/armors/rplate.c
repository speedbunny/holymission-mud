inherit"obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_alias("plate");
    set_name("platemail");
    set_type("armour");
    set_short("A suit of platemail");
    set_long("A shiny heavy suit of platemail.\n");
    set_weight(0);
    set_ac(5);
    set_size("medium");
    set_value(4000);
}
