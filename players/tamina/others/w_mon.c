/* ################################################################################### 

                        NEW MONSTER            (c) Whisky ....
                        
   This new object/monster has some new function:
   
   1.) set_mloc: It defines the monster hit-locations ....in a block ({})
   2.) set_ploc: It defines the player hit-locations ..... in a block ({})
   3.) set_parry: It defines the chance to fail absolutely .... as integer
   4.) set_follow_change: It defines the change of a monster to follow in percent
   5.) set_feelings: Gives your monster some standard feelings.....
 
   ################################################################################### 
   
   example:
   
   inherit "players/whisky/genobj/monster";
   
     reset(arg) {
       ::reset(arg);
       
     if (arg) return;
      
     set_name("orc");
     set_short("An orc");
     set_long("A dirty orc\n");
     set_level(2);
     set_mloc(({ "head","torso","right foot","left foot","right claw","left claw"}));
     set_ploc(({ "head","torso","right foot","left foot","right arm","left arm"}));
     set_parry(40);
     set_follow_change(80);
     set_feelings();
     
     
     }
   ################################################################################### */
     
#define TO this_object()
#define TON TO->query_name()
#define TP this_player()
#define TPN TP->query_name()
#define SAY(x) tell_room(environment(),x)
#define E environment
#define TPPOS TP->query_possessive()
#define TOPOS TO->query_possessive()
   
inherit "obj/monster";

      
  string array, array2, array3; 
  int follow_chance, parry_chance, m_feelings, no_fear;
  
reset(arg) {
   ::reset(arg);
  
  if (arg) return;
    
   }
   
 id(str) { 
   if (::id(str)) return 1;
   else return str=="An unfinished monster";
   } 
   
      
set_mloc(monst) {
   int i;
   
   if ( sizeof( monst ) < 1 )
      return;
   
   array = allocate( sizeof( monst ) );
   
   array = monst;
   return 1;
}

query_mloc() {
  if (array) return array;
  else return;
  }
  
set_ploc(play) {
  int i;
   
   if ( sizeof( play ) < 1 )
      return;
   
   array2 = allocate( sizeof( play ) );
   
  array2=play;
  return 1;
}

query_ploc() {
 if (array2) return array2;
 else return;
 }
 
set_parry(n) {
   return parry_chance=n;
   }

query_parry() {
   if (parry_chance) return parry_chance;
   else return;
   }
      
set_follow_chance(c) {
   return follow_chance=c;
   }
   
query_follow_chance() {
   if (follow_chance) return follow_chance;
   else return;
   }
   
set_feelings() {
    m_feelings=1;
    }
    
query_feelings() {
   if (m_feelings) return 1;
   else return;
   }
   
set_friends(friends) {
   int i;
   if ( sizeof( friends ) < 1 )
    return;
   
   array3 = allocate( sizeof( friends ) );
   
   array3=friends;
   return 1;
}

query_friends() {
 if (array3) return array3;
 else return;
 }
 
 init() {
   friends();
   ::init();
   }
   

/* ############################  friends of the monster ############################## */

friends() {
  int i;
  object friend;
  if (array3 && (sizeof(array3)) < 1) return;
  friend=find_living(array3[i]);
  
  if (TP) {
     for(i=0;i<sizeof(array3);i++) {
       if ( array3[i] && find_living(array3[i]) && (find_living(array3[i])->query_attack()==TP)) { 
          attack_object(TP);
          }
        }
    return 1;
    }
   return;
   }
      

/* ########################## when the monster is attacked ########################### */

attack() {
  string object_name, attacker_name, attacker_poss;
  object attacker;
     if ( array2 && (sizeof(array2)) < 1 ) return;
     
     if (::attack()) {
  
     attacker=this_object()->query_attack();  /* because of cats */
     
     object_name=this_object()->query_name();
     attacker_name=attacker->query_name();
     attacker_poss=attacker->query_possessive();
     if (array) {
     tell_object(attacker,"\n"+object_name+" tries to hit you on your "+array2[random(sizeof(array2))]+".\n");
     tell_others("\n"+object_name+" tries to hit "+attacker_name+" on "+attacker_poss+" "+array2[random(sizeof(array2))]+".\n");
     }
     return 1;
    }
    return 0;
   }


/* ############################## the hit on the monster ############################# */
  
   
hit_player(dam) {
    string object_name, attacker_name, object_poss, dir;
    object attacker;
   
    if ( array && (sizeof(array)) < 1) return;
    
    if (random(100)<parry_chance) {
    
    attacker=this_object()->query_attack();  /* because of cats */
    if(!attacker) attacker=this_player();
    
    switch(random(4)) {
      case 0:
        dir="north";
        break;
      case 1:
        dir="south";
        break;
      case 2:
        dir="west";
        break;
      case 3:
        dir="east";
        break;
      return 1;
      }
          
    object_name=this_object()->query_name();
    attacker_name=attacker->query_name();
    object_poss=this_object()->query_possessive();
    if (array) { 
    tell_object(attacker,"You try to hit "+object_name+" on "+object_poss+" "+array[random(sizeof(array))]+
          ", but "+object_name+" makes a move to the "+dir+" and parries your attack.\n");
    tell_others(attacker_name+" tries to hit "+object_name+" on "+object_poss+" "+array[random(sizeof(array))]+
        ", but "+object_name+" makes a move to the "+dir+" and parries the attack.\n");
        }
    return;
    }
    return ::hit_player(dam);
  }


/* ######################## the follow function ##################################### */
 
     
 catch_tell(arg) {
    string who,where,how;
      
  if (sscanf(arg,"%s leaves %s.",who,where)==2) {
  if (random(100)<follow_chance) {  
     command(where);
    return 1;
    }
   return 1;
   }
    
   
 if (m_feelings) { 
   
  if (sscanf(arg,"%s smiles at you.", who)==1) { 
     say(TON+" smiles happily.\n");
     }
     
  else if (sscanf(arg,"%s falls down laughing.", who)==1) { 
     say(TON+" grins evilly.\n");
     }
      
  else if (sscanf(arg,"%s waves farewell.", who)==1) { 
     tell_object(TP,TON+" waves at you.\n");
     tell_env(TON+" waves at "+TPN+".\n");
     }
      
  else if (sscanf(arg,"%s bows gracefully.", who)==1) { 
     tell_object(TP,TON+" bows to you.\n");
     tell_env(TON+" bows to "+TPN+".\n");
     }
      
  else if (sscanf(arg,"%s curtseys gracefully.", who)==1) {
     tell_object(TP,TON+" bows to you.\n");
     tell_env(TON+" bows to "+TPN+".\n");
     }
         
  else if (sscanf(arg,"%s kisses you.", who)==1) {
     tell_object(TP,TON+" kisses you.\n");
     tell_env(TON+" kisses "+TPN+".\n");
     }
       
  else if (sscanf(arg,"%s fondles you.", who)==1) {
     say(TON+" blushes.\n");
     }
       
  else if (sscanf(arg,"%s slaps you.", who)==1) {
     tell_object(TP,TON+" slaps you.\n");
     tell_env(TON+" slaps "+TPN+"\n");
     }
       
  else if (sscanf(arg,"%s hugs you.", who)==1) {
     tell_object(TP,TON+" smiles at you.\n");
     tell_env(TON+" smiles at "+TPN+".\n");
     }
     
  else {
   if (random(100)<4) {
      say(TON+" looks around.\n");
      }
      
   return 1;
   } 
      
  return 1;
  }
  return 1;
  
  }
 
  
  tell_others(str) {
    object ob;
    int i;
    ob=all_inventory(E(TO));
    
    for (i=0;i<sizeof(ob);i++) {
        if (!ob[i]->query_attack()) {
           tell_object(ob[i],str);
           }
      }
   return 1;
   }
  
  tell_env(str) {
    object ob;
    int i;
    ob=all_inventory(E(TO));
    
    for (i=0;i<sizeof(ob);i++) {
        if (ob[i]!=TP) {
           tell_object(ob[i],str);
           }
      }
   return 1;
   }
  
     
      
