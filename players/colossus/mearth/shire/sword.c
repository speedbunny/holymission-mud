inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("sword");
    set_short("A short sword");
    set_long("A short sword used by the shiriffs of the Shire.\n");
    set_class(8);
    set_weight(2);
    set_value(25);
}
