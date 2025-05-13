
/* ------------------------------------------------------------------------- */
/*             Created by Ted                                                */
/*   This will create some random armor and put it on the monster            */
/*   from which this is called from......simply put this line in:            */
/*                                                                           */
/* call_other("players/ted/random_armor","make_item", monster_obj, level);   */
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
/* call_other("players/ted/random_armor","make_item", guard, 14);            */
/*                                                                           */
/* ------------------------------------------------------------------------- */



make_item(ob, level) {
 int length, test;
 string size;
 object item, junk;

length = random(5)+1;
  if((length == 4) && (random(3) == 2)) size = "any";
   else size = "medium";
  if(length == 1) size = "small";
  if(length == 2) size = "medium";
  if(length == 3) size = "large";
  if(length == 5) size = "small";
 test = random(100);
 if(level >= 5)
    test = random(100) + level;
 if(level >= 10)
    test = random(100) + (level*2);
 if(test >= 50) {
   length = random(4);
   if(level >= 10)
     length = random(7);
   if(level >= 15)
     length = random(7) + 4;
   if(level >= 19)
     length = random(9) + 5;

  if(!item) {
   item = allocate(15);
    item[0] = "players/ted/armors/leather_vest";
    item[1] = "players/ted/armors/leather_armor";
    item[2] = "players/ted/armors/small_shield";
    item[3] = "players/ted/armors/chain_shirt";
    item[4] = "players/ted/armors/leather_gloves";
    item[5] = "players/ted/armors/medium_shield";
    item[6] = "players/ted/armors/leather_boots";
    item[7] = "players/ted/armors/steel_cap";
    item[8] = "players/ted/armors/chainmail";
    item[9] = "players/ted/armors/wool_cloak";
    item[10] = "players/ted/armors/amulet_of_prot";
    item[11] = "players/ted/armors/ring_of_protection";
    item[12] = "players/ted/armors/platemail";
    item[13] = "players/ted/armors/cloak_of_protection";
    item[14] = "players/ted/armors/shield_of_light";
  }
  junk = clone_object(item[length]);
  if(length != 2 || length != 5 || length != 10 || length != 11)
   call_other(junk, "set_size", size);
  move_object(junk, ob);
  call_other(ob, "init_command", "wear "+junk->query_type());
  return 1;
  }
}
