inherit "obj/monster";

reset(flag) {
    ::reset(flag);
    if(flag) return;
    set_name("ugly pirate");
    set_alias("pirate");
    set_level(2);
    set_male();
    set_al(-100);
    set_short("An ugly pirate");
    set_long("This is a small and ugly pirate.\n");
    set_aggressive(1);
    add_money(50+random(100));
}
