#define TO this_object()
inherit "/players/patience/GenObj/monster";
   object mail,shield,boots,helmet,gauntlet,robe,sword; 

  reset(arg) {
    ::reset(arg);
    
  if (arg) return;
  
  set_name("elf");
  set_alt_name("guard");
  set_alias("elf guard");
  set_level(35);
  set_short("An elf guard");
  set_long(
          "You see a young strong elf. He is a guard of Maria Wichteldorf\n"+
          "He is very tall and don't look like if anybody should dare to \n"+
          "attack him. He is a good friend of the local Smith.\n");
  load_chat(20,(
            { "The elf guard looks around.\n",
             "The elf smiles happily.\n",
            }));
  load_a_chat(20,(
            { "The elf guard growls at you.\n",
              "The elf says: I kill you!\n",
            }));
  set_chance(2);
  set_spell_mess1("makes a critical hit.");
  set_spell_mess2("hits you on a critical spot.");
  set_spell_dam(50+random(100));
  set_follow_chance(20);
  set_ploc(({ "head","right foot","left foot","right feet","left feet","torso"}));
  set_mloc(({ "head","right foot","left foot","right feet","left feet","torso"}));
  set_parry(40);
  set_feelings();
  set_friends(({"kid","melissa","guard","franz","hilde","schurli","tiffany","michelle"}));
  mail=clone_object("obj/armour");
  shield=clone_object("obj/armour");
  boots=clone_object("obj/armour");
  helmet=clone_object("obj/armour");
  gauntlet=clone_object("obj/armour");
  robe=clone_object("obj/armour");
  sword=clone_object("/players/patience/GenObj/weapon");

  mail->set_name("mail");
  mail->set_alias("chainmail");
  mail->set_short("A mithril chainmail");
  mail->set_long(
                "You see an mithril chainmail:\n\n"+
                "You think that it's a good protection.\n"+
                "It's weight seems to be so 2 pounds and\n"+
                "it seems to be made for a large elf.\n");
  mail->set_weight(2);
  mail->set_value(4000);
  mail->set_type("armour");
  mail->set_ac(4);
  mail->set_size(3);
  
  boots->set_name("boots");
  boots->set_alias("iron boots");
  boots->set_short("A pair of heavy iron boots");
  boots->set_long(
                  "You see a pair of mithril boots:\n\n"+
                "You think that it's a good protection.\n"+
                "It's weight seems to be so 1 pound and\n"+
                "it seems to be made for a large elf.\n");
  boots->set_weight(1);
  boots->set_value(800);
  boots->set_type("boot");
  boots->set_ac(1);
  boots->set_size(3);
  
  helmet->set_name("helmet");
  helmet->set_alias("mithril helmet");
  helmet->set_short("A mithril helmet");
  helmet->set_long(
                  "You a mithril helmet:\n\n"+
                "You think that it's a good protection.\n"+
                "It's weight seems to be so 1 pounds and\n"+
                "it seems to be made for a large elf.\n");
  helmet->set_weight(1);
  helmet->set_value(150);
  helmet->set_type("helmet");
  helmet->set_ac(1);
  helmet->set_size(3);
  
  shield->set_name("shield");
  shield->set_alias("mithril shield");
  shield->set_short("A mithril shield");
  shield->set_long(
                  "You see a mithril shield:\n\n"+
                "You think that it's a good protection.\n"+
                "It's weight seems to be so 2 pounds and\n"+
                "it seems to be made for a large elf.\n");
  shield->set_weight(2);
  shield->set_value(300);
  shield->set_type("shield");
  shield->set_ac(1);
  shield->set_size(3);
  
  robe->set_name("robe");
  robe->set_alias("blue robe");
  robe->set_short("A soft blue robe");
  robe->set_long(
                  "You see a soft blue robe :\n\n"+
                "You think that it's a good protection.\n"+
                "It's weight seems to be so 2 pounds and\n"+
                "it seems to be made for a large human.\n");
  robe->set_weight(2);
  robe->set_value(100);
  robe->set_type("cloak");
  robe->set_ac(1);
  robe->set_size(3);
  
  gauntlet->set_name("gauntlets");
  gauntlet->set_alias("mithril gauntlets");
  gauntlet->set_short("A pair of mithril gauntlets");
  gauntlet->set_long(
                  "You see a pair of mithril gauntlets :\n\n"+
                "You think that it's a good protection.\n"+
                "It's weight seems to be so 1 pound and\n"+
                "it seems to be made for a large human.\n");
  gauntlet->set_weight(1);
  gauntlet->set_value(200);
  gauntlet->set_type("glove");
  gauntlet->set_ac(1);
  gauntlet->set_size(3);
  
  sword->set_name("sword");
  sword->set_alt_name("sharp sword");
  sword->set_alias("longsword");
  sword->set_short("A sharp sword");
  sword->set_long(
                "You see a sharp, mithril longsword :\n\n"+
                "You think that it's a very good weapon.\n"+
                "It's weight seems to be so 8 pounds and\n"+
                "it seems to be made to wield in any hand.\n");
  sword->set_weight(4);
  sword->set_value(6000);
  sword->set_class(20);
  sword->set_use(1800);
  sword->set_level(15);
  move_object(mail,TO);
  move_object(boots,TO);
  move_object(gauntlet,TO);
  move_object(shield,TO);
  move_object(helmet,TO);
  move_object(robe,TO);
  move_object(sword,TO);
  command("wear mail");
  command("wear boots");
  command("wear gauntlets");
  command("wear shield");
  command("wear robe");
  command("wear shield");
  command("wear helmet");
  command("wear robe");
  command("wield sword");
/*  call_out("move_me",20);*/
  }
  
  move_me() {
   this_object()->random_move();
   call_out("move_me",20);
   }
   
