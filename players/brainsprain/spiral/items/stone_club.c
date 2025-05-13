stone_club
inherit "obj/weapon";
void reset(int arg) {
    ::reset(arg);

    set_name("club");
    set_alias("stone club","club");
    set_short("A stone club");
    set_long(
"The head of this club is formed from a shard of onyx.  It is lashed to "+
"a quartz handle.  The overall effect is an extremely heavy weapon "+
"perfect for crushing anything.  However there are several cracks in the "+
"onyx.\n");
    set_class(3);
    set_weight(1);
    set_value(50);
}
