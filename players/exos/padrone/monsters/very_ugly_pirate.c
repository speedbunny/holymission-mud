inherit "obj/monster";

reset(flag) {
    ::reset(flag);
    if(flag) return;
    set_name("very ugly pirate");
    set_alias("pirate");
    set_level(4);
    set_gender(1);
    set_al(-100);
    set_short("A very ugly pirate");
    set_long("This is a medium-sized and very ugly pirate.\n");
    set_aggressive(1);
    add_money(1+random(50));
}
