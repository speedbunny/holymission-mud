inherit "obj/food";

reset(arg) {
    if(arg) return;
        set_name("candy");
        set_short("A piece of candy");
        set_long("A piece of candy.\n");
        set_alias("piece");
        set_value(5);
        set_weight(1);
        set_strength(10);
        set_eater_mess("Oooh!  That's verrrry yummi!\n");
}
