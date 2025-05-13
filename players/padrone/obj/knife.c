inherit "obj/weapon";

reset(flag) {
    ::reset(flag);
    if(flag) return;
    set_name("knife");
    set_class(5);
    set_value(8);
    set_weight(2);
    set_short("A knife");
}
