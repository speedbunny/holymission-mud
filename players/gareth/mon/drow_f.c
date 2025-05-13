#include "/players/gareth/define.h"
inherit "/obj/npc";
   object scalemail, helm, bracers, scimitar; 

  reset(arg) {
    ::reset(arg);
    
  if(!arg) {
  set_name("drow fighter");
  set_race("elf");
  set_alt_name("fighter");
  set_alias("drow");
  set_short("A drow fighter");
  set_long("You see a young drow fighter. He has recently graduated\n"+ 
           "from the academy. He's really eager to prove himself in\n"+ 
           "battle. He is strong even for a dark elf. His eyes burns\n"+
           "with firery hatred and determination.\n");
  load_chat(15,({"The drow says: come on lets fight!\n",
                "The dark elf says: don't be a wuss!\n",
                }));
  load_a_chat(15,({"The fighter body blocks you - it hurts\n",
                  "The drow hisses:  You're a punk!\n",
                  }));
  set_level(35);
  set_al(-500);
  set_hp(5750);
 set_wc(7500000);
  set_ac(75);
  set_chance(80);
  set_spell_mess1("The drow spinkicks you in the head.");
  set_spell_mess2("The dark elf elbows you in the throat.");
  set_spell_dam(55+random(50));
  set_dodge(75);
  set_attacks(2);
  set_attacks_change(80);
  set_fol_change(50);
  set_rid_change(25);
  add_money(16000);
  
//scalemail=transfer(CO(ITEM+"e_scmail"),TO);
  helm=transfer(CO(ITEM+"helm"),TO);
  bracers=transfer(CO(ITEM+"bracers"),TO);
/*
  scimitar=transfer(CO(ITEM+"scim"),TO);
*/
           
//init_command("wear scalemail");
  init_command("wear bracers");
  init_command("wear helm");
/*
  init_command("wield scimitar");
*/

 }
 
 }
 

