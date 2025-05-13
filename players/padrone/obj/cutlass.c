inherit "obj/weapon";

reset(flag) {
    ::reset(flag);
    if(flag) return;
    set_name("cutlass");
    set_class(10);
    set_value(50);
    set_weight(3);
    set_short("A cutlass");
    set_long("This is a cutlass. It has probably belonged to a pirate.\n");
}
