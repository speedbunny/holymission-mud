#include "/players/gareth/define.h"
inherit "obj/monster";   
   object pot,chainmail,bracers,staff; 
   int i;

  reset(arg) {
    ::reset(arg);
  if(!arg) {
  set_name("drow mage");
  set_race("drow");
  set_alt_name("mage");
  set_alias("elf");
  set_short("A drowish mage");
  set_gender(2);
  set_size(3);
  set_long("You see a young, beautiful dark elf. She looks as\n"+ 
           "deadly as she is beautiful. Her blue eyes burn with\n"+ 
           "passion, drive and determination. You sense she is \n"+
           "waiting for something.\n");
  load_chat(20,({ "The dark-elf looks at you and laughs.\n",
                  "The drow grins evilly.\n",
            }));
  load_a_chat(20,(
            { "The drow says: I shall piss on your dead skull!!\n",
              "The dark elf screams: How dare you touch me!\n",
            }));
  set_level(50);
  set_dex(85);
  set_hp(4500);
  set_wc(15);
  set_n_ac(35);
  set_al(-1500);
  set_aggressive(1);
  set_number_of_arms(2);
  add_money(2500);

  set_language_skill(2,100);
  change_spell( "acid blast", 99, 95, 0 );
  change_spell( "fireball", 99, 95, 1 );
  change_spell( "chainlightning", 99, 95, 1 );

  chainmail= TR(CO(ITEM+"email"), TO);
  bracers= TR(CO(ITEM+"bracers"), TO);
  staff= TR(CO("/players/llort/guild/obj/staff"), TO);

  init_command("wield staff");
  init_command("wear chainmail");
  init_command("wear bracers");

	  }
  }

int concentrate( object vic ) {
   int rnd;
   if ( vic && !query_concentrating() ) { 
      rnd = random( 100 );
      if ( rnd <= 20 )                              
         npc_process_spell( "acid blast", vic->query_real_name() );
      else if ( rnd < 60 )                         
         npc_process_spell( "fireball", vic->query_real_name() );
      else if ( rnd >= 75)                                       
         npc_process_spell( "chainlightning", vic->query_real_name() );
      else           
         return(0);
                return(1);
   }
   return(0);
}

 
