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
  int    follow_chance, parry_chance, m_feelings, no_fear, blow_price, fuck_price,
         old_chat_chance;
  status blowing, fucking;
  
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
 
set_price( blow, fuck )
{
   blow_price = blow;
   fuck_price = fuck;
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
        say(TON+" smiles at you sexily.\n");
     }
        
     else if (sscanf(arg,"%s falls down laughing.", who)==1) { 
        say(TON+" say: Don't be shy, take me.\n");
     }
         
     else if (sscanf(arg,"%s waves farewell.", who)==1) { 
        tell_object(TP,TON+" say: Why are you leaving. Am i to ugly for you.\n");
        tell_env(TON+" begins to cry bitterly.\n");
        tell_object(TP,TON+" begins to cry bitterly.\n");
     }
         
     else if (sscanf(arg,"%s bows gracefully.", who)==1) { 
        tell_object(TP,TON+" bows to you.\n");
        tell_env(TON+" bows to "+TPN+".\n");
        }
         
     else if (sscanf(arg,"%s curtseys gracefully.", who)==1) {
        tell_object(TP,TON+" smiles at you.\n");
        tell_env(TON+" smiles at "+TPN+".\n");
        }
            
     else if (sscanf(arg,"%s kisses you.", who)==1) {
        tell_object(TP,TON+" gives you a deep and very passionate kiss.\n");
        tell_env(TON+" gives "+TPN+" a deep and very passionate kiss.\n");
        }
          
     else if (sscanf(arg,"%s fondles you.", who)==1) {
        say(TON+" say: Stop that !!! First you have to pay.\n");
        }
          
     else if (sscanf(arg,"%s slaps you!", who)==1) {
        if ( TP->query_gender_string() == "male" ) {
           tell_object(TP,TON+" kicks you in your balls.\n");
           tell_env(TON+" kicks "+TPN+" in his balls.\n");
        }
        else {
           tell_object(TP,TON+" slaps you.\n");
           tell_env(TON+" slaps "+TPN+".\n");
        }
     }
     else if (sscanf(arg,"%s kicks you.   OUCH!!", who)==1) {
        if ( TP->query_gender_string() == "male" ) {
           tell_object(TP,TON+" kicks you in your balls.\n");
           tell_env(TON+" kicks "+TPN+" in his balls.\n");
        }
        else {
           tell_object(TP,TON+" kicks you.\n");
           tell_env(TON+" kicks "+TPN+".\n");
        }
     } 
     else if (sscanf(arg,"%s hugs you.", who)==1) {
        tell_object(TP,TON+" smiles at you very sexily.\n");
        tell_env(TON+" smiles at "+TPN+" very sexily.\n");
     }
     else if (sscanf(arg,"%s gives you %d gold coins.",who,how)==2) {
        if ( blowing || fucking )
           tell_object(TP,TON+" growls: I'm already working. Don't bother us and fuck off!!\n" );
        else {
           if ( how < 2500 )
              tell_object(TP,TON+" growls: Sorry, but for that price i don't make it.\n" );
           else if ( how < 5000 ) {
              tell_object(TP,TON+" smiles sexily and hugs you very affective.\n" );
              old_chat_chance = chat_chance;
              chat_chance = 0;
              blowing = 1;
              call_out( "blow1", 5, TP );
           }
           else {
              if ( TP->query_gender_string() == "male" ) {
                 tell_object(TP,TON+" necks you and fondles your pint.\n" );
                 fucking = 1;
              }
              else
                 tell_object(TP,TON+" wonders: You're no man, how can you fuck this???\n" );
           }
        }
     }
     
     else {
        if (random(100)<4)
           say(TON+" looks around.\n");
     }
         
     return 1;
   }

   return( 1 );
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
  
     
/* ----- the action - routines ------------------------------------------------------- */

blow1( player )
{
   if ( present( player, environment() ) ) {
      if ( player->query_gender_string() == "male" ) {
         tell_object( player, TON + " knees down in front of you and fondles your pint.\n" );
         tell_env( TON + " knees down in front of " + player->query_name() +
                   " and fondles his pint.\n" );
      }
      else {
         tell_object( player, TON + " kisses your breast very deeply and passionately.\n" );
         tell_env( TON + " kisses the breast of " + player->query_name() +
                   " very deeply and passionately.\n" );
      }
      call_out( "blow2", 6, player );
   }
   else {
      blowing = 0;
      old_chat_chance = chat_chance;
   }
}

blow2( player )
{
   if ( present( player, environment() ) ) {
      if ( player->query_gender_string() == "male" ) {
         tell_object( player, TON + " kisses you pint very deeply and passionately.\n" );
         tell_env( TON + " kisses the pint of " + player->query_name() +
                   " very deeply and passionately.\n" );
      }
      else {
         tell_object( player, TON + " licks carressly at your nipples.\n" );
         tell_env( TON + " licks caressly the nipples of " + player->query_name() + ".\n" );
      }
      call_out( "blow3", 10, player );
   }
   else {
      blowing = 0;
      old_chat_chance = chat_chance;
   }
}

blow3( player )
{
   if ( present( player, environment() ) ) {
      if ( player->query_gender_string() == "male" ) {
         tell_object( player, TON + " licks carressly at you balls.\n" );
         tell_env( TON + " licks carressly at the balls of " + player->query_name() + ".\n" );
      }
      else {
         tell_object( player, TON + " knees down in front of you and gives you a warm kiss nearby your pussy.\n" );
         tell_env( TON + " knees down in front of " + player->query_name() +
                   " and gives her a warm kiss nearby her pussy.\n" );
      }
      call_out( "blow4", 4, player );
   }
   else {
      blowing = 0;
      old_chat_chance = chat_chance;
   }
}

blow4( player )
{
   if ( present( player, environment() ) ) {
      if ( player->query_gender_string() == "male" ) {
         tell_object( player, TON + " takes your pint in " + TO->query_possessive() + 
                      " mouth and sucks it tenderly.\n" );
         tell_env( TON + " take the pint of " + player->query_name() + " in " +
                   TO->query_possessive() + " mouth and sucks it tenderly.\n" );
      }
      else {
         tell_object( player, TON + " gives you a very deep kiss at your pussy.\n" );
         tell_env( TON + " gives " + player->query_name() + 
                   " a very deep kiss at her pussy.\n" );
      }
      call_out( "blow5", 7, player );
   }
   else {
      blowing = 0;
      old_chat_chance = chat_chance;
   }
}

blow5( player )
{
   if ( present( player, environment() ) ) {
      if ( player->query_gender_string() == "male" ) {
         tell_object( player, TON + " begins to suck faster.\n" );
         tell_env( TON + " begins to suck faster.\n" );
      }
      else {
         tell_object( player, TON + " starts to licks at your pussy. You can feel her breath.\n" );
         tell_env( TON + " at the pussy of " + player->query_name()  + ".\n" );
      }
      call_out( "blow6", 5, player );
   }
   else {
      blowing = 0;
      old_chat_chance = chat_chance;
   }
}

blow6( player )
{
   if ( present( player, environment() ) ) {
      if ( player->query_gender_string() == "male" ) {
         tell_object( player, "You feel, that you can't hold it back much longer.\n" );
         tell_env( player->query_name() + " gets a red head and begins to perspire all over his body.\n" );
      }
      else {
         tell_object( player, "You feel, that you'll comming soon. You begin to perspire all over your body.\n" );
         tell_env( player->query_name() + " begins to perspire all over her body.\n" );
      }
      call_out( "blow7", 5, player );
   }
   else {
      blowing = 0;
      old_chat_chance = chat_chance;
   }
}

blow7( player )
{
   if ( present( player, environment() ) ) {
      if ( player->query_gender_string() == "male" ) {
         tell_object( player, "You can't hold yourself back and spread all you sperm into " + TON +
                      "'s mouth. " + capitalize( TO->query_pronoun()) +
                      " smiles at you pardonly and swallow all your sperm.\n" +
                      "Wow, that was the best orgasm, you've ever had!!!\n" );
         tell_env( player->query_name() + " can't hold it back any longer and spreads all his\n" +
                   "sperm over " + TON + ". He looks very glad now!!!\n" );
      }
      else {
         tell_object( player, "As " + TON + " begins to lick faster, you get a bombastic orgasm.\n" +
                      "You wind yourself in completely exhaustion and feel a great silence coming\n" +
                      "over you. That was the best orgasm, you've ever had!!!\n" );
         tell_env( player->query_name() + " winds herself in a bombastic orgasm.\n" );
      }
      call_out( "blow8", 10, player );
   }
   else {
      blowing = 0;
      old_chat_chance = chat_chance;
   }
}

blow8( player )
{
   if ( present( player, environment() ) ) {
      if ( player->query_gender_string() == "male" ) {
         tell_object( player, TON + " stands up and gives you a passionate kiss.\n" +
                      TON + " says: You were great, darling.\n" );
         tell_env( TON + " stands up and gives " + player->query_name() + " a passionate kiss.\n" +
                   TON + " says: You were great, darling.\n" );
      }
      else {
         tell_object( player, TON + " stands up and gives you a passionate kiss.\n" +
                      TON + " says: I love you, darling. It is great, to make love with a female!\n" );
         tell_env( TON + " stands up and gives " + player->query_name() + " a passionate kiss.\n" );
      }
   }
   
   blowing = 0;
   old_chat_chance = chat_chance;
}


