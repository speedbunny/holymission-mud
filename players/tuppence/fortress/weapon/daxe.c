inherit "obj/weapon";
void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("axe");
    set_short("A evil battleaxe");
    set_alias("battleaxe");
    set_class(20);
    set_weight(2);
    set_value(2000);
    set_long("An evil battleaxe, usually wielded by a great demon\n");
}
