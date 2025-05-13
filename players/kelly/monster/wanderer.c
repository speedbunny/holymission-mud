inherit "obj/monster";
 
object staff,shoes,knapsack,jacket;
 
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("wanderer");
 set_size(3);
 set_male();
 set_level(17);
 set_hp(750);
 set_al(50);
 set_race("elf");
 set_short("A wanderer");
 set_long("He's a wandering elf, old and wise. He knows how to survive"+
   "\nin the cruel reality.\n");
 set_ac(3);
 set_wc(10);
 set_aggressive(0);
 set_move_at_reset(1);
 set_spell_mess1("The wanderer quickly turns around and hits his opponent "+
      "with a deadly karate-kick.");
 set_spell_mess2("You're hit by a deadly karate-kick.");
 set_spell_dam(99);
 set_chance(5); 
 
 
 shoes=clone_object("/obj/armour");  
 shoes->set_name("shoes");
 shoes->set_size(3);
 shoes->set_type("boots");
 shoes->set_ac(1);
 shoes->set_value(500);
 shoes->set_weight(2);
 shoes->set_short("Tough leather shoes");
 shoes->set_long("Shoes, made of tough leather, to climb mountains.\n");
 move_object(shoes,this_object());
 init_command("wear shoes");

 jacket=clone_object("/obj/armour");
 jacket->set_size(3);
 jacket->set_name("jacket");
 jacket->set_ac(1);
 jacket->set_value(450);
 jacket->set_weight(2);
 jacket->set_short("A leather jacket");
 jacket->set_long("A jacket made of tough leather.\n");
 jacket->set_type("armour");
 move_object(jacket,this_object());
 init_command("wear jacket");

 staff=clone_object("obj/weapon");
 staff->set_name("staff");
 staff->set_class(18);
 staff->set_short("A wooden staff");
 staff->set_long("A staff made of hard ebony wood.\n");
 staff->set_value(1500);
 staff->set_weight(2);
 move_object(staff,this_object());


 init_command("wield staff");
 
 knapsack=clone_object("/obj/container");
 knapsack->set_name("knapsack");
 knapsack->set_alias("sack");
 knapsack->set_short("A knapsack");
 knapsack->set_long("It's a big leather knapsack.\n");
 knapsack->set_weight(2);
 knapsack->set_value(500);
 knapsack->set_max_weight(20);
 knapsack->set_read("Made in Nenzing/Vorarlberg.\n");
 move_object(knapsack,this_object());
 
}
 
 
