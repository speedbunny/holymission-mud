inherit "obj/monster";
#define ARM "/players/baalthasar/armour/"
#define WEA "/players/baalthasar/weapons/"

reset(arg) {
    ::reset(arg);
    if(!arg) {

 set_name("soldier");
	set_race("human");
set_level(8);
set_hp(750);
	set_al(200);
        set_gender(1);
 set_short("A soldier");
 set_long("This is one of the weaker warriors of Castle Strongheart \n"
+"but nonetheless he would give his life in service of his \n"
+"Goddess, Gwendolyn. \n");
add_money(200+random(500));
move_object(clone_object(WEA + "shortsd"), this_object());
command("wield shortsword");
move_object(clone_object(ARM + "gscale"), this_object());
command("wear armour");
move_object(clone_object(ARM + "gshield"), this_object());
command("wear shield");
move_object(clone_object(ARM + "gboots"), this_object());
command("wear boots");
set_ac(12);
set_aggressive(0);
set_chance(20);
set_spell_mess1("The soldier makes a quick dodge then kicks hard. \n");    
set_spell_mess2("The soldier makes a quick dodge then kicks you painfully in the stomach! \n");
set_spell_dam(25);
    }
}

