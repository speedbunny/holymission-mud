inherit "obj/monster";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("hungry pirate");
    set_alias("pirate");
    set_level(2);
    set_male();
    set_al(-100);
    set_short("A hungry pirate");
    set_long("This pirate looks hungry. He's looking for food in the kitchen.\n");
    set_aggressive(1);
    add_money(2+random(10));
}
