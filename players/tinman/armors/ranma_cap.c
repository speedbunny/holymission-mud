inherit "obj/armour";

reset (arg) {
    ::reset (arg);
    if (arg) return;
    set_alias("cap");
    set_name("Ranma's cap");
    set_short("A chinese army cap");
    set_long("A green cap with a red star of the Chinese army, which Ranma\n" +
     "probably acquired during his training in China.\n");
    set_value(750);
    set_size("any");
    set_weight(1);
    set_type("helmet");
    set_ac(1);
}
