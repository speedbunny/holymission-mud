inherit"obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("cloak");
set_type("cloak");
    set_short("A crimson cloak");
    set_long("A crimsoned colored cloak belonging to Roland.\n");
    set_weight(1);
    set_size("medium");
    set_value(150);
    set_ac(1);
}
