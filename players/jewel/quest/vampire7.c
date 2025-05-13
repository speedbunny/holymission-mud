inherit "obj/npc";

reset (arg) {
    ::reset(arg);
    if (!present("blood glass")) {
        move_object(clone_object("/players/jewel/quest/bglass"),this_object());
    }
    if (arg) return;
    set_name("vampire guest");
    set_alt_name("guest");
    set_alias("vampire");
    set_level(40);
    set_al(-500);
    set_ac(18);
    set_wc(25);
    set_chance(20);
    set_spell_dam(40);
    set_spell_mess1("The vampire stares into his opponents eyes\n");
    set_spell_mess2("The vampire drains you\n");
    set_aggressive(0);
    set_race("undead");
    set_short("Vampire Guest");
    set_long("A vampire on a vampire party.\n");
    set_attacks(3);
    set_attacks_change(50);
    add_money(500+random(500));
}
