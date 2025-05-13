inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("plate");
    set_alias("platemail");
    set_type("armour");
    set_size("medium");
    set_short("Old rusted platemail");
    set_long("A worn and rusted suit of ancient platemail.\n");
    set_ac(4);
    set_weight(2);
    set_value(500);
}
