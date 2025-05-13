#include "/players/qclxxiv/mymonster.h"
object lastgreet;
object book;
string lastlists;
int ll_index;

reset(arg) {
	if (!lastlists) { lastlists = allocate(4); }
	lastlists[0] = lastlists[1] = lastlists[2] = lastlists[3] = 0;
	ll_index = 0;
	::reset(arg);
	if (arg) return;
	set_name("librarian");
	set_alias("old lady");
	set_race("lady");
	set_level(30);
   	set_wc(10);
   	set_ac(100);
   	set_hp(1000);
	set_sp(50);
   	set_spell_mess1("Librarian casts a fireball on her attacker.");
   	set_spell_mess2("Librarian casts a fireball....you get damaged badly.");
	set_chance(20);
	set_spell_dam(30);
    set_al(5);
	set_gender(2);
	load_chat(7, ({
		"Librarian coughs softly.\n",
		"Librarian turns a page.\n",
		"Librarian scratches her head.\n",
		"Librarian turns a page.\n",
"Librarian takes book from red shelf.\nLibrarian puts book on green shelf.\n",
"Librarian takes book from yellow shelf.\nLibrarian puts book on red shelf.\n",
"Librarian takes book from green shelf.\nLibrarian puts book on yellow shelf.\n",
			})  );
	load_a_chat(15, ({
        "Librarian looks at you VERY angry.\n",
  "Librarian looks quite tough and dangerous when angry.\n",
			})  );
    load_match(this_object(), ({ 
								 "smoke", ({"takes a deep draw",}),
								 "answer", ({"says", "tells you",}),
								"arrives", ({"arrives",}),
								 "receive", ({"gives",}), }));
   	set_aggressive(0);
   	set_short("Librarian");
   	set_long(
"An old lady with gray hair and a sour look. She obviously is quite tough\n"
+"for her age. She looks back at you apparently somewhat irritated.\n" );
	PLACE_IN_THIS(book,"/players/qclxxiv/library/book");
	set_living_name( "librarian" );
	enable_commands();
}
		
say_room(str) {   /* NOT to be called from actions */
    say("Librarian says: "+str); /* to all in room BUT vendor. */
}

answer(str) {
    string who, lwho, rest, message; 
    sscanf(str, "%s %s", who, rest);
	lwho = lower_case(who);
    if (lwho=="librarian") return;
    if (!( sscanf(rest, "says: %s\n", message) 
		|| sscanf(rest, "tells you: %s\n", message) ) ) return;
	message = " " + lower_case(message) + " ."; /* add stuff for easier parse*/
	answer_anyone(who, message);
}

answer_anyone(who, message) {
	string dum;
	if (sscanf(message,"%s mines", dum)) {
		say_room(
"Oh the mines! They are in the most southwestern finger of the leaf.\n"
+"Just go south, west, 4 times north, northwest, south from here. Then\n"
+"search for a dark pit in the southwest of that finger.\n");
		return;
	}
	if (random(10)>5) say_room( "Please be quiet. This is a library.\n");
	else if (random(10)>5) say_room( "Be quiet. Read the board.\n");
	else if (random(10)>5) say_room( "Hush hush!!\n");
	else if (random(10)>5) say_room( "Be silent please!\n");
	else if (random(10)>5) 
			tell_room(this_object(),"Librarian withers "+who+" with a look.\n");
	else say_room( "Will you be silent now!\n");
}

in_lastlists(who) {
	return (lastlists[0]==who || lastlists[1]==who || lastlists[2]==who
		|| lastlists[3]==who);
}

to_lastlists(who) {
	lastlists[ll_index] = who;
	ll_index = (1+ll_index) % 4;
}

receive(str) {
	string who, what, s;
	object who_obj, what_obj, place;
	if (sscanf(str,"%s gives you %s.\n",who,what)==2 
			|| sscanf(str,"%s gives %s to Librarian",who,what)==2 ) {
		what_obj = present( what, this_object() );
		who_obj = present( lower_case(who) );
		if (!who_obj) {
			say("Librarian looks puzzled.\n");
			return 0;
		}
		say_room("Well, thank you for the "+what+", "+who+".\n");
		if (what_obj->id("qlib_book")) {
			if (what_obj->id("index")) {
				command("close index");	
				command("put index on table");	
				if (environment(what_obj)==this_object()) {
					/* second command failed for some reason */
					place = present("table");
					if (!place) {
						tell_room(environment(),
						"Librarian throws index on the floor.\n");
						place = environment();
					}
					else tell_room(environment(),
						"Librarian puts index on table.\n");
					move_object(what_obj,place);
				}
			}
			s=what_obj->query_shelfcolor();
			if (!s) return;
			command("close book");	
			command("put book on "+s+" shelf");	
			if (environment(what_obj)==this_object()) {
				/* second command failed for some reason */
				place = present(s+" shelf");
				if (!place) {
					tell_room(environment(),
					"Librarian throws book on the floor.\n");
					place = environment();
				}
				else tell_room(environment(),
					"Librarian puts book on "+s+" shelf.\n");
				move_object(what_obj,place);
			}
		}
	}
}

smoke( str ) {
	if (random(10)>5)
		say_room("Please do not smoke here. This is a library.\n");
	else say_room("Do you really have to smoke here?\n");
}

do_a_thing() {
	int i;
	i = random(14);
	switch( i ) {
	case 0 : say("Librarian scratches behind her ear.\n");
			break;
	case 1 : say("Librarian coughs softly.\n");
			break;
	case 3 : say("Librarian shrugs helplessly.\n");
			break;
	case 4 : say("Librarian shows something vaguely resembling a smile.\n");
			break;
	}
}

arrives(str) {
    string who;
    if (sscanf(str, "%s arrives", who) ) {
		if (who!=lastgreet) {
			lastgreet = who;
			say("Librarian nods.\n");
		}
	}
}


move_player(arg) {
	::move_player(arg);
	call_out("go_back",0 );
}

go_back() {
	if (environment(this_object())->its_qlibrary()) return;
	say("Librarian strides back to her library.\n");
	move_object(this_object(), "/players/qclxxiv/library/qlibrary");	
}

heart_beat() {
	int t;
	object obj, tab, place;
	string s;
	if (environment() && random(35)==30) {
		if (present("qlib_book", environment())) {
			for (t=random(7)+1; t>0; t--) {
				if (obj=present("qlib_book", environment())) {
					if (obj->id("index")) {
						tell_room(environment(),
								"Librarian picks up the index.\n");
						move_object(obj,this_object());
						command("close index");	
						command("put index on table");	
						if (environment(obj)==this_object()) {
							/* second command failed for some reason */
							place = present("table");
							if (!place) {
								tell_room(environment(),
								"Librarian throws index on the floor.\n");
								place = environment();
							}
							else tell_room(environment(),
								"Librarian puts index on table.\n");
							move_object(obj,place);
						}
					}
					else if (s=obj->query_shelfcolor()) {
						tell_room(environment(),"Librarian picks up a book.\n");
						move_object(obj,this_object());
						command("close book");	
						command("put book on "+s+" shelf");	
						if (environment(obj)==this_object()) {
							/* second command failed for some reason */
							place = present(s+" shelf");
							if (!place) {
								tell_room(environment(),
								"Librarian throws book on the floor.\n");
								place = environment();
							}
							else tell_room(environment(),
								"Librarian puts book on "+s+" shelf.\n");
							move_object(obj,place);
						}
					}
				}
				else break;
			}
		}
		else if (tab=present("qlib_table",environment()))
		  if (present("qlib_book", tab)) {
			for (t=random(5)+1; t>0; t--) {
				if (obj=present("qlib_book", tab)) {
					if (obj->id("index")) {
					}
					else if (s=obj->query_shelfcolor()) {
						tell_room(environment(),
								"Librarian takes a book from the table.\n");
						move_object(obj,this_object());
						command("put book on "+s+" shelf");	
						if (environment(obj)==this_object()) {
							/* second command failed for some reason */
							place = present(s+" shelf");
							if (!place) {
								tell_room(environment(),
								"Librarian throws book on the floor.\n");
								place = environment();
							}
							else tell_room(environment(),
								"Librarian puts book on "+s+" shelf.\n");
							move_object(obj,place);
						}
					}
				}
				else break;
			}
		}
	}
	return ::heart_beat();
}
