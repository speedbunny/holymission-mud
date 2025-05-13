#include "/players/gareth/define.h"
inherit "/obj/npc";
   object mail,boots,helmet,sword; 

  reset(arg) {
    ::reset(arg);
    
  if (arg) return;
  
  set_name("drow guard");
  set_alt_name("guard");
  set_alias("drow");
  set_race("elf");
  set_level(60);
  set_dex(80);
  set_wc(75);
  set_short("An drow guard");
  set_long(
          "You see a very mean and nasty drow, you think he might\n"+
          "be a worthy adversery and more, and you are absolutly\n"+
          "correct. Perhaps you should leave now while there's still time.\n");
  load_chat(20,(
            { "The drow looks around.\n",
             "The drow glares at you.\n",
            }));
  load_a_chat(20,(
            { "The drow growls.\n",
              "The dark elf says: now it ends!\n",
            }));
  set_chance(2);
  set_spell_mess1("The guard splits your skulls");
  set_spell_mess2("The guards disembowels his oppenent");
  set_spell_dam(80+random(150));
  set_fol_change(20);
  set_attacks(3);
  set_dodge(30);
  set_attacks_change(50);
  set_rid_change(35);
  add_money(10000);
  
  mail=CO("obj/armour");
  boots=CO("obj/armour");
  helmet=CO("obj/armour");
  sword=CO("/players/patience/GenObj/weapon");

  mail->set_name("mail");
  mail->set_alias("scalemail");
  mail->set_short("Adamantine scalemail");
  mail->set_long(
                "A strong suit of Adamantine scalemail:\n\n"+
		"Looks like dragon scales interwoven together\n"+
		"to form a strong piece of armor that's cool.\n"+
                "The suit looks as if it's great protection.\n"+
                "It seems to weigh about 5 pounds or so and \n"+
                "it seems to be made for a dark elf.\n");
  mail->set_weight(2);
  mail->set_value(4000);
  mail->set_type("armour");
  mail->set_ac(4);
  mail->set_size(3);
  
  boots->set_name("boots");
  boots->set_alias("steel boots");
  boots->set_short("A pair of Steel boots");
  boots->set_long(
                  "You see a pair of Steel boots:\n\n"+
                  "It looks like good protection.\n"+
                  "It weighs about 1 pound or so and\n"+
                  "it seems to only fit a drow elf.\n");
  boots->set_weight(1);
  boots->set_value(800);
  boots->set_type("boot");
  boots->set_ac(1);
  boots->set_size(3);
  
  helmet->set_name("helmet");
  helmet->set_alias("adamantine helmet");
  helmet->set_short("A adamantine helmet");
  helmet->set_long(
                  "You see an adamantine helmet:\n\n"+
                  "It provides good protection for\n"+
                  "the head....what else would it protect???\n");
  helmet->set_weight(1);
  helmet->set_value(150);
  helmet->set_type("helmet");
  helmet->set_ac(1);
  helmet->set_size(3);
  
  sword->set_name("sword");
  sword->set_alt_name("glowing sword");
  sword->set_alias("longsword");
  sword->set_short("A glowing sword");
  sword->set_long(
                "You see a sharp, glowing longsword :\n\n"+
                "You think that it's a very good weapon.\n"+
                "It's weight seems to be so 8 pounds and\n"+
                "it seems to be made to wield in any hand.\n");
  sword->set_weight(4);
  sword->set_value(6000);
  sword->set_class(25);
  sword->set_use(2000);
  sword->set_level(20);
  
  MO(mail,TO);
  MO(boots,TO);
  MO(helmet,TO);
  MO(sword,TO);

  command("wear mail");
  command("wear boots");
  command("wear helmet");
  command("wield sword");

  }
  
  move_me() {
   this_object()->random_move();
   call_out("move_me",20);
   }
   
