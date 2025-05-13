inherit "obj/weapon";
void reset(int arg) {
    ::reset(arg);

    set_name("axe");
    set_alias("stone axe");
    set_short("A stone axe");
    set_long(
"A huge axe whose head is carved out of a slab of granite.  The wooden. "+
"bends slightly under the weight of the massive stone.  A thin piece of "+
"twine is all that connects the head of the axe to the handle.\n");
    set_class(4);
    set_weight(1);
    set_value(55);
}

