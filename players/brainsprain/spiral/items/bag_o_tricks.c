inherit "obj/container";
void reset(int arg) {

    set_name("bag o tricks");
    set_alias("bag");
    set_short("A bag of tricks");
    set_long(
"An huge bag, it could hold lots of items.  The leather strap that hangs "+
"from it is nearly rotted out.  There are several small holes in the bag. "+
"The bag itself is made of a tough leather of unknown origin.\n");
    set_value(50);
    set_weight(1);
    set_max_weight(10);
}
