inherit "obj/npc";
#include "../walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { switch(random(4))
    { case 0 : 
               set_name("worm");
  	       set_alt_name("worm");

	       set_race("animal");
               
               set_short("worm");
	       set_long("It's a simple worm. It has been found guilty\n " +
                        "of killing another worm. Perhaps the other one\n" +
                        "is in the room too.\n");
 
	       set_gender(0);

	       set_level(5);
	       set_attacks_change(100);
	       set_attacks(4);    

	       set_al(-300);
	       set_aggressive(1);
	       add_money(50);

	       set_spell_mess2("SNUTCH !!!!\n" +
                               "The ugly worm kisses you....");
	       set_chance(20);
	       set_spell_dam(50);
               break;;
       case 1: 
                set_name("ghost");
		set_alt_name("ghost worm");
                set_race("ghost");

                set_short("ghost worm");
                set_long("It's a ghost worm. It was killed by the\n" +
                         "aggressive killerworm. Perhaps he is in the\n" +
                         "room too.\n");

		set_gender(0);

		set_level(10);
		set_attacks_change(40);
		set_attacks(5);

		set_al(100);
		set_aggressive(0);
		add_money(1);

                break;
       case 2:
		set_name("lawyer");
		set_alt_name("human");
		set_race("human");

		set_short("lawyer");
		set_long("This is the lawyer of the accused worm. DON'T annoy him\n");

		set_gender(1);

		set_level(15);
		set_attacks_change(60);
		set_attacks(1);

		set_al(0);
		set_aggressive(1);
		add_money(100);

		set_spell_mess2("Hakjf flelhgem glihze vhgue\n" +
		                "Ouch, that hurts...");
                set_chance(20);
		set_spell_dam(50);
                CO("cure_ser_potion");
		break;
       case 3:
		set_name("accused");
		set_alt_name("human");
		set_race("human");

		set_short("accused human");
		set_long("It's a small human who has been accused of\n" +
			 "killing his mother. He will be sentenced to death.\n");

		set_gender(1);

		set_level(17);
		set_attacks_change(100);
		set_attacks(2);

		set_al(-300);
		set_aggressive(1);
		add_money(5);
                CO("cure_ser_potion");
		break;
    }
  }
}
