inherit "obj/weapon";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("rusty cutlass");
    set_class(7);
    set_value(10);
    set_weight(3);
    set_alt_name("cutlass");
    set_short("A rusty cutlass");
    set_long("This used to be a fine weapon, but the pirate who owned it let it rust.\n");
}
