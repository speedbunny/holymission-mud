#include "/players/nylakoorub/guild/defines.h"
#include "/obj/lw.h"

int do_timestop() {
    object target, env, *ob;
    string vag;
    int i, j;
    target = TP->query_attack();
    if(!target){
	write("You're not under attack.\n");
	return 1;
    }
    if(check_cost(TIMESTOP_COST, TIMESTOP_LEVEL)) {
	write("You're too mentally fatigued for that.\n");
	return 1;
    }
    env= environment(this_player());
    ob= all_inventory(env);
    j= sizeof(ob);
    vag= this_player()->query_real_name();
    for(i=0; i<j; i++){
	if(living(ob[i]) && ob[i]->query_attack())
	     { ob[i]->stop_fight();
	       ob[i]->stop_fight();
	       ob[i]->stop_hunter(1);
	       if(ob[i]->query_real_name() != vag){
		   tell_object(ob[i], capitalize(vag)+" seems to stop "+
		   "time completely! You stop fighting!\n");
		    }
	     }
	}
    write(
	"You stop time completely, which makes "+target->query_name()+" stop"+
	" attacking you!\n");
    say(lw(
	capitalize(vag)+" stops time which makes "+
	target->query_name()+" stop attacking.\n"));
    TP->restore_spell_points(COST(-TIMESTOP_COST));
    return 1;
}
