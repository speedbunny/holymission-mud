/* Completed 14.01.1995 */

inherit "/obj/soft_drink";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("egg");
    set_alias("falcon egg");
    set_short("an egg");
    set_long("Egg of a giant falcon. It is said to have some "+
             "healing power.\n");
    set_value(350);
    set_drinker_mess("Crack! Ssssss... glug... glug...\n");
    set_drinking_mess(" breaks an egg and drinks its contain.\n");
    set_strength(25);
    set_weight(1);
}

void init() {
    ::init();
    add_action("eat","eat");
}

int eat(string str) {
    if(!str) {
        notify_fail("Eat what ?\n");
        return 0;
    }
    if ((str!="egg") && (str!="falcon egg")) {
        notify_fail("Are you OK ? That is not edible!\n");
        return 0;
    }
    write("Hey, this is not a boiled-egg! It contains some liquid!\n");
    return 1;
} 
