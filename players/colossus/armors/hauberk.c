inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_alias("chain");
    set_type("armour");
    set_name("hauberk");
    set_short("Chain hauberk");
    set_long(
      "Typical chain hauberk used by knights of that time.");
    set_weight(3);
    set_size("medium");
    set_value(500);
    set_ac(3);
}
