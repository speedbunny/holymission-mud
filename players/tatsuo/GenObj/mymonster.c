#define TO     (this_object())
#define TON    (TO->query_name())
#define TP     (this_player())
#define TPN    (TP->query_name())
#define SAY(x) (tell_room(environment(),x))
#define TPPOS  (TP->query_possessive())
#define TOPOS  (TO->query_possessive())
   
inherit "obj/monster";

      
string friends;
int    follow_chance, parry_chance, has_feelings, no_fear,
       accuracy, isNinja;
  
reset(arg)
{
   ::reset( arg );
  
   if ( arg )
      return;
      
   follow_chance = 0;
   parry_chance = 0;
   has_feelings = 0;
   no_fear = 0;

   set_dead_ob( "/players/patience/eastMonst/monst_died" );
}
 
init()
{
   ::init();

   friends();
}
   
   
id(str)
{ 
   if ( ::id(str) )
      return( 1 );
   else
      return( str == "An unfinished monster" );
} 
   

set_friends( arr )
{
   if ( !arr || sizeof( arr ) < 1 )
      return;
   
   friends = allocate( sizeof( arr ) );
   friends = arr;

   return( 1 );
}

set_follow_chance( c )
{
   follow_chance = c;
}

set_feelings( )
{
   has_feelings = 1;
}

set_parry( p )
{
   parry_chance = p;
}

set_no_fear() {
   no_fear = 1;
}

query_parry()         { return( parry_chance ); }
query_follow_chance() { return( follow_chance ); }
query_has_feelings()  { return( has_feelings ); }
query_no_fear()       { return( no_fear ); }
query_friends()       { return( friends ); }
      
      

/* ############################  friends of the monster ############################## */

friends()
{
   int    i;
   object fr;
   
   if ( !friends || sizeof(friends) < 1 )
      return;
     
   if ( TP ) {
      for( i = 0; i < sizeof(friends); i++) {
         if ( (TP->query_attack()) && (TP->query_attack())->id(friends[i]) ) {
            attack_object( TP );
            return( 1 );
         }
         else {
            fr = find_living(friends[i]);
            if ( fr && fr->query_attack() == TP ) {
               attack_object( TP );
               return( 1 );
            }
         }
      }
   }

   return( 1 );
}
      

/* ############################## the hit on the monster ############################# */
  
   
hit_player( dam )
{
   object attacker;
   
   if ( dam > 50 )
      return ::hit_player(dam);
   
   if ( random( 100 ) < parry_chance ) {
      attacker = this_object()->query_attack();            /* because of cats */
      ParryMess( TO, attacker );
      return( 0 );
   }
    
   return ::hit_player(dam);
}


run_away( arg )
{
   if ( no_fear )
      return( 0 );
      
   return( ::run_away( arg ) );
} 
     
catch_tell(arg)
{
   string who,where,how;
      
   if (sscanf(arg,"%s leaves %s.", who, where) == 2 ) {
      if (random(100)<follow_chance)
         command( where );
  
      return( 1 );
   }
    
   
 if (has_feelings) { 
   
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
 
  
tell_others( str )
{
   object ob;
   int    i;
   
   ob = all_inventory( environment( TO ) );
    
   for (i=0;i<sizeof(ob);i++)
      if (!ob[i]->query_attack())
         tell_object(ob[i],str);
 
   return( 1 );
}
  
tell_env(str)
{
   object ob;
   int    i;
   
   ob = all_inventory( environment( TO ) );
    
   for (i=0;i<sizeof(ob);i++)
      if (ob[i]!=TP)
         tell_object(ob[i],str);
 
   return( 1 );
}
  
/* ------------------------------------------------------------------------------------ */
/*    The messages, when you parries a hit                                              */
/*                                                                                      */
/*    -> myself (object), attacker (object)                                             */
/* ------------------------------------------------------------------------------------ */
ParryMess( me, monst )
{
   string monstName, message, message1, message2;
   object monstWeap;
   
   monstName = monst->query_name();
   monstWeap = monst->query_wielded();
   
   if ( monstWeap ) {
      message = monstName + " tries to hit you with " + monst->query_possessive() +
                " " + monstWeap->query_name() + ",\nbut ";
      message1 = monstName + " tries to hit " + me->query_name() + " with " +
                 monst->query_possessive() + " " + monstWeap->query_name() + ",\nbut ";
      message2 = "You try to hit " + me->query_name() + " with your " +
                 monstWeap->query_name() + ",\nbut ";
   }
   else {
      message = monstName + " tries to hit you with " + monst->query_possessive() +
                " physical force,\nbut ";
      message1 = monstName + " tries to hit " + me->query_name() + " with " + 
                monst->query_possessive() + " physical force,\nbut ";
      message2 = "You try to hit " + me->query_name() + " with your physical force, but\n";
   }
   
   switch( random(11) ) {
      case 0: message += "you make a move to the left and PARRY the attack.\n";
              message1 += me->query_name() + " makes a move to the left " +
                          "and PARRIES the attack.\n";
              message2 += me->query_name() + " makes a move to the left " +
                          "and PARRIES your attack.\n";
              break;
      case 1: message += "you make a move to the right and PARRY the attack.\n";
              message1 += me->query_name() + " makes a move to the right " +
                          "and PARRIES the attack.\n";
              message2 += me->query_name() + " makes a move to the right " +
                          "and PARRIES your attack.\n";
              break;
      case 2: message += "you jump to the left and PARRY the attack.\n";
              message1 += me->query_name() + " jumps to the left " +
                          "and PARRIES the attack.\n";
              message2 += me->query_name() + " jumps to the left " +
                          "and PARRIES your attack.\n";
              break;
      case 3: message += "you jump to the right and PARRY the attack.\n";
              message1 += me->query_name() + " jumps to the right " +
                          "and PARRIES the attack.\n";
              message2 += me->query_name() + " jumps to the right " +
                          "and PARRIES your attack.\n";
              break;
      case 4: message += "you jump back and PARRY the attack.\n";
              message1 += me->query_name() + " jumps back and PARRIES the attack.\n";
              message2 += me->query_name() + " jumps back and PARRIES your attack.\n";
              break;
      case 5: message += "you dodge left and PARRY the attack.\n";
              message1 += me->query_name() + " dodges left and PARRIES the attack.\n";
              message2 += me->query_name() + " dodges left and PARRIES your attack.\n";
              break;
      case 6: message += "you dodge right and PARRY the attack.\n";
              message1 += me->query_name() + " dodges right and PARRIES the attack.\n";
              message2 += me->query_name() + " dodges right and PARRIES your attack.\n";
              break;
      case 7: message += "you dodge back and PARRY the attack.\n";
              message1 += me->query_name() + " dodges back and PARRIES the attack.\n";
              message2 += me->query_name() + " dodges back and PARRIES your attack.\n";
              break;
      case 8: if ( me->query_wielded() ) {
                 message += "you raise your " + (me->query_wielded())->query_name() +
                            " and PARRY the attack.\n";
                 message1 += me->query_name() + " raises " + me->query_possessive() +
                             " " + (me->query_wielded())->query_name() +
                            " and PARRIES the attack.\n";
                 message2 += me->query_name() + " raises " + me->query_possessive() +
                             " " + (me->query_wielded())->query_name() +
                            " and PARRIES your attack.\n";
                 break;
              }
/*      case 9: if ( me->query_secWielded() ) {
                 message += "you raise your " + (me->query_secWielded())->qeury_name() +
                            " and PARRY the attack.\n";
                 message1 += me->query_name() + " raises " + me->query_possessive() +
                             " " + (me->query_secWielded())->query_name() +
                            " and PARRIES the attack.\n";
                 message2 += me->query_name() + " raises " + me->query_possessive() +
                             " " + (me->query_secWielded())->query_name() +
                            " and PARRIES your attack.\n";
                 break;
              }*/
      default: message += "you duck the swing and PARRY the attack.\n";
               message1 += me->query_name() + " ducks the swing and PARRIES the attack.\n";
               message2 += me->query_name() + " ducks the swing and PARRIES your attack.\n";
   }
   
   tell_object(me, message );
   tell_object(monst, message2 );
   say( message1, monst );
}
     

/* --- ninja-features ---------------------------------------- */

set_accuracy( a )
{
   accuracy = a;
}

query_accuracy( )
{
   return( accuracy );
}

set_ninja( )
{
   isNinja = 1;
}

query_ninja( )
{
   return( isNinja );
}
