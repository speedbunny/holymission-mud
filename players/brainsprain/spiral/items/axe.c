inherit "obj/weapon";
void reset(int arg) {
    ::reset(arg);
    set_name("axe");
    set_alias("axe");
    set_short("A throwing axe");
    set_long(
"  An axe moulded moulded from a piece of iron  The handle is made of a\n"+
"  piece of granite.  All and all, the axe is perfectly balanced for\n"+
"  throwing.  An engraved picture of a human head adorns the blade.\n");
    set_class(8);
    set_weight(1);
    set_value(100);
}
