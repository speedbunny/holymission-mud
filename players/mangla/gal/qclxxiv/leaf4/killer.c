inherit "players/qclxxiv/mymonster";
reset(arg) {
        ::reset(arg);
	 if (arg) return;
	set_name("Ice-cold mist and water");
	set_level(30);
   	set_wc(100);
	set_ac(100);
   	set_hp(2100);
	set_ep(100000); 
	set_sp(5);
   	set_aggressive(0);
   	set_short("Ice-cold mist and water");
}

/* needed to let area kill a player who moves thru it without a guide */
do_kill( obj ) { /* assumes obj already drained to very low hp */
	obj->hit_player(1000); /* should do 'em */
}
