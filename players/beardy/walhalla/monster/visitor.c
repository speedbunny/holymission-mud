inherit "obj/npc";
#include "../walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { switch(random(2))
    { case 0 : 
               set_name("woman");
  	       set_alt_name("human");
	       set_race("human");

               set_level(10+random(25));
               set_gender(2);
               switch(TO->query_level())
               { case 10 .. 15 : set_short("young gild");
                                 set_long("It's a young girl. It looks very unhappy,\n" +
                                          "because you have such a stinking smell...\n");
                                 set_attacks_change(random(30));
				 set_attacks(random(7));
			         set_aggressive(0);
				 add_money(10);
       				 break;
		 case 16 .. 25 : set_short("women");
				 set_long("It's a beautiful woman. Wow, what a figure.\n" +
             				  "I hope you dont attack her...\n");
				 set_attacks_change(random(60));
				 set_attacks(random(5));
				 set_aggressive(0);
				 add_money(500);
				 CO("cure_potion");
				 break;
		 case 26 .. 34 : set_short("fightess");
			         set_long("It's a female fighter. She has got muscles...\n");
				 set_attacks_change(70+random(30));
			   	 set_attacks(4+random(3));
				 add_money(600);
				 CO("str_potion");
				 CO("cure_potion");
				 break;
 		}

	       set_al(200);

	       set_spell_mess2("SSCCCCRRRRAAATTTTCCCCHHHH !!!!\n" +
                               "The woman makes a deep cut with it's fingernails...");
	       set_chance(TO->query_level()+random(TP->query_level()*2));
	       set_spell_dam(2*TO->query_level());
               break;
       case 1: 
                set_name("man");
		set_alt_name("human");
                set_race("human");

		set_gender(1);
                set_level(15+random(30));
		switch(TP->query_level())
		{ case 15 .. 20 : set_short("young man");
				  set_long("It's a young man, looking quite innocent,\n" +
					   "but don't trust in him...\n");
				  set_attacks_change(random(40));
				  set_attacks(random(7));
				  add_money(400);
				  break;
		  case 21 .. 30 : set_short("man");
				  set_long("It's a normal man, like everyone else.\n");

				  set_attacks_change(random(60));
	  			  set_attacks(2+random(3));
			          add_money(700);
				  CO("cure_ser_potion");
				  break;
		 case 31 .. 39  : set_short("fighter");
				  set_short("It's a fighter, DON'T annoy him...\n");
			  	  set_attacks_change(80+random(40));
				  set_attacks(5+random(3));
				  add_money(3000+random(200));
				  CO("cure_crit_potion");
				  CO("str_potion");
				  break;
 		}

		set_al(100);

		set_spell_mess2("############################\n" +
                		"A hidden male attack ...");
                set_chance( TO->query_level()+random(TP->query_level()*2));
                set_spell_dam(2*TO->query_level());
                break;
    }
  }
}
