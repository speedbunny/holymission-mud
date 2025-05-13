inherit "obj/npc";
reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_alt_name("tana-ri");
    set_level(40);
    set_str(60);
    set_dex(50);
    set_al(-500);
    set_ac(20);
    set_aggressive(1);
    set_wc(25);
    set_race("demon");
    set_name("vrock");
    set_short("vrock");
    set_long("Oh what a big vulture this is! .. Hmm .. On second thought it\n"+
             "looks somewhat different. It has human hands with long, sharp\n"+
             "fangs and a wicked, intelligent stare.\n"+
             "   ARGH ... . . it's a VROCK!!! - better run fool\n");
    set_chance(15);
    set_spell_mess1("The Vrock flaps his wings.");
    set_spell_mess2("The Vrock flaps his wings, almost knocking you over.");
    set_spell_dam(50);
    set_attacks(4);
    set_attacks_change(100);
    set_size(4);
}

int query_str() { return 60; }
