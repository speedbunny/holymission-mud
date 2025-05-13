#include "/players/arthur/defs/ardefs.h"
inherit "obj/monster";
object cane;
reset(arg) {
   ::reset(arg);
   if(!arg) {

   switch(random(2)+1)
   { 
    case 1: {
     set_name("An adult Triceratops");
     set_alias("triceratops");
     set_alt_name("An adult Triceratops");
     set_level(30);
     add_money(random(1500));
     set_race("dino");
     set_short("An adult Triceratops");
     set_long("This huge Triceratops, you would feel much better if you left here.\n");
     set_spell_dam(100);
     set_chance(30);
     set_spell_mess1("The Triceratops runs around wildly.\n");
     set_spell_mess2("The Triceratops charges towards you!\nYou feel your bones break as you are ran over.\n");
     break;}
    case 2: {
     set_name("adult Triceratops");
     set_alias("riceratops");
     set_alt_name("adult Triceratops");
     set_level(30);
     add_money(random(1500));
     set_race("dino");
     set_short("An adult Triceratops");
     set_long("This huge Triceratops, you would feel much better if you left here.\n");
     set_spell_dam(100);
     set_chance(30);
     set_spell_mess1("The Triceratops runs around wildly.\n");
     set_spell_mess2("The Triceratops charges towards you!\nYou feel your bones break as you are ran over.\n");
     break;
     }
     /*
    case 3: {
     set_name("A Shreeker");
     set_alias("shreeker");
     set_alt_name("A Shreeker");
     set_level(15);
     add_money(50);
     set_race("shreeker");
     set_aggressive(1);
     set_short("A Shreeker");
     set_long("The Shreeker looks like it fears no one, so you better watch out!\n");
     set_wc(20);
     set_spell_dam(random(15));
     set_chance(65);
     set_spell_mess1("The Shreeker violently screams at the top of its lungs.");
     set_spell_mess2("The Shreeker burns your eardrums as it screams violently.");
     break;
     }
    case 4: {
     set_name("A Tyrantisorous Rex");
     set_alias("rex");
     set_alt_name("A Tyrantisorous Rex");
     set_level(30);
     add_money(1000+random(2000));
     set_race("dino");
     set_short("A Tyrantisorous Rex");
     set_long("Watch where you walk! You may be stepped on smashing you to a bloody pulp\n"+
     "The fealing of power comming from the Rex almost makes you run out of this\n"+
     "room without seeing anything else.\n");
     set_spell_dam(random(100));
     set_chance(20);
     set_spell_mess1("Tyrantisorous starts chewing.");
     set_spell_mess2("The Tyrantisorous Takes a giant bite out of you!");
     break;
     }
    case 5: {
     set_name("A Tyrantisorous Rex");
     set_alias("rex");
     set_alt_name("A Tyrantisorous Rex");
     set_level(30);
     add_money(1000+random(2000));
     set_race("dino");
     set_short("A Tyrantisorous Rex");
     set_long("Watch where you walk! You may be stepped on smashing you to a bloody pulp\n"+
     "The fealing of power comming from the Rex almost makes you run out of this\n"+
     "room without seeing anything else.\n");
     set_spell_dam(random(100));
     set_chance(20);
     set_spell_mess1("Tyrantisorous starts chewing.");
     set_spell_mess2("The Tyrantisorous Takes a giant bite out of you!");
     break;
     }
    case 6: {
     set_name("A Tyrantisorous Rex");
     set_alias("rex");
     set_alt_name("A Tyrantisorous Rex");
     set_level(15);
     add_money(1000+random(2000));
     set_race("dino");
     set_short("A Tyrantisorous Rex");
     set_long("Watch where you walk! You may be stepped on smashing you to a bloody pulp\n"+
     "The fealing of power comming from the Rex almost makes you run out of this\n"+
     "room without seeing anything else.\n");
     set_spell_dam(random(100));
     set_chance(20);
     set_spell_mess1("Tyrantisorous starts chewing.");
     set_spell_mess2("The Tyrantisorous Takes a giant bite out of you!");
     break;}
    case 7: {
     set_name("A Tyrantisorous Rex");
     set_alias("rex");
     set_alt_name("A Tyrantisorous Rex");
     set_level(15);
     add_money(1000+random(2000));
     set_race("dino");
     set_wc(50);
     set_ac(200);
     set_hp(10000);
     set_short("A Tyrantisorous Rex");
     set_long("Watch where you walk! You may be stepped on smashing you to a bloody pulp\n"+
     "The fealing of power comming from the Rex almost makes you run out of this\n"+
     "room without seeing anything else.\n");
     set_spell_dam(random(100));
     set_chance(20);
     set_spell_mess1("Tyrantisorous starts chewing.");
     set_spell_mess2("The Tyrantisorous Takes a giant bite out of you!");
     break;}
    case 8: {
     set_name("A Tyrantisorous Rex");
     set_alias("rex");
     set_alt_name("A Tyrantisorous Rex");
     set_level(15);
     add_money(1000+random(2000));
     set_race("dino");
     set_short("A Tyrantisorous Rex");
     set_long("Watch where you walk! You may be stepped on smashing you to a bloody pulp\n"+
     "The fealing of power comming from the Rex almost makes you run out of this\n"+
     "room without seeing anything else.\n");
     set_spell_dam(random(100));
     set_chance(20);
     set_spell_mess1("Tyrantisorous starts chewing.");
     set_spell_mess2("The Tyrantisorous Takes a giant bite out of you!");
     break;}
    case 9: {
     set_name("A Tyrantisorous Rex");
     set_alias("rex");
     set_alt_name("A Tyrantisorous Rex");
     set_level(15);
     add_money(1000+random(2000));
     set_race("dino");
     set_short("A Tyrantisorous Rex");
     set_long("Watch where you walk! You may be stepped on smashing you to a bloody pulp\n"+
     "The fealing of power comming from the Rex almost makes you run out of this\n"+
     "room without seeing anything else.\n");
     set_spell_dam(random(100));
     set_chance(20);
     set_spell_mess1("Tyrantisorous starts chewing.");
     set_spell_mess2("The Tyrantisorous Takes a giant bite out of you!");
     break;}
    case 10: {
     set_name("A Tyrantisorous Rex");
     set_alias("rex");
     set_alt_name("A Tyrantisorous Rex");
     set_level(15);
     add_money(1000+random(2000));
     set_race("dino");
     set_short("A Tyrantisorous Rex");
     set_long("Watch where you walk! You may be stepped on smashing you to a bloody pulp\n"+
     "The feeling of power comming from the Rex almost makes you run out of this\n"+
     "room without seeing anything else.\n");
     set_spell_dam(random(100));
     set_chance(20);
     set_spell_mess1("Tyrantisorous starts chewing.");
     set_spell_mess2("The Tyrantisorous Takes a giant bite out of you!");
     break;} */
    }
   }
  }
