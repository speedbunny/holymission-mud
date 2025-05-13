inherit "players/qclxxiv/island/ianimal";
id(arg) { return (::id(arg) || arg=="bird"); }

reset(arg) {
     ::reset(arg);
	 if (arg) return;
	set_race("bird");
	msgin = "flies in";
	msgout = "flies away";
	mmsgin = "flies in";
	mmsgout = "flies away";
}

/* default restriction: no animal runs into whirlpools */
/*   OK for birds in general as well
run_OK(room) {
	if (room->query_whirl()) return 0;
	return 1;
}
*/
can_climb() { return 1; } /* well....climb:-) */
run_method() { return "fly"; } 

fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "scratches";
    	case 2: return "picked";
    	case 3: return "picked";
    	case 4: return "picked";
    	case 5: return "picked";
    	case 6: return "picked";
    	case 7: return "picked";
   		case 8: return "picked";
   		case 9: return "picked";
  		case 10: return "did an INSANE amount of damage by picking ";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
    	case 1: return " in the face";
    	case 2: return "";
    	case 3: return "";
    	case 4: return " hard";
    	case 5: return " pretty hard";
    	case 6: return " very hard";
    	case 7: return " with a bone crushing sound";
		case 8: return " to small fragments";
   		case 9: return " into a puddle of blood and body parts";
  		case 10: return "";
		default: return "huh?";
	}
}

