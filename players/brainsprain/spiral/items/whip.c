inherit "obj/weapon";
void reset(int arg) {
    ::reset(arg);

    set_name("whip");
    set_alias("whip");
    set_short("A black, leather whip");
    set_long(
"A slender, black whip.  It is about six feet long.  Its handle is made "+
"out of a shard of onyx.  The leather of the whip is stained black from "+
"sweat and blood.  The end of the whip is frayed into three separate tips "+
"about six inches long.\n");
    set_class(5);
    set_weight(1);
    set_value(70);
}

