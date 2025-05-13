/* Axlrose - Human Army */
/* Soldier's Dagger */
inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("dual edged long knife");
    set_alt_name("dagger");
    set_alias("knife");
    set_short("Dual bladed steel dagger");
    set_long
    ("A dual edged steel dagger approximately eight inches long.  Leather \n"
      +"wrapping circles the handle from hilt to pommel.\n");
    set_class(4);
    set_value(20);
    set_weight(1);
}
