inherit "obj/monster";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("fat pirate");
    set_alias("pirate");
    set_level(3);
    set_male();
    set_al(-100);
    set_short("A fat pirate");
    set_long("This is a short and fat pirate.\n");
    set_aggressive(1);
    add_money(2+random(10));
}
