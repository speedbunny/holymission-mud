inherit "obj/thing";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_weight(100);
    set_short("A BIG FLASHING you SHOULD read!");
    set_name("A BIG SIGN");
    set_long("Please READ the sign! It's for your own good!\n");
}
