// 240893 Moonchild changed to reduce unneeded callouts

#define TO this_object()
#define TP this_player()
#define TPN TP->query_name()
#define SAY(x) tell_room(environment(),x)

inherit "obj/monster";
  object mail, boots, sword, shield, helmet, gauntlet, robe, soul;
  reset(arg) {
   ::reset(arg);  
  if (arg) return;
  load_chat(10, ({
     "The guard looks around.\n",
     "The guard looks around.\n",
     "The guard looks around.\n",
     "The guard sighs deeply.\n",
     "The guard says: This is really a sad day.\n",
     "The guard says: The princess is so unhappy and nobody can help her.\n",
     "The guard sulks in the corner.\n",
     "The guard sulks in the corner.\n",
     "The guard bursts into tears.\n",
	}));
  set_name("guard");
  set_alt_name("human");
  set_alias("sad guard");
  set_short("A very sad human");
  set_long(
           "You see a very sad human, he is the guard of the castle of sadness.\n"+
           "In former days he was a really happy guy, but since the queen died\n"+
           "he is really sad. The only thing the sad, big guard has from former\n"+
           "days is his friendly impression in his face.\n");
  set_gender(1);
  set_whimpy(-1);
  set_level(38);
  
  mail=clone_object("obj/armour");
  shield=clone_object("obj/armour");
  boots=clone_object("obj/armour");
  helmet=clone_object("obj/armour");
  gauntlet=clone_object("obj/armour");
  robe=clone_object("obj/armour");
  sword=clone_object("obj/weapon");
  
  mail->set_name("mail");
  mail->set_alias("chainmail");
  mail->set_short("An iron chainmail");
  mail->set_long(
                "You see an iron chainmail:\n\n"+
                "You think that it's a good protection.\n"+
                "It's weight seems to be so 10 pounds and\n"+
                "it seems to be made for a large human.\n");
  mail->set_weight(8);
  mail->set_value(1200);
  mail->set_type("armour");
  mail->set_ac(3);
  mail->set_size(3);
  
  boots->set_name("boots");
  boots->set_alias("iron boots");
  boots->set_short("A pair of heavy iron boots");
  boots->set_long(
                  "You see a pair of iron boots:\n\n"+
                "You think that it's a good protection.\n"+
                "It's weight seems to be so 4 pounds and\n"+
                "it seems to be made for a large human.\n");
  boots->set_weight(3);
  boots->set_value(200);
  boots->set_type("boot");
  boots->set_ac(1);
  boots->set_size(3);
  
  helmet->set_name("helmet");
  helmet->set_alias("iron helmet");
  helmet->set_short("A heavy iron helmet");
  helmet->set_long(
                  "You a heavy iron helmet:\n\n"+
                "You think that it's a good protection.\n"+
                "It's weight seems to be so 3 pounds and\n"+
                "it seems to be made for a large human.\n");
  helmet->set_weight(2);
  helmet->set_value(150);
  helmet->set_type("helmet");
  helmet->set_ac(1);
  helmet->set_size(3);
  
  shield->set_name("shield");
  shield->set_alias("tower shield");
  shield->set_short("A heavy tower shield");
  shield->set_long(
                  "You see a heavy iron shield:\n\n"+
                "You think that it's a good protection.\n"+
                "It's weight seems to be so 8 pounds and\n"+
                "it seems to be made for a large human.\n");
  shield->set_weight(6);
  shield->set_value(300);
  shield->set_type("shield");
  shield->set_ac(1);
  shield->set_size(3);
  
  robe->set_name("robe");
  robe->set_alias("black robe");
  robe->set_short("A soft black robe");
  robe->set_long(
                  "You see a soft black robe :\n\n"+
                "You think that it's a good protection.\n"+
                "It's weight seems to be so 2 pounds and\n"+
                "it seems to be made for a large human.\n");
  robe->set_weight(2);
  robe->set_value(100);
  robe->set_type("cloak");
  robe->set_ac(1);
  robe->set_size(3);
  
  gauntlet->set_name("gauntlets");
  gauntlet->set_alias("iron gauntlets");
  gauntlet->set_short("A pair of iron gauntlets");
  gauntlet->set_long(
                  "You see a pair of iron gauntlets :\n\n"+
                "You think that it's a good protection.\n"+
                "It's weight seems to be so 2 pounds and\n"+
                "it seems to be made for a large human.\n");
  gauntlet->set_weight(2);
  gauntlet->set_value(80);
  gauntlet->set_type("glove");
  gauntlet->set_ac(1);
  gauntlet->set_size(3);
  
  sword->set_name("sword");
  sword->set_alt_name("longsword");
  sword->set_alias("iron longsword");
  sword->set_short("An iron longsword");
  sword->set_long(
                  "You see a sharp, iron longsword :\n\n"+
                "You think that it's a very good weapon.\n"+
                "It's weight seems to be so 20 pounds and\n"+
                "it seems to be made to wield in any hand.\n");
  sword->set_weight(10);
  sword->set_value(2000);
  sword->set_class(22);
  move_object(mail,TO);
  move_object(boots,TO);
  move_object(gauntlet,TO);
  move_object(shield,TO);
  move_object(helmet,TO);
  move_object(robe,TO);
  move_object(sword,TO);
  command("powerup");
  call_out("glook",10);
  }
  
  hit_player(dam) {
     
   if (random(100)<60) {
    switch(random(5)) {
      case 0:
      SAY("The sad human makes a move to the east and parries your attack.\n");
      break;
      case 1:
      SAY("The sad human makes a move to the west and parries your attack.\n");
      break;
      case 2:
      SAY("The sad human jumps high up into the air and parries your attack.\n");
      break;
      case 3:
      SAY("The sad human parries your attack with his iron longsword.\n");
      break;
      case 4:
      SAY("The sad human parries your attack with his tower shield.\n");
      break;
      return;
      }
      return;
      }
     return ::hit_player(dam);
   }
   
   attack() {
      
      
     if (::attack()) {
        switch(random(6)) {
         case 0:        
          SAY("The sad human hits your body with his iron longsword badly.\n");
          TP->hit_player(random(20));
         break;
         case 1:        
          SAY("The sad human hits your left feet with his iron longsword badly.\n");
          if (random(100<20)) call_out("pfall",1);
          TP->hit_player(random(10));
         break;
         case 2:        
          SAY("The sad human hits your right feet with his iron longsword badly.\n");
          if (random(100<20)) call_out("pfall",1);
          TP->hit_player(random(10));
         break;
         case 3:        
          SAY("The sad human gazed your head  with his iron longsword.\n");
          TP->hit_player(random(8));
         break;
         case 4:        
          SAY("The sad human tickled your left hand  with his iron longsword.\n");
          if (random(100<20)) call_out("pdrop",1);
          TP->hit_player(random(8));
         break;
         case 5:        
          SAY("The sad human tickled your left hand  with his iron longsword.\n");
          call_out("pdrop",1);
          TP->hit_player(random(8));
         break;
        return 1;
        }
       return 1;  
      
       }
     }
     
    pfall() {
      SAY(TPN+" stumbles and falls on "+TP->query_possessive()+" back.\n");
      call_out("pup",2);
      }
      
     pup() {
       SAY(TPN+" gets up again.\n");
       }
    
    
       
     pdrop() {
        object ob;
        int i;
         ob=all_inventory(TP);
         for (i=0;i<sizeof(ob);i++) {
             if (ob[i]->query_wielded()) {
                 TP->drop_one_item(ob[i]);
              }
          }
      return;
      }
    
    catch_tell(arg) {
       string str1, str2;
       
      if (sscanf(arg,"%s bows to you.",str1)==1) {
          write("The sad human introduces himself as:\n\n");
          tell_object(TP,long()+"\n");
          write("The guard bows to you.\n");
          return 1;
       }
       
      if (sscanf(arg,"%s waves %s",str1,str2)==2) {
          command("wave "+ TPN);
          return 1;
       }
       
      if (sscanf(arg,"%s arrives.",str1)==1) {
         write("The guard sulks in the corner.\n");
         call_out("sulk1",2);
         return 1;
       }
       
      if (sscanf(arg,"%s hugs you.",str1)==1) {
         write("The guard hugs you.\n");
         return 1;
       }
      return 1;
     }
     
    sulk1() {
      SAY("The sad human says: Do you know why all are so unhappy.\n");
      call_out("sulk2",4);
    }
    
    sulk2() {
      write("The guard scratches his head thinking.\n");
      call_out("sulk3",4);
     }
     
    sulk3() {
      SAY("The sad human says: Since the poor Queen died all here is so unhappy.\n");
      call_out("sulk4",4);
    }
    
    sulk4() {
      SAY("The sad human says: I wish i could see the princess happy again.\n");
      call_out("sulk5",4);
     }
     
    sulk5() {
      command("sulk");
      call_out("sulk6",4);
     }
     
    sulk6() {
      SAY("The sad human says: Also the clown is so sad that he can't bring her to laugh anymore.\n");
      command("cry");
    }
    
    
    
    
      
     
    
    
        
       
      
    
  
  
  
                 
  
  
