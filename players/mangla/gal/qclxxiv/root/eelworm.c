inherit "players/qclxxiv/mymonster";
string last_attacker_name;

reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(10,({
		"Schlllppp...the eelworm nibbles on a piece of fibril.\n",
		"The eelworm is enjoying the tasty root fibre.\n",
		"The eelworm seems to be afraid of you.\n",
	  }));
	 load_a_chat(10,({
     "Eelworm says: Ouch .... please don't do that.\n",
     "Eelworm cries: Eek .... A giant eelworm killer is attacking me!\n",
    "Eelworm says: I didn't do you no harm !\n",
	  }));
   /* Changed by Dice to make the eelworm make the sounds  */
	set_name("eelworm");
	set_race("eelworm");
	set_level(3);
   	set_wc(9);
	set_ac(5);
   	set_hp(700);
	set_sp(45);
    set_al(10);
    load_match(this_object(), ({ "restore_heart_beat", 
								 ({"grazes you", "hits you",
									"smashes you", "tickles you", }),
							 }));
   	set_aggressive(0);
	set_short("eelworm");
	set_long("A friendly eelworm, eating it's way through the root system.\n");
}

refresh_stats()
{
    if (attacker_ob ) {
  /*  if (attacker_ob && present(attacker_ob, environment(this_object())) ) {*/
		set_ac( attacker_ob->query_ac() + attacker_ob->query_n_ac() ); /*new*/
		set_wc( attacker_ob->query_wc() + attacker_ob->query_level()/4 ); 
													 /* increased 8-5-83 */
		if (query_wc() < attacker_ob->query_level())
			set_wc( attacker_ob->query_level() );       /* NEW:-)*/
	}
	if (query_sp() > 45) 
		set_sp(45);
}

attacked_by(attacker) {
	int atlev, newhp;
	if (attacker->query_name()!=last_attacker_name) {
		last_attacker_name = attacker->query_name();
		atlev = attacker->query_level();
		set_level( atlev /*+ atlev/5*/ ); /* reduced 8-5-83 */
		if (attacker->query_guild()==7) set_ep(experience*6/10);
		else set_ep( experience*75/100 );
		refresh_stats();
		/* as there are 30 eelworms in the root system (assured evry reset)
		// hp of max(10,player's hp+sp) is really sufficient:-) */
		newhp = attacker->query_hp()+attacker->query_sp(); 
		newhp = newhp*3/2; /* increased 8-5-83 */
		if (newhp<10) newhp=10; set_hp(newhp);
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

