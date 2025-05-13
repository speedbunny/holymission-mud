inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("big smelly pirate");
    set_alias("pirate");
    set_level(7);
    set_male();
    set_al(-150);
    set_short("A big smelly pirate");
    set_long("This is a big pirate. He does not smell good.\n");
    set_aggressive(1);
    add_money(1+random(50));
}
