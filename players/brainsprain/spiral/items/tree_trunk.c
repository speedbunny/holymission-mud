inherit "obj/weapon";
void reset(int arg) {
    ::reset(arg);

    set_name("trunk");
    set_alias("trunk");
    set_short("A tree trunk");
    set_long(
"A freshly uprooted oak tree.  Several feet of the bark has been peled away "+
"to form a crude handle.  All of the branches have been ripped off, however "+
"Several of them stubs are pointed and sharp.  The roots are still attached "+
"also.\n");
    set_class(10);
    set_weight(45);
    set_value(1000);
}
