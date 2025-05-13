inherit "obj/alco_drink";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("sweet looking cola");
    set_alias("cola");
    set_short("A bottle of cola");
    set_long("drink it.\n");
    set_drinking_mess("Yummie cola!\n");
    set_strength(8);
    set_value(20);
}
