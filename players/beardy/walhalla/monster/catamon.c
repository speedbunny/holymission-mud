inherit "obj/npc";
#include "../walhalla.h"

reset(arg) 
{ ::reset(arg);
    if(!arg) 
    { switch(random(5))
	{ case 0 : 
	    set_name("beetle");
	    set_alt_name("beetle");
	    set_race("animal");

	    set_short("skeleton beetle");
	    set_long("It's the dangerous skeleton beetle. Of\n" +
	      "course it died once but i should be hard\n" +
	      "to kill it a second time.\n");

	    set_gender(1);

	    set_level(15);
	    set_attacks_change(30);
	    set_attacks(2);    

	    set_al(-200);
	    set_aggressive(1);
	    add_money(1);

	    set_spell_mess1("");
	    set_spell_mess2("TTOOKK !\n" +
	      "The beetle hit you with his bones...");
	    set_chance(20);
	    set_spell_dam(60);

	    CO("cure_potion");
	    break;
	case 1: 
	    set_name("fly");
	    set_alt_name("skeleton fly");
	    set_race("animal");

	    set_short("skeleton fly");
	    set_long("It's the once died famous killer fly.\n" +
	      "The fangs, that are bones now, look very\n" +
	      "dangerous to you. The huge head too.\n");

	    set_gender(0);

	    set_level(19);
	    set_attacks_change(40);
	    set_attacks(3);

	    set_al(100);
	    set_aggressive(1);
	    add_money(1);

	    set_spell_mess1("");
	    set_spell_mess2("SSSSSUUUUUUUURRRR !!!\n" +
	      "You got a well placed hit from the fly...");
	    set_chance(45);
	    set_spell_dam(40);
	    CO("cure_potion");
	    break;
	case 2:
	    set_name("skeleton");
	    set_alt_name("human");
	    set_race("undead");

	    set_short("skeleton");
	    set_long("It's a large skeleton and looks very dangerous.\n");

	    set_gender(0);

	    set_level(23);
	    set_attacks_change(30);
	    set_attacks(3);

	    set_al(-200);
	    set_aggressive(1);
	    add_money(1);

	    set_spell_mess1("");
	    set_spell_mess2("SSSPPPPPPPPPLLLLLLLUUUUUUUUUNNNNNNNGGGGGGG \n" +
	      "The skeleton hits you in your face...");
	    set_chance(20);
	    set_spell_dam(70);
	    CO("cure_potion");
	    break;
	case 3:
	    set_name("bazill");
	    set_alt_name("disease");
	    set_race("virus");

	    set_short("bazill");
	    set_long("It's a small bazill and looks quite nice. but" +
	      "it looks very quick too.\n");

	    set_gender(0);

	    set_level(2);
	    set_attacks_change(100);
	    set_attacks(13);

	    set_al(20);
	    set_aggressive(1);
	    add_money(1);

	    set_spell_mess1("");
	    set_spell_mess2("HHHHHHHAAAAAAAAAAAAATTTTTTTTOOOOOOOOOIIIII\n" +
	      "The bazill sneezes into you face ...");
	    set_chance(70);
	    set_spell_dam(10);
	    break;
	case 4: 
	    set_name("warmonger");
	    set_alt_name("monger");
	    set_race("idiot");

	    set_short("warmonger");
	    set_long("This is the stupid long lost Warmonger. He looks quite\n" +
	      "cruel but he isn't\n");

	    set_gender(1);

	    set_level(26);
	    set_attacks_change(10);
	    set_attacks(3);

	    set_al(300);
	    set_aggressive(1);
	    add_money(5000);

	    set_spell_mess1("");
	    set_spell_mess2("The warmonger stares at you and you feel weaker now");
	    set_chance(30);
	    set_spell_dam(40);
	    CO("cure_potion");
	    break;
	}
    }
}
