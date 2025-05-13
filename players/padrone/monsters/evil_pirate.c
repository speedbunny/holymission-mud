inherit "obj/monster";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("evil pirate");
    set_alias("pirate");
    set_level(3);
    set_male();
    set_al(-200);
    set_short("An evil pirate");
    set_long("This is an evil-looking pirate.\n");
    set_aggressive(1);
    add_money(20+random(30));
}
