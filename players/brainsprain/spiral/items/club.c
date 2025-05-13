inherit "obj/weapon";
void reset(int arg) {
    ::reset();

    set_name("club");
    set_alias("club");
    set_short("A huge club");
    set_long(
"This club is composed of a hude ball of granite tied to a stick of wood. "+
"with a piece of string.  The sweat-blackened, wooden handle has been worn "+
"smooth from use.  Various chips and dents add character to the otherwise "+
"lackluster tool of destruction.\n");
    set_class(17);
    set_weight(3);
    set_value(900);
}
