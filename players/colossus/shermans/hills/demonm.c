#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if (arg) return;
    set_name("medium demon");
    set_alt_name("demon");
    set_size(3);
    set_level(20);
    set_hp(600);
    set_al(-150);
    set_ac(12);
    set_aggressive(1);
    set_wc(20);
    set_race("demon");
    set_short("Medium demon");
    set_long("A medium demon with long sharp claws.\n");
    add_money(400+random(400));
}
