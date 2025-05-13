inherit "obj/monster";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("disgusting pirate");
    set_alias("pirate");
    set_level(2);
    set_male();
    set_al(-100);
    set_short("A disgusting pirate");
    set_long("Yuk! What a disgusting pirate!\n");
    set_aggressive(1);
    add_money(2+random(20));
}
