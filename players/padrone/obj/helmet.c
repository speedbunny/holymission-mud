inherit "/obj/armour";

reset(flag) {
    ::reset(flag);
    if(flag) return;
    set_name("metal helmet");
    set_ac(1);
    set_weight(3);
    set_value(75);
    set_alias("helmet");
    set_type("helmet");
    set_short("A metal helmet");
    set_long("A metal helmet\n");
}
