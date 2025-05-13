#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if (arg) return;
    set_name("tiny demon");
    set_alt_name("demon");
    set_size(1);
    set_level(10);
    set_hp(250);
    set_al(-150);
    set_ac(5);
    set_aggressive(1);
    set_wc(12);
    set_race("demon");
    set_short("Tiny demon");
    set_long("A tiny demon with long finger nails.\n");
    add_money(100+random(100));
}
