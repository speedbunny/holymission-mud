inherit "/spells/spell";
#include "/spells/spell.h"

void reset(int arg) {

    ::reset(arg);
    if(arg) return;
    set_name("Fear");
    set_syntax("cast 'fear' [opponent]");
    set_kind( NON_AGGRESSIVE );
    set_save_vs( MINDEFFECTIVE );
    set_save_vs_info( "to negate" );
    set_cost( 0 );
    set_speed( NEXT_HB );
    set_guild_allowed( 4, 1 );
    set_player_help(
      "By concentrating with your mind, you can cause an impulse in\n" +
      "another living being to run away int terror.\n");
}

void release(string arg, int act_skill, int max_skill) {

    object  att;
    int     d;
    string  att_name, tp_name;

    att = check_target(arg);
    if(!att) return;
    if( !valid_living(att) ) return;

    d = TPL;

    if(check_success(act_skill,max_skill)) {
	switch(att->do_save(Skind,Ssave,0,0,this_object())) {
	case IMMUNE:        d = 0; break;
	case SAVED:         d = 0; break;
	default:            d = d;
	}
	if(environment(TP)->query_property("no_fear")){
	    printf("You cannot cast 'terror' in this area.\n");
	    return;
	}
	att_name = att->query_name();
	tp_name  = TPN;

	printf("You begin to concentrate in your opponent.\n");
	say(tp_name+" begins to concentrate.\n",
	  TP,att);
	tell_object(att,"You feel mental switches being flipped.\n");

	if(d)
	    att->run_away();
    }
}

