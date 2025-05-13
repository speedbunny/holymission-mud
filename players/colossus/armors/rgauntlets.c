inherit"obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_alias("gloves");
    set_name("gauntlets");
    set_short("War gauntlets");
    set_long("Heavily armored war gauntlets.\n");
    set_type("glove");
    set_weight(0);
    set_size("medium");
    set_value(250);
    set_ac(1);
}
