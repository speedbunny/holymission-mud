inherit "/spells/spell";
#include "/spells/spell.h"

void reset(int arg) {

    ::reset(arg);
    if(arg) return;
    set_name("Fearall");
    set_syntax("cast 'fear all'");
    set_kind( NON_AGGRESSIVE );
    set_save_vs( MINDEFFECTIVE );
    set_save_vs_info( "to negate" );
    set_cost( 0 );
    set_speed( NEXT_HB );
    set_guild_allowed( 4, 1 );
    set_player_help(
      "By concentrating with your mind, you can cause an impulse in\n" +
      "another living being to run away in sheer terror.\n");
}

void release(string arg, int act_skill, int max_skill) {

    object  att,*inv;
    int     d,i,dam;
    string  att_name, tp_name;

    /*    
	att = check_target(arg);
	if(!att) return;
	if(!valid_living(att)) return;
    */

    if(check_success(act_skill,max_skill)) {
	inv = all_inventory(environment(TP));
	d = sizeof(inv);
	tp_name = TPN;
	for( i=0; i<d; i++) {
	    att = inv[i];
	    if (!valid_living(att)) continue;
	    switch(att->do_save(Skind,Ssave,0,0,this_object())) {
	    case IMMUNE:        dam = 0; break;
	    case SAVED:         dam = 0; break;
	    default:            dam = 1;
	    }
	    if(environment(TP)->query_property("no_fear")){
		write("You cannot 'fearall' in this area.\n");
		return;
	    }
	    if ( dam )
		att->run_away();
	}
	printf("You begin to concentrate on all linving in this room.\n");
	say(tp_name+" begins to concentrate.\n",
	  TP);
    }
}

