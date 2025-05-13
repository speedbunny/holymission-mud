inherit "obj/armour";

reset(flag) {
    ::reset(flag);
    if(flag) return;
    set_name("chainmail");
    set_alias("armour");
    set_type("armour");
    set_ac(3);
    set_value(500);
    set_weight(5);
    set_short("A suit of chainmail");
}
