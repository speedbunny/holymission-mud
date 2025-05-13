inherit "players/qclxxiv/leaf5/qmonster";

reset(arg) {
     ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
	"The Cyclops's big mouth is hanging wide open.\n",
		"The Cyclops looks very angry.\n",
"You hear a deep grumbling noise coming from the stomach of the Cyclops....\n"
	  }));
	 load_a_chat(20,({
        "The Cyclops makes awful roaring noises.\n",
        "The Cyclops spits at his attacker.\n",
	  }));
	set_name("cyclops");
	set_race("giant");
   	set_spell_mess1( "The Cyclops tramples his opponent.");
   	set_spell_mess2("The Cyclops tramples you.");
   	set_short("A Cyclops");
   	set_long(
"A Cyclops. A giant having one eye in his forehead. An absolute KILLER!\n" );
}

fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "tickled";
    	case 2: return "hit";
    	case 3: return "hit";
    	case 4: return "hit";
    	case 5: return "crushed";
    	case 6: return "crushed";
    	case 7: return "kicked";
   		case 8: return "kicked";
   		case 9: return "kicked";
  		case 10: return "did an INSANE amount of damage to";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
    	case 1: return " in the stomach";
    	case 2: return " in the stomach";
    	case 3: return " in the face";
    	case 4: return " on top of the head";
    	case 5: return " with a but against the breast";
    	case 6: return " with a but against the head";
    	case 7: return " at the breast";
		case 8: return " in the face";
   		case 9: return " on top of the head";
  		case 10: return "";
		default: return "huh?";
	}
}

