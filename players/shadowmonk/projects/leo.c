inherit "/obj/monster";
#include "/obj/lw.h"

#define GM		"guild/master"

#define TTP(x)		writelwnl(x)
#define TOP(x,y)	say(lwnl(x), y)  
#define TAL(x)          tell_room(environment(), lwnl(x))
#define TOB(x,y)	tell_object(y, lwnl(x))
#define TME(x) 		tell_object( find_player( "shadowmonk" ), lwnl(x) )


#define TP		this_player()
#define NAME		query_real_name()
#define LVL		query_level()
#define TPN		TP->NAME
#define TPCN		capitalize(TP->NAME)
#define ENV		environment

string *tell_arr;
object  give_him_castle;


void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name
	("Leo");
    set_alt_name
	("leo");
    set_living_name
	("leo");
    set_short
	("Leo the Archwizard");
    set_long
	("You see a old man with a very long white beard. He seems "+
	 "very wise and still very capable in the art of magic.\n");
    set_level(40);
    set_race("human");
    set_gender(1);
    set_al(1000);
    add_money(2000 + random(3000));
    enable_commands();
}

catch_tell(str) {
    string a, b, c;
    
    if(TPN=="Leo")
	return 1;

    if(!tell_arr)
	tell_arr=({});

    set_heart_beat(1);

    if(sscanf(str, "%sello%sleo%s", a, b, c) == 3 ||
       sscanf(str, "%sello%sLeo%s", a, b, c) == 3 ||
       sscanf(str, "%s hi%sleo%s", a, b, c) == 3 ||
       sscanf(str, "%s hi%sLeo%s", a, b, c) == 3 ||
       sscanf(str, "%s Hi%sleo%s", a, b, c) == 3 ||
       sscanf(str, "%s Hi%sLeo%s", a, b, c) == 3) {
        tell_arr += ({ "Welcome, "+TPN+".", "Greetings, "+TPCN+".", TPN });
	if( TP->LVL == GM->query_levels( TP->query_guild() ) )
	    tell_arr += ({ "Now that you are a wizard, you can have a castle of "+
			   "your own, "+TPCN+".", "", TPN });
	return;
    }
    if (0 && sscanf(str, "%sgive%scastle%s", a, b, c) == 3 ||
	sscanf(str, "%swant%scastle%s", a, b, c) == 3) {
	if( TP->LVL == GM->query_levels( TP->query_guild() ) ) {
	    castle();
	    return;
	}
	tell_arr += ({ "What! Give a castle to you?", "If you want to talk "+
		       "about getting a castle, come and see me at the Wizards "+
		       "Hall.",  TP->NAME });
	return;
    }
    if (sscanf(str, "%s gives %s to Leo.", a, b) == 2) {
	object ob;
	ob = present(b, this_object());
	if (!ob || !call_other(ob, "id", "orc slayer"))
	    return;
	tell_arr += ({ "Well done "+TPCN+". \n"+
		       "You have fullfilled this quest.", "", TPN });
	call_other(TP, "set_quest", "orc_slayer");
	destruct(ob);
	return;
    }
    if (sscanf(str, "%s arcanarton%s", a, b) == 2) {
        tell_arr += ({ "Search for the jem of arcanarton at the Isle of Magi.",
		       "Search for the jem of arcanarton at the Isle of Magi.", TPN });
        tell_arr += ({ "The staff is somewhere near the village.", 
		       "The staff is somewhere near the village.", TPN });
        return; 
    }
    log_file("LEO", str + "\n");
}

heart_beat() {
    int i;
    object *leoenv;

    leoenv = all_inventory( ENV( this_object() ) );

    for( i=sizeof(leoenv)-1; i>=0; i-- ) 
        if( leoenv[i] == this_object() || !living( leoenv[i] ) ) 
            leoenv = del_array( leoenv, i);
    if(!sizeof(tell_arr) && !sizeof(leoenv)  ) {
	set_heart_beat(0);
        return;
    }
    if(!sizeof(tell_arr)) {
        if(random(80) == 1) 
	    say("Leo smiles.\n");
        return;
    }
    if( ENV(this_object()) == ENV(find_player(tell_arr[2])) && tell_arr[0] != "" ) 
        TAL( "Leo says: "+tell_arr[0] );
    else if(tell_arr[1]!="") 
	TOB( "Leo tells you: "+tell_arr[1], find_player(tell_arr[2]) );
    tell_arr = del_array(tell_arr, 2);
    tell_arr = del_array(tell_arr, 1);
    tell_arr = del_array(tell_arr, 0); 
}

castle() {
    write("You are now ready to take the step into true wizardhood. But, "+
	  "to do this, you must select one wizard that will take "+
	  "responsibility for you. He must also back up your claim of "+
	  "being a wizard, not by cheating. If you have no name so far, "+
	  "come back here again. \nNow give me the name: \n");
    input_to("castle2");
}

castle2(back_up_wiz) {
    string castle_name;
    string player_name;
    string save_name;
    int save_level;
    object wiz;

    return;
  
    if (back_up_wiz == "") {
	write("Welcome back.\n");
	return;
    }
    back_up_wiz = lower_case(back_up_wiz);
    save_name = name;
    save_level = level;
    if (!restore_object("players/" + back_up_wiz)) {
	write("There is no player with that name.\n");
	return;
    }
    name = save_name;
    if (level < 50) {
	write("That player is not full wizard !\n");
	level = save_level;
	return;
    }
    if (!present(back_up_wiz,environment())) {
	write("That wizard is not here right now.\n");
	return;
    }
    wiz = find_living(back_up_wiz);
    if (wiz->query_linkdeath()) {
	write("That wizard is currently linkdead.\n");
	return;
    }
    if (!wiz->query_sponsor()) {
	write("This wizard is not allowed to sponsor new wizards.\n");
	return;
    }

    level = save_level;
    castle_name = clone_object("room/port_castle");
    player_name = call_other(this_player(), "query_name", 0);
    call_other(castle_name, "set_owner", player_name);
    move_object(castle_name, this_player());
    log_file("SPONSOR", back_up_wiz + " : " +
	call_other(this_player(), "query_name") + " " + ctime(time()) + "\n");
    tell_object(this_player(),
		"\n" +
		"Congratulations, you are now a complete god with your own\n" +
		"castle. But beware, you can only drop it once !\n" +
		"When it is dropped, it can never be moved again.\n" +
		"You will get more wizard command at next log in.\n");
    call_other(this_player(), "set_level", this_player()->query_level()+1);
    call_other(this_player(), "set_title", " the wizard");
}


run_away() { 
    return 0; 
}
