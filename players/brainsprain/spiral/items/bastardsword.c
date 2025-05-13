inherit "obj/weapon";
void reset(int arg) {
    ::reset(arg);

    set_name("bastardsword");
    set_alias("sword");
    set_short("A bastardsword");
    set_long(
"A bastard sword made of steel.  The tempered blade glows with an "+
"unnatural malice.  The serrated edge has a cruel light to it.  The "+
"hilts are massive and formed in the shape of a bat.  The handle sweeps "+
"back in a graceful curve.\n");
    set_class(8);
    set_weight(1);
    set_value(150);
}
