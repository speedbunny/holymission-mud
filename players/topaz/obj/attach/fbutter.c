inherit "obj/food";

reset(arg) {
    if(arg) return;
        set_name("butter");
        set_short("A stick of butter");
        set_long("A stick of butter.\n");
        set_alias("loaf");
        set_value(5);
        set_weight(1);
        set_strength(2);
        set_eater_mess("Yech!  Plain butter tastes terrible.\n");
}
