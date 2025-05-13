inherit "obj/weapon";
void reset(int arg) {
    ::reset(arg);

    set_name("mace");
    set_alias("mace");
    set_short("A huge mace");
    set_long(
"A long wooden stick with a huge ball on it.  Several nails stick out of "+
"the end of it at odd angles.  A leather strap has been wrapped around "+
"the handle to improve the grip.  There is a hole on the end of it where "+
"one of the nails has pulled out.\n");
    set_class(7);
    set_weight(1);
    set_value(10);
}

