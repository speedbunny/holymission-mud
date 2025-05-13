inherit "obj/thing";

reset (arg) {
    ::reset(arg);
    if (!arg) {
        set_name("glass");
        set_weight(1);
        set_value(1000);
        set_short("A glass");
        set_long("A glass, stolen from the vampire party.\n");
    }
}
