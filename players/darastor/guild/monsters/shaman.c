//Changed Values: Pretzel


inherit "obj/monster";

#include "/players/darastor/guild/barb.h"

reset(arg) {
    ::reset();
    if(arg) return;

    set_alias("shaman");
    set_name("barbarian shaman");
    set_short("Barbarian Shaman");
    set_long("The spiritual leader of the Barbarians. He oversees the health\n"+
      "and wells being of his clan, and knows many things. Perhaps you\n"+
      "should 'ask' him about somethings.\n");
    set_level(50);
    set_hp(20000);
    set_wc(89);
    set_ac(10);
    set_number_of_arms(2);
}

init(){
    ::init();
    AA("_heal","sacrifice");
    AA("_ask", "ask");
}

_ask(arg) {
    if(this_player()->query_guild() != 11){
	write("The Shaman turns to you and says: arfle boggle nik dar nistinum?\n");
	return 1;
    }
    write("	\n");
    write("The Shaman says: Sacrifice 200 coins for a cure light.\n");
    write("The Shaman says: Sacrifice 700 coins for a cure serious.\n");
    write("The Shaman says: Sacrifice 1400 coins for a cure critical.\n");
write("The Shaman says: Sacrifice 3000 coins for a Heal. (Includes poison)\n");
    write("	\n");
    return 1;
}


_heal(arg) {
    if(TP->query_guild() == 11) {
	switch(arg) {
	case "200 coins":
	case "200 coins to shaman":
            if(TP->query_money()< 200){
                write("You do not have 200 coins\n");
		return 1; }
	    else {
		write("The Shaman utters the words 'judicious dies'\n");
		write("You feel better.\n");
		say("The Shaman utters the words 'judicious dies'\n");
		say(TPN+"'s wounds close.\n");
		TP->add_money(-100);
		TP->heal_self(25+random(10));
		return 1;
	    }
	    break;
	case "700 coins to shaman":
	case "700 coins":
	if(TP->query_money() < 700){
	write("You do not have 700 coins.\n");
	return 1;
	}
	    write("The Shaman utters the words 'judicious quafung'\n");
	    write("You feel better.\n");
	    say("The Shaman utters the words 'judicious quafung'\n");
	    say(TPN+"'s wounds close.\n");
	TP->add_money(-700);
	    TP->heal_self(50+random(30));
	    return 1;
	    break;
	case "1400 coins":
	case "1400 coins to shaman":
	if(TP->query_money() < 1400){
	write("You don't have 1400 coins.\n");
	return 1;
	}
	    write("The Shaman utters the words 'judicious melcraz'\n");
	    write("You feel better.\n");
	    say("The Shaman utters the words 'judicious melcraz'\n");
	    say(TPN+" wounds close.\n");
	TP->add_money(-1400);
	    TP->heal_self(140+random(40));
	    return 1;
	    break;
	case "3000 coins":
	case "3000 coins to shaman":
        if(TP->query_money() < 3000){
	write("You don't have 3000 coins.\n");
	return 1;
	}
	    write("The Shaman utters the words 'xyclophus mestor'\n");
	    write("You are healed.\n");
	    say("The Shaman utters the words 'xyclophus mestor'\n");
	    say(TPN+" looks much better.\n");
	TP->add_money(-3000);
	    TP->heal_self(300+random(50));
	TP->add_poison(-10000);
	    return 1;
	    break;
	default :
            write("sacrifice 200 coins for a cure light.\n");
            write("sacrifice 700 coins for a cure serious.\n");
            write("sacrifice 1400 coins for a cure critical.\n");
            write("sacrifice 3000 coins for a Heal. (Including poison)\n");

	    return 1;
	    break;
	}
	write("The Shaman is much too exhausted to cast right now.\n");
	return 1;
    }
    write("The Shaman looks puzzled.\nThe Shaman doesn't understan a word you said.\n");
    return 1;
}
