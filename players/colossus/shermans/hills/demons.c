#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if (arg) return;
    set_name("small demon");
    set_alt_name("demon");
    set_size(2);
    set_level(15);
    set_hp(350);
    set_al(-150);
    set_ac(7);
    set_aggressive(1);
    set_wc(15);
    set_race("demon");
    set_short("Small demon");
    set_long("A small demon with sharp claws.\n");
    add_money(200+random(200));
}
