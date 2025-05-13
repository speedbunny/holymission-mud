inherit"obj/armour";

void reset(int arg) {

  ::reset(arg);
    if (arg) return;
    set_name("collar");
    set_type("bracelet");
    set_short("Azrael's collar");
    set_long("A beautifully crafted bracelet of silvery metal set with \
pale blue stones. It looks about the right size to fit around your wrist.\n");
    set_weight(1);
    set_ac(1);
    set_value(162);
}
