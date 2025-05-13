inherit"obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("shield");
    set_short("A large metal shield");
    set_long("A large metal shield with Roland's coat of arms on it.\n");
    set_value(750);
    set_type("shield");
    set_size("medium");
    set_weight(0);
    set_ac(5);
}
