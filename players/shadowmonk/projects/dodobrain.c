inherit "/obj/monster";
#include "/players/shadowmonk/include/defs.h"

string *tell_arr;

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name
	("dodoBrain");
    set_alt_name
	("dodo");
    set_living_name
	("dodobrain");
    set_short
	("DoDoBrain the ClueLess.");
    set_long
	("You see a human male. He looks kinda weird out of his eyes."+
	 "Rumors say that he has an unlimited graving for questions, "+
	 "even if he doesn't have the answers.\n");
    set_level(100);
    set_race("human");
    set_gender(1);
    set_al(1000);
    set_aggressive(0);
    set_prevent_poison(1);
    set_no_steal();
    set_no_ears();
    set_number_of_arms(2);
    enable_commands();
}

catch_tell(str) {
    string a, b, c, piece;
    
    if(TP==TO) 
	return 1;
    if(!tell_arr)
	tell_arr=({});
    set_heart_beat(1);
    if( sscanf(str, "%sello%sod%s", a, b, c) == 3 ||
        sscanf(str, "%s hi%sod%s", a, b, c) == 3 ||
        sscanf(str, "%s Hi%sod%s", a, b, c) == 3 ) {
        tell_arr += ({ "Welcome to Holy Mission, "+TPCN+".", 
			"Greetings, "+TPCN+".", TPN });
	return 1;
    }
/*    if( sscanf(str, "%ssmiles%s", a, b) == 2  ||
    	sscanf(str, "%skicks%s", a, b) == 2  ||
    	sscanf(str, "%slaughi%s", a, b) == 2  ||
    	sscanf(str, "%slicks%s", a, b) == 2 )  {
	piece=extract(str, strlen(a), strlen(str)-strlen(b)-2 );
        if( sscanf(piece, "%se", a) == 1 )
	    piece= extract(piece, 0, strlen(piece) - 2 );
        piece += "ing"; 
        tell_arr += ({ piece, piece, TPN });
	return 1;
    }
*/

    if( sscanf(str, "%s leaves %s", a, b) != 2 && 
	sscanf(str, "%s arrives. %s", a, b) != 2 )
        log_file("dodo", str + "\n");
}

heart_beat() {
    int i;
    object *people;

    people = all_inventory( ENV( TO ) );
//    TME("sz people: "+sizeof(people)+"sz tell_arr: "+sizeof(tell_arr) );
    for( i=sizeof(people)-1; i>=0; i-- ) 
        if( people[i] == TO || !living( people[i] ) ) 
            people = del_array( people, i);
    if(!sizeof(tell_arr) && !sizeof(people)  ) {
	set_heart_beat(0);
        return;
    }
    if(!sizeof(tell_arr)) {
        if(random(80) == 1) 
	    TAL("DoDoBrain is bored, and tries to stand on his head...");
        return;
    }
    if( ENV( TO ) == ENV(find_player(tell_arr[2])) && tell_arr[0] != "" ) 
        TENV( "DoDoBrain says: "+tell_arr[0] );
    else if(tell_arr[1]!="") 
	TOB( "DoDoBrain tells you: "+tell_arr[1], find_player(tell_arr[2]) );
    tell_arr = del_array(tell_arr, 2);
    tell_arr = del_array(tell_arr, 1);
    tell_arr = del_array(tell_arr, 0); 
}

run_away() { 
    return 0; 
}

void attack() {
    if(attacker_ob) query_ghost();
}

status query_ghost() {
    object *objs;
    int     i;

    TAL( "Dodobrain doesn't like to fight, so he snaps his fingers and the "+
	 "fighting stops.\n");
    objs=all_inventory(environment());
    for( i=0; i<sizeof(objs); i++ ) {
        objs[i]->stop_fight();
        objs[i]->stop_fight();
        objs[i]->stop_hunter(1);
    }
    return 1;
}
