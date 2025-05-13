inherit "players/qclxxiv/mymonster";
string last_attacker_name;
object last_attacker;

reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(10,({
		"schlllppp...the eelworm nibbles on a piece of fibril.\n",
		"An eelworm is enjoying the tasty root fibre.\n",
		"The eelworm seems to be afraid of you.\n",
	  }));
	 load_a_chat(10,({
        "ouch....please don't do that.\n",
        "EEK...a giant eelworm killer is attacking me! HELP!!!\n",
        "I didn't do you any harm.\n",
	  }));
	set_name("eelworm");
	set_level(3);
   	set_wc(8);
	set_ac(3);
   	set_hp(100);
	set_sp(45);
    set_al(10);
    load_match(this_object(), ({ "restore_heart_beat", 
								 ({"grazes you", "hits you",}),
							 }));
   	set_aggressive(0);
	set_short("eelworm");
	set_long("A friendly eelworm, eating it's way through the root system.\n");
}

refresh_stats(attacker_ob)
{
    if (attacker_ob && present(attacker_ob, environment(this_object())) ) {
		set_ac( attacker_ob->query_ac() + attacker_ob->query_n_ac() ); /*new*/
		set_wc( attacker_ob->query_wc() + attacker_ob->query_level()/5 ); 
		if (query_wc() < attacker_ob->query_level())
			set_wc( atacker_ob->query_levell() );       /* NEW:-)*/
	}
	set_sp(45);
}

attacked_by(attacker) {
	int atlev, newhp;
	if (attacker->query_name()!=last_attacker_name) {
		last_attacker_name = attacker->query_name();
		last_attacker = attacker;
		atlev = attacker->query_level();
		set_level( atlev + atlev/5 );
		refresh_stats(attacker);
		/* as there are 30 eelworms in the root system (assured evry reset)
		// hp of max(10,player's hp+sp) is really sufficient:-) */
		newhp = attacker->query_hp()+attacker->query_sp()
				+attacker->query_level()*10;  /* OK more NEW */
		if (newhp<10) newhp=10; 
		set_hp(newhp);
	}
	::attacked_by(attacker);
}

heart_beat()
{
	refresh_stats(last_attacker);
	::heart_beat();
}

restore_heart_beat(str) {
	set_heart_beat(1);
}

monster_died() {
