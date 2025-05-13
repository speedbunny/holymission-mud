inherit "players/qclxxiv/leaf5/qmonster";

reset(arg) {
     ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
		"The Lion growls loudly.\n",
		"The Lion looks very angry.\n",
		"You hear a grumbling noise coming from the Lion's stomach....\n"
	  }));
	 load_a_chat(20,({
        "The Lion shows its enormous teeth.\n",
        "The Lion growls and roars.\n",
	  }));
	set_name("lion");
	set_race("lion");
   	set_spell_mess1(
		"Lion hits his opponent with his mighty claws.");
   	set_spell_mess2("Lion hits you with his mighty claws.");
   	set_short("A Lion");
   	set_long(
	"An enormous Lion. It doesn't look natural. An absolute KILLER!\n" );
}

fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "scratched";
    	case 2: return "scratched";
    	case 3: return "scratched";
    	case 4: return "hit";
    	case 5: return "hit";
    	case 6: return "struck";
    	case 7: return "struck";
   		case 8: return "struck";
   		case 9: return "crushed";
  		case 10: return "bit";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
    	case 1: return " slightly";
    	case 2: return " rather deep";
    	case 3: return " badly";
    	case 4: return " hard";
    	case 5: return " very heavy";
    	case 6: return " hard";
    	case 7: return " very hard";
		case 8: return " extremely hard";
   		case 9: return " ";
  		case 10: return " in the neck";
		default: return "huh?";
	}
}

