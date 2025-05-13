inherit "players/qclxxiv/root/eelworm";
#define PLACE_IN_THIS(OBJNAME, FILNAME)\
OBJNAME = place_in_this(OBJNAME,FILNAME,this_object());
int mynum;

set_num(n) { mynum = n; }
get_num() { return mynum; }

reset(arg) {
        ::reset(arg);
	 if (arg) return;
	 load_chat(10,({
		"Boxworm says: pprrrrrrttttttt.\n",
		"Boxworm says: qsppprrrrrrttttttt.\n",
		"The boxworm does not seem to be afraid of you.\n",
	  }));
	 load_a_chat(10,({
		"Boxworm says: QSPPPRRRRRRTTTTTTT.\n",
		"Boxworm says: PPRRRRRRTTTTTTT.\n",
		"Boxworm says: SQRTTRRTPPRRRRRRTTTTTTT.\n",
	  }));
	set_name("boxworm");
	set_alias("q174_boxworm");
	set_alt_name("worm");
	set_race("eelworm");
	set_level(9);
   	set_aggressive(0);
	set_short("boxworm");
	set_long(
"A boxworm. It looks a lot like an eelworm, only it's bigger and quite pale.\n"
+"In fact it's close to transparent. There seems to be something inside of it.\n"
		);
	set_whimpy(-1);
}

refresh_stats()
{
    if (attacker_ob ) {
		set_ac( attacker_ob->query_ac() + attacker_ob->query_n_ac() ); 
		set_wc( attacker_ob->query_wc() + attacker_ob->query_level()/4 ); 
		if (query_wc() < attacker_ob->query_level())
			set_wc( attacker_ob->query_level() );       
	}
	if (query_sp() > 45) set_sp(45);
}

attacked_by(attacker) {
	int atlev, newhp;
	if (attacker->query_name()!=last_attacker_name) {
		last_attacker_name = attacker->query_name();
		atlev = attacker->query_level();
		set_level( atlev ); 
		refresh_stats();
		newhp = attacker->query_hp()+attacker->query_sp(); 
		newhp = newhp*3/2; 
		if (newhp<10) newhp=10; 
		set_hp(newhp);
	}
	::attacked_by(attacker);
}

second_life() {
	object loot;
	PLACE_IN_THIS(loot,"/players/qclxxiv/leaf1/spiece");
	loot->set_num(get_num());
	return ::second_life();
}

reduce_hit_point(dam) {
	if (this_player()!=this_object()) 
		attacked_by(this_player());
	return ::reduce_hit_point(dam/2);
}

run_away() {
	tell_room(environment(this_object()),"The boxworm is not intimidated.\n");
	return 1;
}
