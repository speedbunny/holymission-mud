inherit "obj/monster";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("rude pirate");
    set_alias("pirate");
    set_level(3);
    set_male();
    set_al(-100);
    set_short("A rude pirate");
    set_long("The rude pirate laughs and makes an obscene gesture.\n");
    set_aggressive(1);
    add_money(2+random(40));
}
