inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name ("A huge sandworm");
    set_alias ("sandworm");
    set_alt_name ("worm");
    set_level (39);
    set_wimpy (-1);
    set_gender (0);
    set_aggressive (1);
    set_short ("A huge sandworm");
    set_long ("A huge brown sandworm. It is aggressive and it looks tough.\n");
    set_chance(10);
    set_spell_mess1("The sandworm winds itself around you and takes your breath !");
    set_spell_mess2("The sandworm spills sand on you ! \n" +
                    "You are hurt seriously !\n");
    set_spell_dam(10+random(10));
    add_money(850+random (350));
}

init() {
    ::init();
}

detect_invis()
{
    return 1;
}
