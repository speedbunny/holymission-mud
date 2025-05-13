#include "/players/qclxxiv/mymonster.h"
string last_attacker_name;
object loot1;

reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(10,({
		"Electric eel swims around.\n",
		"Electric eel shivers and curls.\n",
		"Electric eel looks at you.\n",
	  }));
	 load_a_chat(10,({
        "Electric eel curls and shivers.\n",
        "Electric eel seems to prepare for another electric shock.\n",
        "Electric eel discharges. A miniature lightning hardly misses you.\n",
	  }));
	set_name("electric eel");
	set_alias("eel");
	set_race("eel");
	set_level(3);
   	set_wc(8);
	set_ac(10);
   	set_hp(700);
	set_sp(45);
   	set_spell_mess1(
"Electric eel discharges. Local lightning strikes its attacker. A terrible shock.");
   	set_spell_mess2(
	"Electric eel discharges. Local lightning strikes you. A terrible shock.");
	set_chance(20);
	set_spell_dam(50);
    set_al(-10);
    load_match(this_object(), ({ "restore_heart_beat", 
								 ({"grazes you", "hits you",
									"smashes you", "tickles you", }),
							 }));
   	set_aggressive(1);
	set_short("Electric eel");
	set_long("An electric eel. It's about 8 feet long and looks mean.\n");
}

refresh_stats()
{
    if (attacker_ob ) {
  /*  if (attacker_ob && present(attacker_ob, environment(this_object())) ) {*/
		set_ac( attacker_ob->query_ac() + attacker_ob->query_n_ac() ); /*new*/
		set_wc( attacker_ob->query_wc() + attacker_ob->query_level()/4 ); 
		if (query_wc() < attacker_ob->query_level())
			set_wc( attacker_ob->query_level() );       /* NEW:-)*/
		if (query_wc() > 30) set_wc( 30 );
	}
	set_sp(0);
}

attacked_by(attacker) {
	int atlev, newhp;
	if (attacker->query_name()!=last_attacker_name) {
		last_attacker_name = attacker->query_name();
		atlev = attacker->query_level();
		set_level( atlev + atlev/5 );
		refresh_stats();
		newhp = 2* ( attacker->query_hp()+attacker->query_sp() ); 
		if (newhp<20) newhp=20; set_hp(newhp);
	}
	::attacked_by(attacker);
}

heart_beat()
{
	refresh_stats();
	::heart_beat();
}

restore_heart_beat(str) {
	set_heart_beat(1);
}

second_life() {
	if (!loot1) {
		say(
		"Electric eel charges up its electric gland..but fails to use it...\n");
		PLACE_IN_THIS(loot1,"/players/qclxxiv/leaf4/eelgland");
	}
	return 0;
}

