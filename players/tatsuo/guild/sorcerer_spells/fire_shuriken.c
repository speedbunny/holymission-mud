#define TP     (this_player())
#define COST     (5 + TP->query_wis())
#define DAM      (5 + random(2 * TP->query_wis()))
#define SR     "/players/patience/skill/skill_rout"

int hit_dam;
object who;

do_fireshuriken( arg )
{
   if ( !TP ) return( 1 );

   TP->remove_skill( "fireshuriken" );

   tell_object( TP,
      "------------------------------------------------------------------\n"+
      "The spell system has changed and this spell had been removed !!!!!\n"+
      "If you are a ninja, please check the guild-board, otherwise this\n"+
      "spell is lost for you !  No reimbursement \n"+
      "------------------------------------------------------------------\n" );

   return( 1 );

#if 0
   mixed  *skill;
   int    sLevel, sMaxLevel;

   hit_dam = DAM; 
   skill = TP->get_skill( "fire_shuriken" );
   if ( !skill && !sizeof( skill ) )
      return;

   sLevel = skill[0];
   sMaxLevel = skill[1];
   if ( !sLevel || !sMaxLevel )
      return;

   if ( arg )
      who = present( arg, environment( this_player() ) );
   else
      who = this_player()->query_attack();

   if (TP->query_sp() < COST)
   {
      write( "You are too low in power to cast this spell.\n" );
      return( 1 );
   }

   if (present("heart_beat",TP))
   {
       write("You are just preparing your attack.\n");
       return 1;
   }
   if ( !who || !living( who ) || environment(who)!=environment(TP) ) {
     write("You cannot fireshuriken someone, who isn't here or who is dead!\n");
      return( 1 );
   }

       
   if ( random(sMaxLevel + 20) > sLevel) {  /* better fail chance */
      write( "You cannot concentrate enough to cast a fireshuriken ...\n");
      return( 1 ); 
   }

   write( "You point with your hand at " + who->query_name() + ".\n" +
          "Suddenly the air in your hand begins to glow and a bright\n" +
          "fireshuriken is shooting out of your hand at your opponent !!!\n" );
   tell_object( who, TP->query_name()+" shoots a fireshuriken at you !!!\n" );
   say( TP->query_name() + " shoots a fireshuriken at " + who->query_name() +
        ".\n", who );

   "/players/patience/guild/attack_mess"->CalcDam( 
          who,who->query_name(),hit_dam);
   if (who->query_race()=="troll") /* trolls suffer double fire dam */
   {
       hit_dam = hit_dam * 2;
       who->hit_player(hit_dam,5);
    }
   else
       who->hit_player(hit_dam,5);

   move_object(clone_object("/players/patience/guild/sorcerer_spells/heart_beat"), TP);
   TP->restore_spell_points( - COST );
   SR->advance_skill( TP, "fire_shuriken", 1, sMaxLevel );

   return( 1 );
#endif
}
 

