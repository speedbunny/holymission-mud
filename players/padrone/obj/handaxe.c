inherit "obj/weapon";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("hand axe");
    set_class(9);
    set_value(25);
    set_weight(2);
    set_alt_name("axe");
    set_short("A hand axe");
}
