inherit "/obj/monster";
inherit "/players/shadowmonk/inherit/feelings.c";
#include "/players/shadowmonk/include/defs_area1.h"
#include "/players/shadowmonk/include/stanfeeling.h"
#include "/players/shadowmonk/include/stanadverb.h"

#define DELAY   0
#define XAN     "Xanchronas "
#define XSAY 	"Xanchronas says: "
#define XTELL 	"Xanchronas tells you: "
#define IGNORE  tell_arr +=({ "Xanchronas ",\
		      "ignores anything said, as he didn't hear his name.",\
			      "Xanchronas ",\
		      "ignores anything said, as he didn't hear his name.",\
			      TP })

int 	concentrating, delay;
mixed  *tell_arr;
mapping level;

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    get_feelings();
    set_name 	
	("xanchronas");
    set_alias_list
	( ({ "dragon", "silver dragon", "xanchronas" }) );
    set_living_name
	("xanchronas");
    set_short	
    	("Xanchronas, the Silver Dragon");
    set_long	
	("Before you stands Xanchronas, the oldest and wisest among the "+
	 "last of the Silver Dragon council. He looks down at you with "+
	 "the wisdom of centuries in his eyes. His silver scales don't "+
	 "show the years he has spent on this earth.\n");
    set_race("dragon");
    set_level(90);
    set_gender(1);
    set_size(6);
    set_aggressive(0);
    set_hp(100);
    set_wc(75);
    set_ac(25);
    set_al(1000);
    set_number_of_arms(2);
    set_language_skill(0, 100);
    set_language_skill(2, 100);
    set_speaks_in(0);
    set_dead_ob(TO);
    set_prevent_poison(1);
    add_money(10000);

    CLONE( "/obj/shadows/resist_acid_shad" )   -> start_shadow( TO, 0 );
    CLONE( "/obj/shadows/resist_fire_shad" )   -> start_shadow( TO, 0 );
    CLONE( "/obj/shadows/resist_elect_shad" )  -> start_shadow( TO, 0 );    
    CLONE( "/obj/shadows/resist_cold_shad" )   -> start_shadow( TO, 0 );    

    change_spell("chainlightning", 80, 95, 1);
    change_spell("fireball", 95, 95, 1);
    change_spell("lightning bolt", 95, 95, 0);
    change_spell("meteor swarm", 75, 95, 2);
    change_spell("summon wind", 95, 95, 1);
    enable_commands();

    delay=0;
}

void monster_died(object ob) {
    if( !( ( ob = TO -> query_attack() ) -> query_immortal() ) )
        shout( CAP( ob -> RNAME ) +" has killed Xanchronas, the oldest on "+
					"the Silver Dragon council !!\n");
    TTP("You have killed Xanchronas, beware for revenge of the Silver "+
	"Dragon council !!");
}

status concentrate(object vic) {
    if( vic && !query_concentrating() )
        switch( random(111) ) {
	    case 0 .. 24:
		concentrating = 1;
		npc_process_spell("fireball", vic);
		break;
	    case 25 .. 49:
		concentrating = 1;
		npc_process_spell("summon wind", vic);
		break;
	    case 50 .. 74:
		concentrating = 1;
		npc_process_spell("lightning bolt", vic);
		break;
	    case 75 .. 89:
		concentrating = 1;
		npc_process_spell("chainlightning", vic);
		break;
	    default:
		concentrating = 1;
		npc_process_spell("meteor swarm", vic);
		break;
	}
  concentrating = 0;
  return 1;
}

status query_concentrating() {
    return concentrating;
}

void init() {
    monster::init();
    add_action( "no_hold", "hold" );
}

status no_hold() {
    if( !random(4) ) {
        TTP( "Xanchronas counters your hold spell !!!" );
        return 1;
    }
}

status alone(object player) { 
    int     i;
    object *people;

    people = all_inventory( ENV( TO ) );

    for( i=sizeof(people)-1; i>=0; i-- ) 
        if( people[i] == TO || people[i] == player || !living(people[i]) ) 
            people=del_array(people, i);
    if( sizeof(people) == 0 )
	return 1;
    return 0;
}

void do_feeling( string str ) {
    command( str );
}


void catch_tell(string str) {
    string a, b, c, *arr;
    int    i, j, sz;
    object who;
    
    str += ".";
    if(!tell_arr)
	tell_arr=({});
    if(!level)
	level=([]);

    set_heart_beat(1);

    if( member_array(TPN, m_indices( level ) ) == -1 ) {
	if( !level[TPN] )
	    level[TPN] = ({});
	level[TPN] += ({ 0, 0, 0, 0, 0 });
    }
    if( sscanf( str, "%s@SCROLL%s", a, b )==2 ) {
        TME(a+".");
	if( living( FP( a ) )==0 || level[a][2] != 1)
	    return;
        MOVE( CLONE( PATH+"items/quest_scroll" ), FP( a ) );
	TOB("Xanchronas hands you a scroll.", FP( a ) );
	TOP("Xanchronas hands "+CAP(a)+" a scroll.", FP( a ) );
        return; 
    }
    if( sscanf( str, "%s@TRANS%s", a, b )==2 ) {
	if( living( FP( a ) )==0 || level[a][3] != 1)
	    return;
	level[a][4] = 1;
        move_object( FP( a ), "/room/church" );
	TOB("You see a bliding light and you find yourself somewhere else.",
			FP(a) );
	TENV("Xanchronas transports "+CAP(a)+" out of the castle." );
        return; 
    }
    if( TP==TO || sscanf(str, "You%s", a) == 1 ) 
	return;
    if(sscanf(str, "%sello%s", a, b) == 2 ||
       sscanf(str, "%ssays: hi%s", a, b) == 2 ||
       sscanf(str, "%ssays: Hi%s", a, b) == 2 ||
       sscanf(str, "%seya%s", a, b) == 2 ) {
        if( !alone( TP ) )
	    if( sscanf(b, "%sanchrona%s", a, c) !=2 ) {
		IGNORE;
 		return;
	    }
	level[TPN][0] = 1;
        if( level[TPN][0] != 1 ) 
            tell_arr += ({  XSAY, "Welcome to my home, "+TPCN+".", 
 			    XTELL, "Greetings, "+TPCN+".", TP });
        else tell_arr += ({  XSAY, "Greetings, "+TPCN+".", 
	  		     XTELL, "Greetings, "+TPCN+".", TP });
        tell_arr += ({ XSAY, "How may I be of service to you, "+TPCN+".",
			"", "", TP });
	return;
    }
    if(sscanf(str, "%sow are y%s", a, b) == 2) {
        if( !alone( TP ) )
	    if( sscanf(b, "%sanchrona%s", a, c) !=2 ) {
		IGNORE;
		return;
	    }
	level[TPN][0] = 1;
        if( level[TPN][0] != 1 ) 
            tell_arr += ({  XSAY, "Welcome to my home, "+TPCN+".", 
			    "", "", TP }); 
        tell_arr += ({  XSAY, "I am doing very well thank you.", 
        		XTELL, "Busy, very busy "+TPCN+".", TP,
			XSAY, "What can I do for you, "+TPCN+".",
			"", "", TP });
	return;
    }
    if( sscanf(str, "%s valley of lava%s", a, b) == 2 ||
        sscanf(str, "%smyster%s", a, b) == 2 ) {
        if( level[TPN][0] != 1 ) {
	    tell_arr += ({  XSAY, "We don't say hello anymore, "+TPCN+"?", 
		       	"", "",	TP });
	    return;
        }
	level[TPN][1] = 1;
        tell_arr += ({  XSAY,"So you want to discover the mysteries of the "+
			"valley of lava.", "", "", TP,
			XSAY, "You will have to prove yourself to me first "+
			"then.", "", "", TP });
        return; 
    }
    if (sscanf(str, "%sprove%s", a, b) == 2) {
        if( level[TPN][0] != 1 ) {
	    tell_arr += ({  XSAY, "We don't say hello anymore, "+TPCN+"?", 
		       	"", "",	TP });
	    return;
        }
        if( level[TPN][1] != 1 ) {
	    tell_arr += ({  XSAY, "What was that about prove, "+TPCN+"?", 
		       	"", "",	TP });
	    return;
        }
	level[TPN][2] = 1;
        tell_arr += ({  XSAY, "Solve this puzzle I have for you, "+TPCN+".", 
			"", "",	TP, "", "", "", TPN+"@SCROLL", TO,
			XSAY,"Look at the puzzle and then listen carefully.",
			"", "",	TP });
        return;
    }
    if(sscanf(str,"%s reads the puzzle given by Xanchronas%s", a, b)==2) {
	if( level[TPN][1] !=1 || level[TPN][2] != 1)
	    return;
	level[TPN][3] = 1;
	tell_arr += ({  XSAY, "As you can see "+TPCN+", there are nine "+
			"empty sqaures.", "", "", TP,
			XSAY, "Each of these sqaures need to be filled, and"+
			" you can do that by asking questions.", "", "", TP,
			XSAY, "I will transport you away from here "+TPCN+
			", so you can start.", "", "", TP,
	                "Xanchronas utters ","some strange words.","","",TP, 
			"", "", "", TPN+"@TRANS", TO, "", "",
			XTELL, "Come back to me when you have solved "+
			"the puzzle.", TP });
        return;
    }
    if( !arr )
	arr = ({});
    while( strstr( str, "." ) != -1 )
        str = str[0..strlen(str)-2];
    arr += explode( str, " " );
    for( i=0, sz=sizeof(arr), a="", b=""; i<sz; i++ ) {
        if( ( j=strlen( arr[i] )-1 ) > 1 ) {
            if( arr[i][j] == 's' )
                arr[i]=arr[i][0..--j];
            if( arr[i][j] == 'e' )
                arr[i]=arr[i][0..--j];
        }
        if( j > 3 )
            if( arr[i][j-2..j] == "ing" )
                arr[i]=arr[i][0..j-=3];
        if( member_array( c=arr[i], m_indices(SFEELINGS) ) != -1 || 
            member_array( c=arr[i]+"e", m_indices(SFEELINGS) ) != -1 )  
            a=c;
        if( member_array( c=arr[i], SADVERBS ) != -1 ) 
            b=" "+c;
    }
    if( a != "") {
        if( member_array( "you", arr ) != -1 ) {
            TME( "command: <"+ a + b +" "+ TPN +">" );
            call_out( "do_feeling", 1, ( a + b +" "+ TPN ) );
        }
        return;
    }
    log_file("xanchronas", str + "\n");
}

void heart_beat() {
    int i;
    object *envir;

    envir = all_inventory( ENV( TO ) );
    for( i=sizeof(envir)-1; i>=0; i-- ) 
        if( envir[i] == TO || !living( envir[i] ) ) 
            envir = del_array( envir, i);
    if( !sizeof(tell_arr) && !sizeof(envir)  ) {
	set_heart_beat(0);
        return;
    }
    if(!sizeof(tell_arr)) {
/*        switch( random(50) ) {
	    case 0: 
		TENV("Xanchronas smiles amusedly.");
		break;
	    case 10: 
		TENV("Xanchronas looks something up in a huge book.");
		break;
	    case 20: 
		TENV("Xanchronas is making some puzzles.");
		break;
	}
*/	return;
    }
    if( delay>=DELAY )
	delay=0;
    else {
	delay++;
	return;
    }
    if( living( tell_arr[4] ) != 0  ) {
	if( ENV( TO ) == ENV( tell_arr[4] ) && tell_arr[1] != "" ) 
	    TENV( tell_arr[0] + tell_arr[1] );
	else if(tell_arr[3]!="") 
	    TOB( tell_arr[2] + tell_arr[3], tell_arr[4] );
    }
    tell_arr = del_array(tell_arr, 4);
    tell_arr = del_array(tell_arr, 3);
    tell_arr = del_array(tell_arr, 2);
    tell_arr = del_array(tell_arr, 1);
    tell_arr = del_array(tell_arr, 0); 
}
