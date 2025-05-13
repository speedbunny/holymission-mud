inherit "/obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return 1;
    set_name("robe");
    set_type("armour");
    set_ac(1);
    set_short("An old brown robe");
   set_long("This is an old brown monks robe\n"+
        "It has holes in it and looks totally worn out\n");
    set_value(150);
    set_weight(1);
    set_size(3);
    return 1;
}

