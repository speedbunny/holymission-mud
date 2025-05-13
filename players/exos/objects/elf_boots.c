inherit "obj/armour";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("elven boots");
    set_alias("boots");
    set_type("boots");
    set_ac(1);
    set_weight(0);
    set_value(1000);
    set_short("elven boots");
    set_long("\
These green boots are more like cloth shoes than boots.  The Elven\n\
warriors of Regulost wear these in preference to all other\n\
footwear.  They are soft and make no sound when the wearer walks.\n\
They are also so light that they leave no footprints.\n");
}
