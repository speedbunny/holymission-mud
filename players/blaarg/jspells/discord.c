inherit "/spells/spell";
#include "/spells/spell.h"

reset(int arg) {

    ::reset(arg);
    if(arg) return;
    set_name("Discord");
    set_syntax("cast 'discord' [opponent]");
    set_kind( AGGRESSIVE );
    set_save_vs( MINDEFFECTIVE );
    set_save_vs_info( "to negate" );
    set_cost( 50 );
    set_speed( 2 );
    set_guild_allowed( 4, 10 );
    set_player_help( +
	"Using the Power of the Force, you can make a living object\n" +
	"in a room panic and start attacking another living object.\n");
}

release_spell(arg, act_skill, max_skill) {

    object  att, tar, *inv;
    int     i, l, d, m, dam;
    string  att_name, tp_name;

    att = check_target(arg);
    if(!att) return;
    if(valid_living(att)) return;

    d = TP->query_level();

    if(check_success(act_skill,max_skill)) {
        switch(att->do_save(Skind,Ssave,0,0,this_object())) {
            case IMMUNE:        dam = 0; break;
            case SAVED:         dam = 0; break;
            default:            dam = 1;
        }
        att_name = att->query_name();
        tp_name  = TPN;

        printf("Using the Force, you make " +att+ " hallucinate...\n" +
	       att+ " begins to panic and goes into a frenzied attack!\n"); 
        tell_object(att,TPN+" shows you your worst nightmares, causing\n" +
		      "you to panic... you start to feel hatred toward\n" +
		      "everyone in the room...\n");
	if (dam) {
	inv = all_inventory(environment(TP));
	m = sizeof(inv);
	tp_name = TPN;
	tar=allocate(m);
	l=0;
	for( i=0; i<m; i++) {
	  if(living(inv[i]) && inv[i]!=TPN && inv[i]!=att) tar[l++]=i;
	  if (l<1) { 
		printf(att+" turns on you!");
		att->attack_object(tp_name);  }

          else { att->attack_object(tar);}
	}
    }
}

