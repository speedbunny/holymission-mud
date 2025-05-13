inherit "obj/monster";
#define ENV environment
object who;

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("Soozie's boyfriend");
	set_alias("boyfriend");
	set_short("Soozie's Boyfriend");
	set_long("This is Soozie's boyfriend.  He has BIG muscles.\n");
	set_race("man");
	set_hp(1000000);
	set_level(100);
	set_wc(1000);
	set_ac(1000);
	set_aggressive(0);
    }
}

heart_beat() {
    ::heart_beat();
    who=find_player("soozie");
    if (who && ENV(who)) {
	if (ENV(who) != ENV(this_object())) {
	    say("Soozie's boyfriend drools after Soozie.\n");
	    move_object(this_object(),ENV(who));
	    say("Soozie's boyfriend flexes as he enters following Soozie.\n");
	}
    }
}
