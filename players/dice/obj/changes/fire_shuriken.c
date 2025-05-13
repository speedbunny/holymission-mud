#define TP     (this_player())
#define COST   (TP->query_int() + TP->query_wis())/2
#define SR     "/players/patience/skill/skill_rout"

do_fireshuriken( arg )
{
   int hit_dam;
   object who;
   mixed  *skill;
   int    sLevel, sMaxLevel;

   hit_dam = ( COST / 2 ) + random( COST / 2 );
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

   if ( TP->query_sp() < COST ) {
      write( "You are too low in power to cast this spell.\n" );
      return( 1 );
   }

   if ( !who || !living( who ) || environment(who)!=environment(TP) ) {
     write("You cannot fireshuriken someone, who isn't here or who is dead!\n");
      return( 1 );
   }

   if ( random(sMaxLevel) > sLevel ) {
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
   who->hit_player( hit_dam );
   TP->restore_spell_points( -1 * COST );

   SR->advance_skill( TP, "fire_shuriken", 1, sMaxLevel );

   return( 1 );
}
