inherit "obj/monster";

reset (arg) {
    ::reset(arg);
    if (!present("teeth")) {
        move_object(clone_object("/players/jewel/quest/teeth2"),this_object());
    }
    if (arg) return;
    set_name("vampire guard");
    set_alt_name("guard");
    set_alias("vampire");
    set_level(20);
    set_al(-250);
    set_ac(15);
    set_wc(40);
    set_aggressive(1);
    set_race("undead");
    set_short("Vampire Guard");
    set_long("A unfriendly vampire, he does not want you to enter.\n");
    add_money(500+random(500));
    command("wield teeth",this_object());
}
