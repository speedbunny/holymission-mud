inherit "obj/weapon";
void reset(int arg) {
    ::reset(arg);
    set_name("sword");
    set_alias("sword");
    set_short("A Copper Sword");
    set_alt_name("copper sword");
    set_long(
"A medium quality short sword made out of copper.  The wooden handle has "+
"a poor etching of an orc inlaid into it.  The blade looks like it has been "+
"recently used to chop down a forest of trees.  There are several nicks along "+
"the cutting edge.\n");
    set_class(4);
    set_weight(1);
    set_value(40);
}
