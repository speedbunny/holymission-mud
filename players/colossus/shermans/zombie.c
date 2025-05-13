#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset();
    if (arg) return;
    set_name("zombie");
    set_level(4);
    set_hp(150);
    set_al(-100);
    set_ac(2);
    set_wc(10);
    set_aggressive(1);
    set_race("undead");
    set_short("Zombie");
    set_long(
      "The zombie is nothing more than magically animated dead.\n\
It looks at you with cold unfeeling eyes as pieces of flesh\n\
are jarred loose by its motions to fall to the ground with\n\
a disgusting sound. Blank eyes gaze at you with no thoughts\n\
except for the desire and the need for warm flesh.\n");
    add_money(random(50));
}
