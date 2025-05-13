/* ------------------------------------------------------------------------- 
             Created by Ted                                          
   This will create some random armor and put it on the monster       
   from which this is called from......simply put this line in:        
                                                                        
 call_other("players/ted/random_armor","make_item", monster_obj, level); 
                                                                  
   where monster_ob is the monster currently being created and the 
   level is the level of the monster. For example:
                                                
 guard = clone_object("obj/monster");            
 call_other(guard, "set_name", "Treasury Guard"); 
 call_other(guard, "set_level", 14);               
 .                                                               
 etc                                                            
 .                                                             
 call_other("players/ted/random_armor","make_item", guard, 14); 
                                                               
 ------------------------------------------------------------------------- */



make_item(ob, level) {
 int length, test;
 object item;

 test = random(100);
 if(level >= 10)
    test = random(100) + level;
 if(level >= 15)
    test = random(100) + (level*2);
 if(test >= 60) {
   length = random(6);
   if(level >= 10)
     length = random(8);
   if(level >= 15)
     length = random(16);
   if(level >= 19)
     length = random(21);
  }


  if(!item) {
    item = allocate(21);
     item[0] = "players/ted/items/poly_scroll";
     item[1] = "players/ted/items/bag_of_holding";
     item[2] = "players/ted/items/identify";
     item[3] = "players/ted/items/crystal_ball";
     item[4] = "players/ted/items/crystal_ball";
#if 0
     item[4] = "players/ted/items/summon_scroll";
#endif
     item[5] = "players/ted/items/poly_scroll";
     item[6] = "players/ted/items/wand_of_cold";
     item[7] = "players/ted/items/identify";
     item[8] = "players/ted/items/wand_of_fire";
     item[9] = "players/ted/items/raise_rod";
     item[10] = "players/ted/items/wand_of_stars";
     item[11] = "players/ted/items/identify";
     item[12] = "players/ted/items/wand_of_cold";
#if 0
     item[13] = "players/ted/items/summon_scroll";
#endif
     item[13] = "players/ted/items/raise_rod";
     item[14] = "players/ted/items/fear_wand";
     item[15] = "players/ted/items/wand_of_fire";
     item[16] = "players/ted/items/healpotion";
     item[17] = "players/ted/items/cure_staff";
     item[18] = "players/ted/items/regen_ring";
#if 0
     item[19] = "players/ted/items/invis_ring";
     item[20] = "players/ted/items/invis_ring";
#endif /* Done by Moonchild */
     item[19] = "players/ted/items/bag_of_holding";
     item[20] = "players/ted/items/poly_scroll";
#if 0
     item[20] = "players/ted/items/black_sphere"; /* Done by Herp */
#endif
   }
   move_object(clone_object(item[length]), ob);
   return 1;
}
