#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if (arg) return;
    set_name("large demon");
    set_alt_name("demon");
    move_object(clone_object("/players/sherman/hills/claws1"),this_object());
    set_level(35);
    set_str(50);
    set_dex(50);
    set_hp(2000);
    set_al(-500);
    set_ac(18);
    set_aggressive(1);
    set_wc(25);
    set_race("demon");
    set_short("Large demon");
    set_long("A large fire demon with long claws.\n");
    set_chance(15);
    set_spell_mess1("The demon flames his opponent");
    set_spell_mess2("The demon burs you");
    set_spell_dam(60);
    command("wield claws",this_object());
}
