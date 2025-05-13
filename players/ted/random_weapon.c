#include "std.h"


/* ------------------------------------------------------------------------- */
/*             Created by Ted                                                */
/*   This will create some random armor and put it on the monster            */
/*   from which this is called from......simply put this line in:            */
/*                                                                           */
/* call_other("players/ted/random_weapon","make_item", monster_obj, level);  */
/*                                                                           */
/*   where monster_ob is the monster currently being created and the         */
/*   level is the level of the monster. For example:                         */
/*                                                                           */
/* guard = clone_object("obj/monster");                                      */
/* call_other(guard, "set_name", "Treasury Guard");                          */
/* call_other(guard, "set_level", 14);                                       */
/* .                                                                         */
/* etc                                                                       */
/* .                                                                         */
/* call_other("players/ted/random_weapon","make_item", guard, 14);           */
/*                                                                           */
/* ------------------------------------------------------------------------- */


make_item(ob, level) {
 int length, test, value, weight, class;
 string name, alias, long, short;
 object item;

 test = random(100);
 if(level >= 5)
    test = random(100) + level;
 if(level >= 10)
    test = random(100) + (level*2);
 if(test >= 50) {
   length = random(3) + 1;
   if(level >= 5)
     length = random(3) + 4;
   if(level >= 10)
     length = random(5) + 6;
   if(level >= 15)
     length = random(5) + 10;

   if(length == 1) {
     name = "knife";
     alias = "knife";
     short = "A Small Knife";
     long = "A small, sharp knife.\n";
     class = 6;
     weight = 1;
     value = 12;
   } if(length == 2) {
     name = "dagger";
     alias = "dagger";
     short = "A Small Dagger";
     long = "A small, sharp dagger.\n";
     class = 7;
     weight = 1;
     value = 15;
   } if(length == 3) {
     name = "hand axe";
     alias = "axe";
     short = "A Hand Axe";
     long = "A short handled axe.\n";
     class = 9;
     weight = 1;
     value = 25;
   } if(length == 4) {
     name = "short sword";
     alias = "sword";
     short = "A Short Sword";
     long = "A shiny short sword.\n";
     class = 10;
     weight = 2;
     value = 100;
   } if(length == 5) {
     name = "scimitar";
     alias = "scimitar";
     short = "A Scimitar";
     long = "A curved sword, it's shape is strange yet deadly.\n";
     class = 11;
     weight = 2;
     value = 275;
   } if(length == 6) {
     name = "hooked blade";
     alias = "blade";
     short = "A Hooked Blade";
     long = "This hooked blade looks quite deadly.\n";
     class = 12;
     weight = 3;
     value = 550;
   } if(length == 7) {
     name = "longsword";
     alias = "longsword";
     short = "A Longsword";
     long = "This is the weapon of choice for Knights and Fighters.\n";
     class = 14;
     weight = 3;
     value = 1200;
   } if(length == 8) {
     name = "broadsword";
     alias = "broadsword";
     short = "A Broadsword";
     long = "This is the weapon of choice for Knights and Fighters.\n";
     class = 14;
     weight = 3;
     value = 1200;
   } if(length == 9) {
     name = "axe";
     alias = "battle axe";
     short = "A Battle Axe";
     long = "This is the weapon of choice for Knights and Fighters.\n";
     class = 14;
     weight = 3;
     value = 1200;
   } if(length == 10) {
     name = "sword of fire";
     alias = "sword";
     short = "A Sword of Fire";
     long = "Fire glimmers along the edge of the blade of this sword.\n";
     class = 15;
     weight = 4;
     value = 2000;
   } if(length == 11) {
     name = "sword of frost";
     alias = "sword";
     short = "A Sword of Frost";
     long = "Frost glints along the edge of the blade of this sword.\n";
     class = 15;
     weight = 4;
     value = 2000;
   } if(length == 12) {
     name = "bastard sword";
     alias = "sword";
     short = "A Bastard Sword";
     long = "This is a deadly sword used by the most powerful of fighters.\n";
     class = 16;
     weight = 4;
     value = 3000;
   } if(length == 13) {
     name = "two handed sword";
     alias = "sword";
     short = "A Two-Handed Sword";
     long = "This is a large two-handed sword, it's weight and sharpness\nmake it a very deadly weapon.\n";
     class = 17;
     weight = 4;
     value = 4200;
   } if(length == 14) {
     name = "great sword";
     alias = "sword";
     short = "A Great Sword";
     long = "This HUGE sword is taller than you are and much more deadly!\n";
     class = 18;
     weight = 4;
     value = 6200;
   }
   item = clone_object("obj/weapon");
   call_other(item, "set_name", name);
   call_other(item, "set_alias", alias);
   call_other(item, "set_short", short);
   call_other(item, "set_long", long);
   call_other(item, "set_class", class);
   call_other(item, "set_weight", weight);
   call_other(item, "set_value", value);
   move_object(item, ob);
   call_other(ob, "init_command", "wield "+alias);
   return 1;
  }
}
