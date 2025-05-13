inherit "players/qclxxiv/mymonster";
#define NAME_OF_GHOST			"Some mist"
#define CName           capitalize(name)

reset(arg) {
     ::reset(arg);
	 if (arg) return;
	set_level(35);
   	set_wc(50);
	set_ac(100);
   	set_hp(10000);
	set_sp(200);
	set_chance(40);
	set_spell_dam(75);
    set_al(-50);
   	set_aggressive(0); 
	set_gender(0);
	set_size(5);
}


peace_with(obj) {
	if (obj==attacker_ob) {
			/*tell_object(obj,"Peace? 1\n");*/
			attacker_ob = alt_attacker_ob;
		hunter = 0; 
		hunted = 0;	
		obj->stop_fight();
		obj->stop_fight();
		obj->stop_hunter(1);
	}
}

do_attack(obj) {
	/*tell_object(obj,"Groooaaaaarrrr 2\n");*/
	/*kill_ob = obj;*/
	attack_object(obj); 
	attack();
}
set_attack(obj) {
	/*tell_object(obj,"Groooaaaaarrrr 1\n");*/
	call_out("do_attack",0,obj);
}

/* next two functions added to make attack more flexible.
 * Providing new versions of next two functions in a monster allows special
 * strings in fights. It are func's rather than arays to save memory in
 * monster instances. Qclxxiv
*/
fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "tickled";
    	case 2: return "grazed";
    	case 3: return "hit";
    	case 4: return "hit";
    	case 5: return "hit";
    	case 6: return "hit";
    	case 7: return "smashed";
   		case 8: return "massacred";
   		case 9: return "pound";
  		case 10: return "did an INSANE amount of damage to";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
    	case 1: return " in the stomach";
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
