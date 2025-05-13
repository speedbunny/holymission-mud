inherit "obj/monster";

#define AO attacker_ob

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("liu kang");
    set_alias("kang");
    set_alt_name("liu");
    set_short("Liu Kang");
    set_long("Liu Kang, a martial artist who fights for Shaolin and seeks to\n"+
      "restore the tournament to its true form by winning the tournament.\n");
    set_level(14);
    set_hp(900);
    set_gender(1);
    set_race("human");
    add_money(250);
    set_wc(17);
    set_ac(9);
}
heart_beat(){
    ::heart_beat();
    if(AO && present(AO, environment()) ) {
	if(!random(5)) {
	    tell_object(AO, "Liu Kang nails you hard with a flying kick!\n");
	    say("Liu Kang nails "+AO->query_name()+" hard with a flying kick!\n", AO);
	    AO->hit_player(14);
	}
	else if (!random(6)) {
	    tell_object(AO, "Liu Kang throws a beam of fire at you, burning you!.\n");
	    say("Liu Kang burns "+AO->query_name()+" with a beam of fire!\n", AO);
	    AO->hit_player(10);
	}
    }
}
