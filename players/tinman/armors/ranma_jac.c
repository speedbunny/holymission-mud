inherit"obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_alias("jacket");
    set_name("Ranma's Jacket");
    set_type("armour");
    set_short("A warm chinese jacket");
    set_long("A jacket worn by any typical chinese person, BUT this is not a\n" +
      "typical jacket. This is Ranma's favorite jacket.\n");
    set_weight(0);
    set_ac(5);
    set_size("any");
    set_value(4000);
}
