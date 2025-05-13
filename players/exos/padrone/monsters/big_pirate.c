inherit "obj/monster";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("big pirate");
    set_alias("pirate");
    set_level(7);
    set_male();
    set_al(-120);
    set_short("A big pirate");
    set_long("This pirate is big, but not as big as his friend.\n");
    set_aggressive(0);
    add_money(10+random(100));
}
