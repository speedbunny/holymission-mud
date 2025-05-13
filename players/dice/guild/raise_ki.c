#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define MSG    "You are already a grandmaster"

#define NINJA_TITLES "/players/patience/guild/ninja_titles"
#define GUILD_MASTER ("/guild/master")
#include "/players/patience/guild/nskill.h"


help_it( arg )
{
   if ( !arg )
      return;
   
   if ( arg == "raise" ) {
      if ( TP->query_guild() != 8 ) {
         write( "Join the ninjas and then try it again.\n" );
         return( 1 );
      }
      
      write( "You can raise your kis here. All ninja-kis can be raised here.\n\n" +
             "If you want to know the price of raising the kis, just type \"cost\"\n" +
             "This will tell you, how much experience you have to sacrify for the\n" +
             "raising. But you also can mix the experience with gold coins.\n" +
             "You always will have to pay the double amount in gold coins as you\n" +
             "have to pay in experience.\n" +
             "Exp: You have been told, that you have to sacrify 1000 experience.\n" +
             "     Now you can choose: 1. sacrifice 1000 exp,\n" +
             "                         2. sacrifice 2000 gold coins,\n" +
             "                         3. sacrifice 500 exp and 1000 gold coins,\n" +
             "                         4. sacrifice 250 exp and 1500 gold coins ...\n\n" +
             "Once you have decided to raise one of your kis, type\n" +
             "   \"raise <ki> with <amount> gold coins\"\n" +
             "where <ki> is the ki, you want to raise and <amount> is the amount,\n" +
             "you want to offer in gold coins.\n" +
             "YOU HAVE TO USE THE PHRASE BY WORD TO AVOID MISUNDERSTANDINGS !!!\n" +
             "WRITE IN LOWER CASE !!!\n" );
             
      return( 1 );
   }

   return( 0 );
}

cost_it( arg )
{
   object nsoul;

   if ( TP->query_guild() != 8 ) {
      write( "Join the ninjas and then try it again.\n" );
      return( 1 );
   }
   
   nsoul = present( "ninjasoul", TP );
   if ( !nsoul ) {
      write( "YOU ARE BUGGY **shiver** please mail your guild-wizard !!!\n" );
      return( 1 );
   }

   write( "You have to sacrifice the following points of experience:\n\n" );

   if ( nsoul->query_throw_skill() < nsoul->query_max_throw_skill() )
      write( formula_appraise(nsoul->query_throw_skill()+1) +
             " experience points to raise your Throwing-ki.\n" );
   else {
      if ( nsoul->query_max_throw_skill() == 100 )
         write(MSG+" in Throwing.\n");
   }

   if ( nsoul->query_karate_skill() < nsoul->query_max_karate_skill() )
      write( formula_appraise(nsoul->query_karate_skill()+1) +
             " experience points to raise your Karate-ki.\n" );
   else {
      if ( nsoul->query_max_karate_skill() == 100 )
         write(MSG+" in Karate.\n");
   }

   if ( nsoul->query_parry_skill() < nsoul->query_max_parry_skill() )
      write( formula_appraise(nsoul->query_parry_skill()+1) +
             " experience points to raise your Yadomejutsu-ki.\n" );
   else {
      if ( nsoul->query_max_parry_skill() == 100 )
         write(MSG+" in Yadomejutsu.\n");
   }

   if ( nsoul->query_acc_skill() < nsoul->query_max_acc_skill() )
      write( formula_appraise(nsoul->query_acc_skill()+1) +
             " experience points to raise your Kenjutsu-ki.\n" );
   else {
      if ( nsoul->query_max_acc_skill() == 100 )
         write(MSG+" in Kenjutsu.\n");
   }
      
   if ( nsoul->query_thc_skill() < nsoul->query_max_thc_skill() )
      write( formula_appraise(nsoul->query_thc_skill()+1) +
             " experience points to raise your Ni-To-Kenjutsu-ki.\n" );
   else {
      if ( nsoul->query_max_thc_skill() == 100 )
         write(MSG+" in Ni-To-Kenjutsu.\n");
   }

   if ( nsoul->query_camou_skill() < nsoul->query_max_camou_skill() )
      write( formula_appraise(nsoul->query_camou_skill()+1) +
             " experience points to raise your Camouflage-ki.\n" );
   else {
      if ( nsoul->query_max_camou_skill() == 100 )
         write(MSG+" in Camouflage.\n");
   }

   if ( nsoul->query_assass_skill() < nsoul->query_max_assass_skill() )
      write( formula_appraise(nsoul->query_assass_skill()+1) +
             " experience points to raise your Assassination-ki.\n" );
   else {
      if ( nsoul->query_max_assass_skill() == 100 )
         write(MSG+" Assassination.\n");
   }

   return( 1 );
}

formula_appraise( v )
{
   return( (v*100 + v*v) / 2 );
}

raise_it( arg )
{
   int    exp, gold, levelExp, kiNo, maxSkill, actSkill;
   string ki;
   object nsoul;

   if ( !arg )
      return;

   if ( TP->query_guild() != 8 ) {
      write( "Join the ninjas and then try it again.\n" );
      return( 1 );
   }
   
   nsoul = present( "ninjasoul", TP );
   if ( !nsoul ) {
      write( "YOU ARE BUGGY **shiver** please mail your guild-wizard !!!\n" );
      return( 1 );
   }

   levelExp = GUILD_MASTER->query_exp(TP->query_guild(),TP->query_level());

   if ( sscanf( arg, "%s with %d gold coins", ki, gold ) == 2 ) {
      if ( TP->query_money() < gold ) {
         write( "Sorry, but you don't " + gold + " gold coins.\n" );
         return( 1 );
      }
      
      if ( ki == "throwing" || ki == "throwing-ki" ) {
         exp = formula_appraise(nsoul->query_throw_skill()+1) - gold/2;
         kiNo = THROW_SKILL;
         maxSkill = nsoul->query_max_throw_skill();
         actSkill = nsoul->query_throw_skill();
      }
      else if ( ki == "karate" || ki == "karate-ki" ) {
         exp = formula_appraise(nsoul->query_karate_skill()+1) - gold/2;
         kiNo = KARATE_SKILL;
         maxSkill = nsoul->query_max_karate_skill();
         actSkill = nsoul->query_karate_skill();
      }
      else if ( ki == "yadomejutsu" || ki == "yadomejutsu-ki" ) {
         exp = formula_appraise(nsoul->query_parry_skill()+1) - gold/2;
         kiNo = PARRY_SKILL;
         maxSkill = nsoul->query_max_parry_skill();
         actSkill = nsoul->query_parry_skill();
      }
      else if ( ki == "kenjutsu" || ki == "kenjutsu-ki" ) {
         exp = formula_appraise(nsoul->query_acc_skill()+1) - gold/2;
         kiNo = ACC_SKILL;
         maxSkill = nsoul->query_max_acc_skill();
         actSkill = nsoul->query_acc_skill();
      }
      else if ( ki == "ni-to-kenjutsu" || ki == "ni-to-kenjutsu-ki" ) {
         exp = formula_appraise(nsoul->query_thc_skill()+1) - gold/2;
         kiNo = THC_SKILL;
         maxSkill = nsoul->query_max_thc_skill();
         actSkill = nsoul->query_thc_skill();
      }
      else if ( ki == "camouflage" || ki == "camouflage-ki" ) {
         exp = formula_appraise(nsoul->query_camou_skill()+1) - gold/2;
         kiNo = CAMOU_SKILL;
         maxSkill = nsoul->query_max_camou_skill();
         actSkill = nsoul->query_camou_skill();
      }
      else if ( ki == "assassination" || ki == "assassination-ki" ) {
         exp = formula_appraise(nsoul->query_assass_skill()+1) - gold/2;
         kiNo = ASSASS_SKILL;
         maxSkill = nsoul->query_max_assass_skill();
         actSkill = nsoul->query_assass_skill();
      }
      else {
         write( "Sorry, I do not know anything about this ki.\n" );
         return( 1 );
      }
      
      if ( actSkill >= maxSkill ) {
  /*
         write( "Sorry, but you have already reached the upperbounder in\n" +
                "this kill.\n" );
  */
         write(MSG+" !"+"\n");
         return( 1 );
      }

      if ( exp <= 0 ) {
         exp = 0;
      }
      else {
         if ( (TP->query_exp() - exp) < levelExp ) {
            write( "Sorry, but you would get under your level-experience.\n" +
                   "You have to pay more gold coins.\n" );
            return( 1 );
         }
      }
      
      TP->add_money( -1 * gold );
      TP->add_exp( -1 * exp );
      
      nsoul->advance_skill_absolut( TP, kiNo, 1 );
      
      call_out("my_msg",2,"You feel raised.\n");
      say( TP->query_name() + " just raised a ki.\n" );
   }
   else
      write( "Please use the exact phrase given in \"help raise\".\n" );
      
   return( 1 );
}

 /* added whisky */
void my_msg(string arg)
{
  tell_object(this_player(),arg);
}
