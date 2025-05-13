/* wadden guide should always be cloned and renamed for a special player */
/* after cloning it call: set_myman( playerptr ). This will do all */

#include "/players/qclxxiv/mymonster.h"
object regionmaster, tidemaster;
object spliff,cap,lastgreet;
string dirs;
object myman;
string myman_name;
string cap_myman_name;
string spliff_from;
#define FOLLOW 0
#define GUIDE 1
#define WAIT 2
#define GOHOME 3
int mode;	/* FOLLOW at start */
#define TO 0
#define FROM 1
int waddendir; /* going TO 'island' at start */
string to_home;

is_wadden_guide() { return 1; }

set_myman( obj ) {
	if (!obj || !living(obj)) {
		call_out("self_destruct", 2);
		myman_name = "nobody";
	}
	else {
		myman = obj;
		myman_name = lower_case(myman->query_real_name());
	}
	cap_myman_name = capitalize(myman_name);
   	set_short(cap_myman_name+"'s wadden guide");
   	set_long(	"Wadden guide (nice).\n"+
				"He is in good shape. He sports a big reddish beard.\n"+
				"He has an account at the Fishers and Farmers Coop.\n"+
				"Wadden guide is a male Human.\n"	);
}

reset(arg) {
	::reset(arg);
	if (!regionmaster) 
		set_regionmaster();
	if (!tidemaster) 
		set_tidemaster();
	if (arg) return;
	set_name("guide");
	set_alias("wadden guide");
	set_level(30);
   	set_wc(20);
   	set_ac(100);
   	set_hp(3000);
	set_sp(50);
   	set_spell_mess1("Wadden guide punches his attacker in the stomach.");
   	set_spell_mess2("Wadden guide punches you in the stomach.");
	set_chance(20);
	set_spell_dam(50);
    set_al(5);
	set_gender(1);
	load_chat(4, ({
		"Wadden guide coughs noisily.\n",
		"Wadden guide scratches his head.\n",
		"Wadden guide scratches behind his left ear.\n",
		"Wadden guide scratches behind his right ear.\n",
			})  );
	load_a_chat(15, ({
        "Wadden guide spits in your direction.\n",
        "Wadden guide hisses: you bastard..I'll get you for that.\n",
			})  );
    load_match(this_object(), ({ "follow",  ({"leaves",}),
								 "smoke", ({"smiles", "takes a deep draw",}),
								 "answer", ({"says", "tells you",}),
			/*					"whatru", ({"looks at you",}), */
								"arrives", ({"arrives",}),
								 "receive", ({"gives",}), }));
	to_home = ({ "south", "southeast","northeast","northeast","northeast",
				"east","house","east", });
   	set_aggressive(0);
   	set_short("Wadden guide");
	PLACE_IN_THIS( spliff, "/players/qclxxiv/obj/spliff_c");
	cap=clone_object("/players/qclxxiv/obj/qhelmet");
	cap->name_qhelmet("cap");
	cap->pref_qhelmet("peaked");
	cap->suf_qhelmet("(worn)");
	move_object(cap,this_object());
	set_living_name( "waddenguide" );
	enable_commands();
	/* init_command("wear cap");  */
}
		
say_room(str) {   /* NOT to be called from actions */
    say("Wadden guide says: "+str); /* to all in room BUT vendor. */
}

follow(str) {
    string who, where;
	if (mode!=FOLLOW) return;
    if (sscanf(str, "%s leaves %s.\n", who, where) == 2) {
/*		say( "myman_name is: " + myman_name + ".\n" );
		say( who + " leaves " + where + ". I'd better follow now.\n" );
*/
		if ( lower_case(who) == myman_name ) {
			do_move(where);
		}
	}
}

arrives(str) {
    string who;
    if (sscanf(str, "%s arrives", who) ) {
		if (lower_case(who) == myman_name) {
			if (mode==GUIDE) {
				return;
			}
			else if (mode==FOLLOW) {
				return;
			}
		} /* in WAIT mode greet myman too */

		if (who!=lastgreet && mode!=GUIDE) {
			lastgreet = who;
			if (random(10)>7) say_room("Howdy "+who+"\n");
			else if (random(10)>7) say_room("Howdy\n");
			else say("Wadden guide nods friendly.\n");
		}
	}
}

answer(str) {
    string who, lwho, rest, message, a, b, c; 
/*	write("guide is going to answer\n"); */

    sscanf(str, "%s %s", who, rest);
	lwho = lower_case(who);
/*	write("guide is going to answer "+lwho+"\n"); */

    if (lwho=="wadden guide") return;
    if (lwho=="guide") return;
    if (!( sscanf(rest, "says: %s\n", message) 
		|| sscanf(rest, "tells you: %s\n", message) ) ) return;
	message = " " + lower_case(message) + " ."; /* add stuff for easier parse*/

/*	write("guide 's myman_name is: "+myman_name +"\n");*/

	if (lwho==myman_name) answer_myman(message);
	else if (lwho=="drunkard") answer_drunkard(message);
	else if (lwho=="publican") answer_publican(message);
	else answer_anyone(who, message);
}

answer_myman(message) {
	string a,b,c;
/*	write("guide is going to answer his  myman\n");*/

	if (mode==GOHOME) {
		tell_myman( "Sorry, I am off duty now, see you later perhaps.\n");
		return;
	}
	if (sscanf(message, "%sfollow me%s", a, b)>1) {
		if (mode!=FOLLOW) {
			tell_myman( "Good, just go before me, and I will follow.\n" );
			mode = FOLLOW;
		}
		else {
			tell_myman( "I am following you already.\n" );
			tell_myman( "Just go before me.\n" );
			tell_myman( 
				"If you want me to wait, or guide you, just say so.\n" );
		}
	}
	else if (sscanf(message, "%sguide me%s", a, b)>1) {
		if (mode!=GUIDE) {
			tell_myman( "Alright. Just follow me.\n" );
			mode = GUIDE;
		}
		else {
			tell_myman( "Wasn't I already guiding you?\n" );
			tell_myman( "Just keep on following me. I'll wait for you.\n" );
			tell_myman( 
				"If you want me to follow you, or wait, just say so.\n" );
		}
	}
	else if (sscanf(message, "%swait here%s", a, b)>1
			|| sscanf(message, "%stay here%s", a, b)>1 )
	{
		if (mode!=WAIT) {
			tell_myman( "OK I'll wait here.\n" );
			mode = WAIT;
		}
		else {
			tell_myman( "But I am already waiting here...\n" );
			tell_myman( 
				"If you want me to follow or guide you, just say so.\n" );
		}
	}
	else answer_anyone(myman_name, message);
}

answer_drunkard(mssg) {

}

answer_publican(mssg) {
	string a;
	if (sscanf(mssg,"%s news about the dragon", a))
		call_out( "say_room",2,"the dragon across the Wadden?\n");
	else if (sscanf(mssg,"%supid adventurers", a))
		say_room("Yeah..I brought one only yesterday..never came back!\n");
}


answer_anyone(who, message) {
	if (random(10)>6) say_room( "oh..\n");
	if (random(10)>7) do_a_thing();
}

receive(str) {
	string who, what;
	if (sscanf(str,"%s gives you %s.",who,what)==2 
			|| sscanf(str,"%s gives %s to Guide",who,what)==2) {
		if (who!="Publican")
			say_room("Thank you for the "+what+", "+who+"!\n");
		else say_room("Thanks\n");
		if (what=="spliff") {
			spliff_from = lower_case(who);
			smoke( "hop" );
		}
	}
}

smoke( str ) {
	if (present("spliff",this_object())) 
		init_command("smoke spliff");
	if (present("spliff",this_object())) {
		if (random(13)>8 && spliff_from) {
			if (present(spliff_from, environment(this_object()) ) )
				init_command("give spliff to "+spliff_from );
		}
	}
	else if (random(10)>6) say("Wadden guide smiles.\n");
	else if ( str=="spliff" && random(10)>7) 
				say_room("Ahhh a spliff..always irie.\n");
	else if ( str=="spliff" && random(10)>7) 
				say_room("Could I have a draw?\n");
	else if (random(10)>6) {
		spliff = 0;
		PLACE_IN_THIS(spliff,"/players/qclxxiv/obj/spliff_c");
		say("Wadden guide fetches a spliff from somewhere.\n");
	}
}

do_a_thing() {
	object obj;
	int i;
	i = random(14);
	switch( i ) {
	case 0 : say("Wadden guide scratches behind his ear.\n");
			break;
	case 1 : say("Wadden guide coughs noisily.\n");
			break;
	case 2 : smoke( "hop" );
			break;
	case 3 : say("Wadden guide shrugs helplessly.\n");
			break;
	case 4 : say("Wadden guide smiles.\n");
			break;
	case 5 : say("Wadden guide tussles his beard.\n");
			break;
	case 6: case 7: case 8: break;
	default:
		if (obj=present("qpub_drink",this_object())) {
			if (obj->query_value()>10) 
				init_command("drink "+obj->query_name());	
			else init_command("drop "+obj->query_empty_name());	
		}
	}
}

heart_beat() {
	int row, col;
	string nextdir;
	object env;
	::heart_beat();
	if (random(30)==10) do_a_thing();
	if (mode==GUIDE) {
		if (myman && environment(myman)==environment(this_object())) {
			env = environment(this_object() );
			if (nextdir = env->towadden() ) {
				do_move( nextdir );
			}
			else if (env->yes_its_a_tide_room()) {
				if (!regionmaster) 
					set_regionmaster();
				if (!tidemaster) 
					set_tidemaster();
				col = env->the_col();
				row = env->the_row();
			/*	say("col, row, dir : "+col+", "+row+", "+waddendir+"\n"); */
				do_move( regionmaster->guide_dir(col, row, waddendir) );	
			}
			else if (env->is_tide_exit()) {
				if (env->is_to_exit()) {
					if (waddendir==TO) {
						if (!waitforlater()) {
							say_room("Well here we go! Follow me precisely!\n");
							do_move("north");
						}
					}
					else {
						say_room("Well we made it back my friend.\n");
						tell_myman("I think I have done my job...\n");
						say_room("I go home again.  Bye.\n");
						mode = GOHOME;
   						set_short(cap_myman_name+"'s wadden guide (free)");
						waddendir = TO;
						do_gohome(0);
					}
				}
				else {  /* its the from_exit. */
					if (waddendir==FROM) {
						if (!waitforlater()) {
							say_room("OK! let's do it again! Hold on!\n");
							do_move("south");
						}
					}
					else {
						say_room("Well I think we made it my friend.\n");
						tell_myman(
					"I'll wait here until you want me to guide you back..\n");
						mode = WAIT;
						waddendir = FROM;
					}
				}
			}
			else {
				tell_myman("Well sorry, I don't know here anymore.\n");
				tell_myman("I'll follow you instead then.\n");
				mode = FOLLOW;
			}
		}	
	}
}

waitforlater() {
	say("Wadden guide looks at clock.\n");
	if (!regionmaster) 
		set_regionmaster();
	if (!tidemaster) 
		set_tidemaster();
	if ((tidemaster->is_falling() && tidemaster->water_level()<4)
		|| tidemaster->water_level()<3 )
		return 0;
	tell_myman( "Well, the tide is not right. I'll wait here.\n" );
	tell_myman( "Ask me to guide you again later.\n");
	mode = WAIT;
	return 1;
}

dest_soon() {
	call_out( "self_destruct", 5 );
}

self_destruct() {
	say("Wadden guide disappears in a puff of smoke.\n");
	destruct( this_object() );
}

do_move( dir ) {
	call_other( this_object(), "init_command", dir );
}

tell_myman( mssg ) {
	if (present(myman_name,environment(this_object()))) say_room( mssg );
	else {
		if (myman) tell_object(myman, "Wadden guide tells you: "+mssg );
		else {
			if (myman=find_living(myman_name)) 
				tell_object(myman, "Wadden guide tells you: Rehi!. "+mssg );
			else say("Wadden guide shrugs helplessly.\n" );
		}
	}
}

set_regionmaster() {
	if (find_object("/players/qclxxiv/leaf4/grifroom"))
		regionmaster = present( "regionmaster",
							find_object("/players/qclxxiv/leaf4/grifroom"));
}

set_tidemaster() {
	if (find_object("/players/qclxxiv/leaf4/grifroom"))
		tidemaster = present( "tidemaster",
							find_object("/players/qclxxiv/leaf4/grifroom"));
}

do_gohome( i ) {
	if (i<8) {
		do_move( to_home[i] );
		i++;
		call_out("do_gohome",3,i);
	}
}

drink_alcohol(str) { return 1; }
drink_alco(str) { return 1; }
