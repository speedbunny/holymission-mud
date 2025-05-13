inherit "obj/weapon";
void reset(int arg) {
    ::reset(arg);

    set_name("spear");
    set_alias("spear");
    set_short("A long spear");
    set_long(
"This spear has a long wooden shaft.  The head is made of flint and is tied "+
"on with a leather thong.  The tip is chipped in many places.  The handle "+
"is in bad need of repair because it is cracked in several places.\n");
    set_class(6);
    set_weight(1);
    set_value(100);
}

