inherit "/players/tatsuo/GenObj/mymonster";

#include "/players/tatsuo/guild/skill_id.h"

#define TP    (this_player())

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   set_name( "hudriwudri" );
   set_alias( "hudriwudri-san" );
   set_short( "Hudriwudri-san" );
   set_long( "This is Hudriwudri-san, the skill-master of Ezo.\n" +
             "He is sitting on a strong branch, nibbling on a leaf.\n" +
             "He looks very wise, maybe he can give you some answers,\n" +
             "if you ask!?\n" );

   set_level( 50 );
   set_gender( 1 );
   set_race( "human" );

   set_no_fear();
   set_parry( 30 );
   set_n_ac( 0 );
   set_ninja();
   set_accuracy( 25 );
   move_object( clone_object( "/players/tatsuo/guild/nweap/sai" ),
                this_object() );
   command( "wield sai" );
}

init( arg )
{
   ::init( arg );

   add_action( "do_ask", "ask" );
}

do_ask( arg )
{
   string what, msg, quests, msg1;
   int    i;
   object nsoul;

   if ( !arg )
      return;

   if ( sscanf( arg, "hudriwudri-san about %s", what ) != 1 &&
        arg != "hudriwudri-san for improvement" ) {
      write( "You can ask Hudriwudri-san about kis or for improvement.\n" );
      return( 1 );
   }

   if ( arg == "hudriwudri-san for improvement" ) {
      quests = explode( TP->query_quests(), "#" );
      nsoul = present( "ninja_soul", TP );
      msg = "";

      for ( i = 0; i < sizeof( quests ); i++ ) {
         if ( quests[i] == "orb_quest" ) {
            if ( nsoul->advance_skill_max( TP, THROW_SKILL, 90, 0 ) )
               msg += "throwing-ki\n";
            if ( nsoul->advance_skill_max( TP, PARRY_SKILL, 80, 0 ) )
               msg += "yadomejutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, KARATE_SKILL, 100, 0 ) )
               msg += "karate-ki\n";
            if ( nsoul->advance_skill_max( TP, ACC_SKILL, 80, 0 ) )
               msg += "kenjutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, THC_SKILL, 90, 0 ) )
               msg += "ni-to-kenjutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, CAMOU_SKILL, 80, 0 ) )
               msg += "camouflage-ki\n";
            if ( nsoul->advance_skill_max( TP, ASSASS_SKILL, 80, 0 ) )
               msg += "assassination-ki\n";
         }
         else if ( quests[i] == "starburst_quest" ) {
            if ( nsoul->advance_skill_max( TP, THROW_SKILL, 80, 0 ) )
               msg += "throwing-ki\n";
            if ( nsoul->advance_skill_max( TP, PARRY_SKILL, 100, 0 ) )
               msg += "yadomejutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, KARATE_SKILL, 80, 0 ) )
               msg += "karate-ki\n";
            if ( nsoul->advance_skill_max( TP, ACC_SKILL, 90, 0 ) )
               msg += "kenjutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, THC_SKILL, 100, 0 ) )
               msg += "ni-to-kenjutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, CAMOU_SKILL, 80, 0 ) )
               msg += "camouflage-ki\n";
            if ( nsoul->advance_skill_max( TP, ASSASS_SKILL, 80, 0 ) )
               msg += "assassination-ki\n";
         }
         else if ( quests[i] == "vampirequest" ) {
            if ( nsoul->advance_skill_max( TP, THROW_SKILL, 80, 0 ) )
               msg += "throwing-ki\n";
            if ( nsoul->advance_skill_max( TP, PARRY_SKILL, 80, 0 ) )
               msg += "yadomejutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, KARATE_SKILL, 80, 0 ) )
               msg += "karate-ki\n";
            if ( nsoul->advance_skill_max( TP, ACC_SKILL, 80, 0 ) )
               msg += "kenjutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, THC_SKILL, 80, 0 ) )
               msg += "ni-to-kenjutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, CAMOU_SKILL, 100, 0 ) )
               msg += "camouflage-ki\n";
            if ( nsoul->advance_skill_max( TP, ASSASS_SKILL, 100, 0 ) )
               msg += "assassination-ki\n";
         }
         else if ( quests[i] == "hellfire" ) {
            if ( nsoul->advance_skill_max( TP, THROW_SKILL, 100, 0 ) )
               msg += "throwing-ki\n";
            if ( nsoul->advance_skill_max( TP, PARRY_SKILL, 80, 0 ) )
               msg += "yadomejutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, KARATE_SKILL, 80, 0 ) )
               msg += "karate-ki\n";
            if ( nsoul->advance_skill_max( TP, ACC_SKILL, 100, 0 ) )
               msg += "kenjutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, THC_SKILL, 80, 0 ) )
               msg += "ni-to-kenjutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, CAMOU_SKILL, 80, 0 ) )
               msg += "camouflage-ki\n";
            if ( nsoul->advance_skill_max( TP, ASSASS_SKILL, 80, 0 ) )
               msg += "assassination-ki\n";
         }
         else if ( quests[i] == "smilequest" ) {
            if ( nsoul->advance_skill_max( TP, THROW_SKILL, 80, 0 ) )
               msg += "throwing-ki\n";
         }
         else if ( quests[i] == "angmar" ) {
            if ( nsoul->advance_skill_max( TP, THROW_SKILL, 65, 0 ) )
               msg += "throwing-ki\n";
            if ( nsoul->advance_skill_max( TP, KARATE_SKILL, 65, 0 ) )
               msg += "karate-ki\n";
         }
         else if ( quests[i] == "witchquest" ) {
            if ( nsoul->advance_skill_max( TP, THROW_SKILL, 50, 0 ) )
               msg += "throwing-ki\n";
         }
         else if ( quests[i] == "free_solar" ) {
            if ( nsoul->advance_skill_max( TP, PARRY_SKILL, 90, 0 ) )
               msg += "yadomejutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, ACC_SKILL, 80, 0 ) )
               msg += "kenjutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, THC_SKILL, 80, 0 ) )
               msg += "ni-to-kenjutsu-ki\n";
         }
         else if ( quests[i] == "ratsquest" ) {
            if ( nsoul->advance_skill_max( TP, THROW_SKILL, 35, 0 ) )
               msg += "throwing-ki\n";
            if ( nsoul->advance_skill_max( TP, PARRY_SKILL, 70, 0 ) )
               msg += "yadomejutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, KARATE_SKILL, 40, 0 ) )
               msg += "karate-ki\n";
         }
         else if ( quests[i] == "cerberos" ) {
            if ( nsoul->advance_skill_max( TP, PARRY_SKILL, 60, 0 ) )
               msg += "yadomejutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, KARATE_SKILL, 60, 0 ) )
               msg += "karate-ki\n";
            if ( nsoul->advance_skill_max( TP, ASSASS_SKILL, 30, 0 ) )
               msg += "assassination-ki\n";
         }
         else if ( quests[i] == "secret_police" ) {
            if ( nsoul->advance_skill_max( TP, CAMOU_SKILL, 80, 0 ) )
               msg += "camouflage-ki\n";
         }
         else if ( quests[i] == "padrone" ) {
            if ( nsoul->advance_skill_max( TP, PARRY_SKILL, 40, 0 ) )
               msg += "yadomejutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, CAMOU_SKILL, 40, 0 ) )
               msg += "camouflage-ki\n";
            if ( nsoul->advance_skill_max( TP, ASSASS_SKILL, 50, 0 ) )
               msg += "assassination-ki\n";
         }
         else if ( quests[i] == "dragon_slayer" ) {
            if ( nsoul->advance_skill_max( TP, ACC_SKILL, 60, 0 ) )
               msg += "kenjutsu-ki\n";
         }
         else if ( quests[i] == "lion" ) {
            if ( nsoul->advance_skill_max( TP, ACC_SKILL, 50, 0 ) )
               msg += "kenjutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, CAMOU_SKILL, 60, 0 ) )
               msg += "camouflage-ki\n";
         }
         else if ( quests[i] == "troll_slayer" ) {
            if ( nsoul->advance_skill_max( TP, THC_SKILL, 60, 0 ) )
               msg += "ni-to-kenjutsu-ki\n";
            if ( nsoul->advance_skill_max( TP, ASSASS_SKILL, 70, 0 ) )
               msg += "assassination-ki\n";
         }
         else if ( quests[i] == "goblin_quest" ) {
            if ( nsoul->advance_skill_max( TP, THC_SKILL, 40, 0 ) )
               msg += "ni-to-kenjutsu-ki\n";
         }
      }

      if ( msg && strlen( msg ) ) 
         write( "Hudriwudri-san says:\n" +
                "I have improved your learning range at the following ki(s):\n"+
                msg );
      else
         write( "Hudriwudri-san says: Sorry, but you ain't in a state,\n" +
                "that i can improve your learning-range.\n" );

      return( 1 );
   }

   if ( what ) {
      msg1 = "Hudriwudri-san says: You want to know, how to improve the\n" +
             "learning range of this ki. Well, let me give you this hint.\n" +
             "\nHudriwudri-san says: ";
      msg = "";
      if ( what == "throwing-ki" || what == "throwing" ) {
         switch( random( 4 ) ) {
            case 0: msg += "I think, the witch-quest would help you.\n";
                    break;
            case 1: msg += "Have you heard anything about a man named Yorel?\n";                    break;
            case 2: msg += "Oh, there is a very sad little girl.\n";
                    break;
            case 3: msg += "Ever heard about the treasure in Angmar?\n"; 
            default: break;
         }
      }
      else if ( what == "yadomejutsu" || what == "yadomejutsu-ki" ) {
         switch( random( 3 ) ) {
            case 0: msg += "Cerberos!\n";
                    break;
            case 1: msg += "Give thee one, called Solar, his freedom back.\n";
                    break;
            case 2: msg += "There is a castle, walking around somewhere.\n";
                    break;
            case 3: msg += "How long have Yorel to suffer from the rats.\n";
            default: break;
         }
      }
      else if ( what == "karate" || what == "karate-ki" ) {
         switch( random( 3 ) ) {
            case 0: msg += "I don't like hellhounds!\n";
                    break;
            case 1: msg += "A rat is nibbling on your toe, take care!\n";
                    break;
            case 2: msg += "Get the treasure, hidden in Angmar.\n";
            default: break;
         }
      }
      else if ( what == "kenjutsu" || what == "kenjutsu-ki" ) {
         switch( random( 3 ) ) {
            case 0: msg += "Slay the right dragon!\n";
                    break;
            case 1: msg += "Give thee one, called Solar, back his freedom.\n";
                    break;
            case 2: msg += "Go for the head!\n";
            default: break;
         }
      }
      else if ( what == "ni-to-kenjutsu" || what == "ni-to-kenjutsu-ki" ) {
         switch( random( 3 ) ) {
            case 0: msg += "Goblins, goblins, everywhere!\n";
                    break;
            case 1: msg += "The king of the trolls is a really bad creep.\n";
                    break;
            case 2: msg += "Like to join the police?\n";
            default: break;
         }
      }
      else if ( what == "camouflage" || what == "camouflage-ki" ) {
         switch( random( 3 ) ) {
            case 0: msg += "I have heard something about lions, I guess.\n";
                    break;
            case 1: msg += "I'm walking, yes indeed, I'm walking.\n";
                    break;
            case 2: msg += "Talk to the guys, who fight the crime.\n";
            default: break;
         }
      }
      else if ( what == "assassination" || what == "assassination-ki" ) {
         switch( random( 3 ) ) {
            case 0: msg += "Mess with the trolls, these stinking bastards.\n";
                    break;
            case 1: msg += "Isn't Lady Marion a honorable person?\n";
                    break;
            case 2: msg += "I hate pirates!\n";
            default: break;
         }
      }

      if ( msg && strlen( msg ) )
         write( msg1 + msg );
      else
         write( "Hudriwudri-san says: Sorry, but I'm only comfort with ninja-kis.\n" );
   }
   else {
      write( "Hudriwudri-san says: Sorry, but i don't know anything about this ki.\n" );
   }

   say( TP->query_name() + " asks Hudriwudri-san about a ki.\n", TP );

   return( 1 );
}
