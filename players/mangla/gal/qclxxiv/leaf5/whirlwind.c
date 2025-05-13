inherit "players/qclxxiv/leaf5/qmonster";

reset(arg) {
     ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
		"The Whirlwind whirls through the room.\n",
		"The Whirlwind looks very angry.\n",
		"You hear a nasty sucking sound coming from the Whirlwind....\n"
	  }));
	 load_a_chat(20,({
        "The Whirlwind makes frightening sucking noises.\n",
        "The Whirlwind whirls around its attacker.\n",
	  }));
	set_name("whirlwind");
	set_race("wind");
	set_alias("whirl");
   	set_spell_mess1( "Whirlwind sucks its opponent in for a moment.");
   	set_spell_mess2("Whirlwind sucks you in for a moment.");
   	set_short("A Whirlwind");
   	set_long("A Whirlwind. A very concentrated, and apparently conscious one.\n"
			+"An absolute KILLER!\n" );
}

fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "hits";
    	case 2: return "hits";
    	case 3: return "hits";
    	case 4: return "strikes";
    	case 5: return "strikes";
    	case 6: return "strikes";
    	case 7: return "CRUSHES";
   		case 8: return "CRUSHES";
   		case 9: return "CRUSHES";
  		case 10: return "did an INSANE amount of damage to";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
    	case 1: return "";
    	case 2: return " at double speed";
    	case 3: return " at utter speed";
    	case 4: return "";
    	case 5: return " at double speed";
    	case 6: return " at utter speed";
    	case 7: return "";
		case 8: return " at double speed";
   		case 9: return " at utter speed";
  		case 10: return "";
		default: return "huh?";
	}
}

