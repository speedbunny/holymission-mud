inherit "obj/weapon";
reset (arg) {
    ::reset();
    set_name("teeth");
    set_class(18);
    set_weight(1);
    set_value(2000);
    set_type(2);
    set_short("Vampire teeth");
    set_long("Very long and sharp teeth.\n");
}

query_teeth() {
    return 1;
}
