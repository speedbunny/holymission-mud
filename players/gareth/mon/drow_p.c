#include "/players/gareth/define.h"
inherit "obj/npc";
   object cloak, bracers, hammer; 

  reset(arg) {
    ::reset(arg);
    
  if(!arg) {

  set_name("drow cleric");
  set_race("elf");
  set_alt_name("cleric");
  set_alias("drow");
  set_short("A drow cleric");
  set_long("A drowish cleric, priestess to the evil spider-god \n"+
           "Lolth. She could be almost attractive if she was not\n"+ 
           "pure evil. She appears to be preparing for a sacrifice,\n"+ 
           "pray that it's not yours.\n");
  load_chat(20,(
            { "The dark elf hisses.\n",
             "The preistess says: you're goodness makes me sick!\n",
            }));
  load_a_chat(20,(
            { "The cleric rebukes you.\n",
              "The drow says: Lolth shall devour your soul!!\n",
            }));
  set_dex(70);
  set_level(50);
  set_al(-2000);
  set_hp(3500);
  set_wc(65);
  set_ac(55);
  set_chance(55);
  set_spell_mess1("The cleric tortures your soul.");
  set_spell_mess2("The preistess damns you to hell!");
  set_spell_dam(100+random(75));
  set_dodge(65);
  set_attacks(3);
  set_attacks_change(30);
  set_fol_change(10);
  add_money(10);

  cloak=TR(CO(ITEM+"cloak"),TO);
  bracers=TR(CO(ITEM+"bracers"),TO);
/*
  hammer=TR(CO(ITEM+"hammer"),TO);
*/

  init_command("wear cloak");
  init_command("wear bracers");
/*
  init_command("wield hammer");
*/

  }

  }
  
