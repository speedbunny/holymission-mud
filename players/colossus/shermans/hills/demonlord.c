#pragma strict_types

inherit "obj/monster";

void reset(int arg){
    object ob;
    ::reset(arg);
    if (!arg) {
	set_name("demonlord");
	set_alt_name("demon");
	set_level(80);
	set_str(100);
	set_dex(100);
	set_hp(8000);
	set_al(-1000);
	set_ac(30);
	set_aggressive(1);
	set_wc(50);
	set_race("demon");
	set_short("The Demonlord");
	set_long("A big red demon.\n");
	set_chance(10);
	set_spell_mess1("The demonlord burns his opponent");
	set_spell_mess2("The demonlord flames you");
	set_spell_dam(100);
	if(sizeof(explode(file_name(this_object()),"#"))>1)
	    "players/sherman/swords/sword2"->xxx();
	move_object(clone_object("players/sherman/hills/crystal"),this_object());
	move_object(clone_object("players/sherman/hills/bracers"),this_object());
	command("wield sword",this_object());
	command("wear bracers",this_object());
	ob=clone_object("/players/llort/guild/obj/fireshield");
	ob->start_shadow(this_object(),-1);
    }
}

