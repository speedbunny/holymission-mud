/* Completed 28.01.1995 */

inherit "/obj/food";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("trout");
    set_alias("fish");
    set_short("a trout");
    set_long("A trout, catched out from a mountain stream. A real delicacy!\n");
    set_value(500);
    set_eater_mess("That was marvelous!\n");
    set_eating_mess(" eats a fish with heavenly joy.\n");
    set_strength(40);
    set_weight(1);
} 
