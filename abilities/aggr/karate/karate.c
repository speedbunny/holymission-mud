// ------------------------------------------------------------------------ 
// karate
// used at the ninjas
// patience
// ------------------------------------------------------------------------ 

inherit  "/abilities/ability";
#include "/spells/spell.h"

void display_msg( int dam, string tp_name, string oppo_name, object oppo );

void reset( int tick )
{
   ::reset(tick);
   if ( tick ) return;

   set_name( "karate" );
   set_syntax( "karate [opponent]" );
   set_speed( NEXT_HB );
   set_guild_allowed( 8, 3 );
   set_kind( AGGRESSIVE );
   set_cost( 10 );
   set_auto_inc();
   set_player_help( 
      "Karate is a nihonese fighting style. It enables you to use your feet\n"+
      "in combat and to make additional hits. A high mastery of this ability\n"+
      "enables you to do awesome damage to your opponent." );
}

void display_prepare( object who )
{
   ;
}

void release( string arg, int act_skill, int max_skill )
{
   object oppo;
   int    dam;
   string oppo_name, tp_name;

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;

   oppo_name = funcall( call, oppo, "query_name" );
   tp_name = funcall( call, TP, "query_name" );

   if ( check_success( act_skill, max_skill ) ) {
      dam = random(TP->query_dex()+TP->str());
      dam = oppo->hit_by_ability( dam, 0 );
      display_msg( dam, tp_name, oppo_name, oppo );
   }
   else {
      display_msg( 0, tp_name, oppo_name, oppo );
      oppo->attacked_by( TP );
   }
}

void display_msg( int dam, string tp_name, string oppo_name, object oppo )
{
   string how, what, wfoot;

   if ( dam == 0 ) 
   {
      write("You miss your opponent and your foot flies a mile high !\n");
      tell_object(oppo, tp_name+" missed you with mighty karate sweep.\n" );
      say(tp_name+" missed "+ oppo_name +" with a might karate sweep.\n",oppo);
      return;
   }
    
   if ( oppo && !(oppo->query_ghost()) && living(oppo) )
   {
      switch ( dam ) {
         case 1:
         case 2:
         case 3:
         case 4:
         case 5:  how = " FOOT !!!";
                  what = "kick";
                  break;
         case 6:
         case 7:
         case 8:  how = " FOOT in the stomach !!!";
                  what = "kick";
                  break;
         case 9:
         case 10:
         case 11: how = " FOOT pretty hard in the stomach !!!";
                  what = "kick";
                  break;
         case 12:
         case 13:
         case 14: how = " FOOT very hard at the torso !!!";
                  what = "kick";
                  break;
         case 15:
         case 16:
         case 17: how = " FOOT extremely hard at the torso !!!";
                  what = "kick";
                  break;
         case 18:
         case 19:
         case 20: how = " FOOT with a bonecrushing sound at the head !!!";
                  what = "hit";
                  break;
         case 21: 
         case 22: 
         case 23: 
         case 24: 
         case 25: how = " FOOT critically at the head !!!";
                  what = "hit";
                  break;
         default: write( "BOOM, ZACK, iiiiiin de goschn !!!!!!\n" );
                  say( "You cover your eyes, as "+tp_name+" nearly destroys "+
                       "the head of "+oppo_name+"\nwith a mighty karate "+
                       "sweep !!!\n", oppo );
                  tell_object( oppo, "You can see nothing else than "+
                       "blood, as "+tp_name+" places "+TPPOS+" foot into your "+
                       "face !!!\n" );
                  return;
     }

     if ( random(2) ) wfoot = "right";
     else             wfoot = "left";
     
     write( "You " + what + " " + oppo_name + 
                 " with your " + wfoot + how + "\n");
     tell_object(oppo, tp_name + " " + what + "s you with " + TPPOS +
                 " " + wfoot + how + "\n");
     say( tp_name + " " + what + "s " + oppo_name + " with " + TPPOS +
          " " + wfoot + how + "\n", oppo );
   }
   else {
      say( "You double over, as "+tp_name+" destroys the head of "+oppo_name+
           "\nwith a mighty karate sweep !!!\n" );
      write( "You wipe away the brain of the "+oppo_name+" from your foot "+
             "...\n" );
   }
}
