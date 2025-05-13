sceptert.c
inherit "obj/weapon";
void reset(int arg) {
    ::reset(arg);

    set_name("scepter");
    set_alias("scepter");
    set_short("The Trakag scepter");
    set_long(
"The scepter of the Troll chief.  It is a staff with fine silver inlay. "+
"The end of the scepter is encrusted with various gems.  The handle has "+
"a fine sheepskin leather encasing.  This is obviously a fine made object.\n");
    set_class(6);
    set_weight(1);
    set_value(70);
}
