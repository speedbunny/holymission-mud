inherit "players/qclxxiv/leaf5/qmonster";

reset(arg) {
     ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
		"Ink drips from the corners of Inkblob's big mouth.\n",
		"The Inkblob looks very angry.\n",
		"You hear a deep bubbling sound coming from inside the Inkblob....\n"
	  }));
	 load_a_chat(20,({
        "The Inkblob makes awful bubbling noises.\n",
        "The Inkblob spits ink towards his attacker.\n",
	  }));
	set_name("inkblob");
	set_race("blob");
   	set_spell_mess1(
		"Inkblob sprays an enormous amount of ink towards his opponent.");
   	set_spell_mess2("Inkblob sprays an enormous amount of ink towards you.");
   	set_short("An Inkblob");
   	set_long("An Inkblob. A weird black unearthly monster. An absolute KILLER!\n" );
}

fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "spickled";
    	case 2: return "spat";
    	case 3: return "sprayed";
    	case 4: return "sprayed";
    	case 5: return "sprayed";
    	case 6: return "sprayed";
    	case 7: return "soaked";
   		case 8: return "soaked";
   		case 9: return "blobbed";
  		case 10: return "did an INSANE amount of blobbing to";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
    	case 1: return " in the face";
    	case 2: return " in the face";
    	case 3: return " lightly";
    	case 4: return " pretty heavy";
    	case 5: return " very heavy";
    	case 6: return " extremely hard";
    	case 7: return " with a soap bubbling sound";
		case 8: return " to small blobs";
   		case 9: return " into a blobble of blood and body bubbles";
  		case 10: return "";
		default: return "huh?";
	}
}

