
/* Copied from /room/south/sshore24.c */
/* Completed 27.01.1995 */

inherit "/obj/treasure";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("bush");
    set_short("a bush");
    set_value(80);
    set_weight(1);
    set_long("A bush of the best quality.\n");
}

