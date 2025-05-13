#include "std.h"


/* ------------------------------------------------------------------------- */
/*             Created by Ted                                                */
/*   This will create some random armor and put it on the monster            */
/*   from which this is called from......simply put this line in:            */
/*                                                                           */
/* call_other("players/ted/random_treasure","make_item", monster_obj,level); */
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
/* call_other("players/ted/random_treasure","make_item", guard, 14);         */
/*                                                                           */
/* ------------------------------------------------------------------------- */

make_item(ob, level) {
 int length, one, two, three, test, value, weight;
 string first, second, third, alias, id, short;
 object item;
 string array1, array2, array3;

 test = random(100);
 if(level >= 5)
    test = random(100) + level;
 if(level >= 10)
    test = random(100) + (level*2);
 if(test >= 50) {
   length = random(4) + 1;
   one = 0;
   two = 0;
   three = 0;
   if(length == 1)
     one = random(8) + 1;
   if(length == 2) {
     two = random(6) + 1;
     three = random(6) + 1;
   } if(length == 3) {
     one = random(8) + 1;
     two = random(6) + 1;
     three = random(6) + 1;
   } if(length == 4) {
     one = random(8) + 1;
     three = random(6) + 1;
   }
   array1 = allocate(9);
   array2 = allocate(7);
   array3 = allocate(7);

   array1[1] = "pearl";
   array1[2] = "diamond";
   array1[3] = "sapphire";
   array1[4] = "ruby";
   array1[5] = "coral";
   array1[6] = "ivory";
   array1[7] = "topaz";
   array1[8] = "emerald";

   array2[1] = "gold ";
   array2[2] = "platinum ";
   array2[3] = "silver ";
   array2[4] = "electrum ";
   array2[5] = "copper ";
   array2[6] = "bronze ";

   array3[1] = "bracelet";
   array3[2] = "necklace";
   array3[3] = "tiara";
   array3[4] = "bauble";
   array3[5] = "buckle";
   array3[6] = "carving";

   if((one > 0) && (two > 0) && (three > 0)) {
     short = "A "+array1[one]+" and "+array2[two]+array3[three];
     alias = array3[three];
   }
   if((one > 0) && (two == 0) && (three > 0)) {
     short = "A "+array1[one]+" "+array3[three];
     alias = array3[three];
   }
   if((one == 0) && (two > 0) && (three > 0)) {
     short = "A "+array2[two]+array3[three];
     alias = array3[three];
   }
   if((one > 0) && (two == 0) && (three == 0)) {
     short = "A large "+array1[one];
     alias = array1[one];
   }
   value = random(50) + 50;
   if(level >= 10)
     value = random(200) + 100;
   if(level >= 15)
     value = random(600) + 200;
   if(level >= 19)
     value = random(1000) + 500;
   weight = 1;
   if(value >= 500)
     weight = 2;
   item = clone_object("obj/treasure");
   call_other(item, "set_id", alias);
   call_other(item, "set_alias", alias);
   call_other(item, "set_short", short);
   call_other(item, "set_long", short+", it looks quite expensive.\n");
   call_other(item, "set_weight", weight);
   call_other(item, "set_value", value);
   move_object(item, ob);
   return 1;
  }
}
