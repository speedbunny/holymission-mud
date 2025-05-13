#include "/players/gareth/define.h"
inherit "/obj/npc";
   object platemail, helm, bracers, scimitar; 

  reset(arg) {
    ::reset(arg);
    
  if(!arg) {
  set_name("drow warlord");
  set_race("elf");
  set_alt_name("warlord");
  set_alias("drow");
  set_short("A drow warlord");
  set_long("You see a very strong drowish warlord. He is the\n"+ 
           "trainer of of all the drow of the house of Gawain.\n"+ 
           "He's one of the strongest of the dark elves. His eyes\n"+ 
           "burn with firery hatred and determination.\n");
  load_chat(25,({"The drow says:  come on!! Let's fight!!.\n",
                "The dark elf grins evilly.\n",
                }));
  load_a_chat(25,({"The warlord goes berzerk.\n",
                  "The drow growls:  You will die now!!!!\n",
                  }));
  set_level(85);
  set_al(-1000);
  set_hp(5000);
set_wc(65000000);
  set_ac(75);
  set_chance(75);
  set_spell_mess1("The drow warlord wrecks havoc on you body.");
  set_spell_mess2("The dark elf does some serious damage to you.");
  set_spell_dam(100+random(80));
  set_attacks(3);
  set_attacks_change(55);
  set_aggressive(1);
  set_fol_change(45);
  set_dodge(55);
  set_rid_change(30);
  add_money(20000);

  platemail=transfer(CO(ITEM+"e_plmail"),TO);
  helm=transfer(CO(ITEM+"helm"),TO);
  bracers=transfer(CO(ITEM+"bracers"),TO);
/*
  scimitar=transfer(CO(ITEM+"scim"),TO);
*/
           
  init_command("wear platemail");
  init_command("wear bracers");
  init_command("wear helm");
/*
  init_command("wield scimitar");
*/

 }
 
 }
