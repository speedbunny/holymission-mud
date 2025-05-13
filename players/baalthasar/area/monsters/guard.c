inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(!arg) {

	set_name("guard");
	set_race("human");
set_level(12);
set_hp(1250);
set_ep(700000);
	set_al(200);
        set_gender(1);
        set_alias("guard");
	set_short("A castle guard");
	set_long("One of the many and proud defenders of the great Castle \n"
	  +"Strongheart!  He's a devout follower of Gwendolyn, and would \n"
	  +"risk anything to keep sacred her domain. \n");
	set_wc(15);
set_ac(12);
set_aggressive(0);
set_chance(20);
set_spell_mess1("You watch, impressed, as the guard slices deep into his opponent. \n");
set_spell_mess2("You grind your teeth in pain as the guard's sword bites deep! \n");
set_spell_dam(50);
    }
}

