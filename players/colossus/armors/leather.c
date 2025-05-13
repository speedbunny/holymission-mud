inherit"obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("leather");
    set_alias("armour");
    set_type("armour");
    set_short("Leather armour");
    set_long("A suit of leather armour used by gladiators");
    set_ac(3);
    set_weight(3);
    set_value(300);
}
