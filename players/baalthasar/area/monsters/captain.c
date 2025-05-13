inherit "obj/monster";
#define ARM "/players/baalthasar/armour/"
#define WEA "/players/baalthasar/weapons/"

reset(arg) {
    ::reset(arg);
    if(!arg) {

set_name("captain");
	set_race("human");
set_level(15);
set_hp(1500);
	set_al(200);
        set_gender(1);
set_short("The Captain");
set_long("The commanding officer of the soldiers of this castle. \n");
move_object(clone_object(WEA + "glongsd"), this_object());
command("wield longsword");
move_object(clone_object(ARM + "gscale"), this_object());
command("wear armour");
move_object(clone_object(ARM + "gshield"), this_object());
command("wear shield");
move_object(clone_object(ARM + "gboots"), this_object());
command("wear boots");
set_ac(12);
set_aggressive(1);
set_chance(22);
set_spell_mess1("The captain bashes his enemie's face with a THUD!!\n");
set_spell_mess2("The captain deftly thrusts your weapon aside and pounds you in the face!\n");
set_spell_dam(65);
    }
}

