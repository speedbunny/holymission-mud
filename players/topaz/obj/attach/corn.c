inherit "obj/food";

reset(arg) {
    if(arg) return;
        set_name("corn");
        set_short("An ear of corn");
        set_long("A ripe ear of corn.\n" +
                 "You could probably eat it.\n");
        set_alias("ear");
        set_alt_name("ear of corn");
        set_value(10);
        set_weight(1);
        set_strength(5);
        set_eater_mess("Mmmm!  That tastes good!\n");
}
