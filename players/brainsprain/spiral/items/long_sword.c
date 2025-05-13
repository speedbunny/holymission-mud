inherit "obj/weapon";
void reset(int arg) {
    ::reset(arg);

    set_name("long sword");
    set_alias("longsword", "sword");
    set_short("A longsword");
    set_long(
"A finely balanced blade that is about five feet long tip to hilts.  The "+
"steel glistens as if it where wet.  The sweeping hilts are made to block "+
"most slashing blows.  The handle has a diamond imbedded in it.\n");
    set_class(12);
    set_weight(2);
    set_value(250);
}
