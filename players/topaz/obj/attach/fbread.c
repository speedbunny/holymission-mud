inherit "obj/food";

reset(arg) {
    if(arg) return;
        set_name("bread");
        set_short("A loaf of bread");
        set_long("A loaf of bread.\n");
        set_alias("loaf");
        set_value(5);
        set_weight(1);
        set_strength(5);
        set_eater_mess("It's a bit dry, but still good.\n");
}
