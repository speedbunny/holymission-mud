inherit "obj/npc";
reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_alt_name("tana-ri");
    set_level(45);
    set_al(-500);
    set_ac(25);
    set_aggressive(1);
    set_wc(30);
    set_race("demon");
    set_name("marilith");
    set_short("marilith");
    set_long("A large fire demon with long claws. Looking closer you notice\n"+
             "this has to be one of the legendary True Tana-Ri. His 6 arms\n"+
             "and his powerfull snaketail make him a formidable oponent!!\n");
    set_chance(15);
    set_spell_mess1("The Marilith charges!!!");
    set_spell_mess2("The Marilith charges at YOU, almost knocking you over.");
    set_spell_dam(60);
    set_attacks(6);
    set_attacks_change(100);
    set_size(4);
}

int query_str() { return 60; }
int query_dex() { return 60; }
