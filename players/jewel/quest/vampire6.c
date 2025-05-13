inherit "obj/monster";

reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_name("vampire lady");
    set_alt_name("vampire");
    set_alias("vampiress");
    set_level(20);
    set_al(-250);
    set_ac(15);
    set_wc(25);
    set_aggressive(1);
    set_race("undead");
    set_short("Vampiress");
    set_long("A sexy looking lady with long teeth.\n");
    move_object(clone_object("/players/jewel/quest/capev"),this_object());
    command("wear cape",this_object());
}
