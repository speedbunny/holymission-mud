inherit "obj/weapon";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("long sword");
    set_class(15);
    set_value(700);
    set_weight(2);
    set_alt_name("sword");
    set_short("A long sword");
}
