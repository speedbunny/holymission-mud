inherit "obj/alco_drink";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name( "vodka" );
    set_alt_name("bottle");
    set_alias("drink");
    set_short( "A shot of Skye Vodka" );
    set_long("This is one shot of an awesome clear liquor.\n");
    set_drinker_mess("AHHHHHH, that stuff rocks.\n");
    set_drinking_mess(" slams a shot of Skye Vodka.\n");
    set_value(100);
    set_weight(1);
    strength=50;
}
