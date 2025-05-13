#define TO this_object()

inherit "/obj/npc";

void reset(int arg) 
{
   object mail,shield,boots,helmet,gauntlet,robe,sword,horn; 
    ::reset(arg);
    
  if (arg!=0) return;
  
  set_name("elf");
  set_alt_name("guard");
  set_alias("elf guard");
  set_level(60);
  set_hp(1500);
  set_short("An elf guard");
  set_long(
          "You see a young very strong elf. He is looking like all the other\n"+
          "guards of Maria Wichteldorf, but something in his face makes you feel\n"+
          "that this elf has an awful secret.\n");
  load_chat(10,(
            { "The elf guard grins demonically.\n",
             "The elf guard says: They all will die.\n",
            }));
  load_a_chat(20,(
            { "The elf guard growls at you.\n",
              "The elf says: I kill you!\n",
            }));
  set_fol_change(100);
  set_rid_change(10);
  set_dodge(40);
  set_attacks(6);
  set_attacks_change(50);

  mail=clone_object("obj/armour");
  shield=clone_object("obj/armour");
  boots=clone_object("obj/armour");
  helmet=clone_object("obj/armour");
  gauntlet=clone_object("obj/armour");
  robe=clone_object("obj/armour");
  sword=clone_object("/players/whisky/quest/obj/ashmukur"); 
  horn=clone_object("/players/whisky/quest/obj/horn");

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
  boots->set_type("boots");
  boots->set_ac(1);
  
  helmet->set_name("mithril helmet");
  helmet->set_alias("helmet");
  helmet->set_short("A black mithril helmet");
  helmet->set_long(
                  "You a black mithril helmet:\n\n"+
                "You think that it's a very good protection.\n"+
                "It's weight seems to be so 1 pounds and\n"+
                "it seems to be made for a large elf.\n");
  helmet->set_weight(1);
  helmet->set_value(3000);
  helmet->set_type("helmet");
  helmet->set_ac(2);
  
  shield->set_name("mithril shield");
  shield->set_alias("mithril shield");
  shield->set_short("A black mithril shield");
  shield->set_long(
                  "You see a black mithril shield:\n\n"+
                "You think that it's a very good protection.\n"+
                "It's weight seems to be so 2 pounds and\n"+
                "it seems to be made for a large elf.\n");
  shield->set_weight(2);
  shield->set_value(5000);
  shield->set_type("shield");
  shield->set_ac(2);
  
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
  
  move_object(mail,TO);
  move_object(boots,TO);
  move_object(gauntlet,TO);
  move_object(shield,TO);
  move_object(helmet,TO);
  move_object(robe,TO);
  move_object(sword,TO);
  move_object(horn,TO);
  command("wear mail");
  command("wear boots");
  command("wear gauntlets");
  command("wear shield");
  command("wear robe");
  command("wear shield");
  command("wear helmet");
  command("wear robe");
  command("wield sword");
}
  
    
