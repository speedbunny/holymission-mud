/* Axlrose's Favorite Drink */
inherit "obj/soft_drink";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("dr. pepper");
    set_alt_name("bottle");
    set_alias("drink");
    set_short("A bottle of Dr. Pepper");
    set_long("An ice cold bottle of Dr. Pepper.\n");
    set_drinker_mess("Ahhh, refreshing...be a pepper, drink Dr. Pepper!\n");
    set_drinking_mess(" buuurrrps loudly and obnoxiously!!!  'What a pig!' you think.\n");
    set_value(100);
    set_weight(1);
    strength=20;
}

