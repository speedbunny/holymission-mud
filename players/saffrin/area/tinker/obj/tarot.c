inherit "obj/weapon";
#include "/players/saffrin/defs.h"

reset(arg){

  ::reset(arg);
    set_name("tarot");
    set_short("A deck of tarot cards");
    set_long("A deck of tarot cards that look like they have been hand painted.\n");
    set_class(5);
    set_weight(1);
    set_value(83);
    set_hit_func(TO);
}

weapon_hit(attacker){
    ME("You feel the card of death jump out of the deck and slice your enemy.\n");
    say("The card of death jumps out of the tarot deck and slices its enemy.\n");
    return 1;
}
