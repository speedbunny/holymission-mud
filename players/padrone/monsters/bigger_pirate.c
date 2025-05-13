inherit "obj/monster";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("bigger pirate");
    set_alias("pirate");
    set_level(9);
    set_male();
    set_al(-130);
    set_short("A bigger pirate");
    set_long("This pirate is bigger than his companion.\n");
    set_aggressive(1);
    add_money(20+random(200));
}
