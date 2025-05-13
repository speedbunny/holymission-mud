#include "/players/gareth/define.h"
inherit "/obj/monster";   
   object chainmail, bracers, staff; 

  reset(arg) {
    ::reset(arg);
  if(!arg) {
  set_name("drow mage");
  set_race("drow");
  set_alt_name("mage");
  set_alias("elf");
  set_short("A drowish mage");
  set_long("You see a young, beautiful dark elf. She looks as\n"+ 
	   "deadly as she is beautiful. Her blue eyes burn with\n"+
	   "passion, drive and determination. You sense she is \n"+
	   "waiting for something, pray that it's not your death.\n");
  load_chat(20,({ "The mage casts a spell and begins to glow.\n",
	          "The dark elf checks you out and laughs.\n",
	     }));
  load_a_chat(20,(
	    { "The drow says: good people must die!!\n",
	      "The female howls: fool! I shall spit on your dead skull!\n",
	    }));
  set_aggressive(1);
  set_level(50+random(20));
  set_dex(75);
  set_hp(5000+random(3500)); 
  set_wc(30+random(10));
  set_n_ac(25+random(10));
  set_number_of_arms(2);
  set_al(-1500);
  add_money(5500+random(3000));
  set_language_skill(2,100);

  change_spell("chainlightning", 99, 95, 0);
  change_spell("fireball", 99, 95, 1);
  change_spell("firestorm", 99, 95, 2);
  change_spell("harm", 50, 75, 2);
  
  staff= TR(CO(ITEM+"staff"),TO); 
  chainmail= TR(CO(ITEM+"email"),TO);
  bracers= TR(CO(ITEM+"bracers"),TO);

  init_command("wield staff");
  init_command("wear chainmail");
  init_command("wear bracers");
 	 }
  }

int concentrate(object vic) {
	int rnd;
	if (vic && !query_concentrating()) {
	   rnd = random(100);
	   if (rnd <= 25)
		npc_process_spell("chainlightning", vic->query_real_name());
     	   else if (rnd <= 65)
		npc_process_spell("fireball", vic->query_real_name());
	   else if (rnd > 70)
		npc_process_spell("firestorm", vic->query_real_name());
	   else if (rnd >= 90)
		npc_process_spell("harm", vic->query_real_name());
	   else 
	        return(0);
		  return(1);
	}
	   return(0);
}


/*  init () {
       ::init();
       set_heart_beat(1);
  }
  heart_beat() {
      ::heart_beat();
      write("heart beat activated.\n");
      if(AO && present(AO, ENV)) {
	if(!random(6)) {
   tell_object(AO, "You stagger helpless as the drow blinds you.\n");
   say("Drow blinds "+AO->N+" with a darkness spell.\n", AO);
   AO->hit_player(2);
   AO->hold(TP, 5);
		}
	}
}
  hold_end(obj) {
  tell_object(obj, "You can see again!\n");
  return 1;
}
*/
