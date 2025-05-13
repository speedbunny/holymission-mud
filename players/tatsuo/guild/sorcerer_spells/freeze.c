
/* last changes: whisky (didn't work ok) */

#define TP     (this_player())
/* cost lower because ninjas dont have that much spell-points */
#define COST   50 - (TP->query_wis()/4)
#define SR     "/players/patience/skill/skill_rout"

do_freeze( arg )
{
   if ( !TP ) return( 1 );

   TP->remove_skill( "freeze" );

   tell_object( TP,
      "------------------------------------------------------------------\n"+
      "The spell system has changed and this spell had been removed !!!!!\n"+
      "If you are a ninja, please check the guild-board, otherwise this\n"+
      "spell is lost for you !  No reimbursement \n"+
      "------------------------------------------------------------------\n" );

   return( 1 );

#if 0
   object who, obj;
   mixed  *skill;
   int    sLevel, sMaxLevel, formula;

   skill = TP->get_skill( "freeze" );

   if ( !skill && !sizeof( skill ) )
      return;

   sLevel = skill[0];         /* skillevel of player */
   sMaxLevel = skill[1];      /* maxskillevel  (100) */

   if ( !sLevel || !sMaxLevel )
      return;

   if ( arg )
      who = present( arg, environment( this_player() ) );
   else
      who = this_player()->query_attack();

   if ( TP->query_sp() < COST ) {
      write( "You are too low on power to freeze someone.\n" );
      return( 1 );
   }

   if ( !who || !living( who ) || environment(who)!=environment(TP) ) {
     write("You cannot freeze someone, " +
           "who isn't here or who is dead!\n");
      return( 1 );
   }

   if ( random( sMaxLevel ) > sLevel )   /* skillfailur */
   {
      write( "You fail to freeze " + who->query_name() + " ...\n");
      return( 1 ); 
   }

   write( "You turn your open hands towards " + who->query_name() + ".\n" +
          "The air between your hands begins to shine in a blue color and\n" +
          "you feel it getting colder. Suddenly a blue ice-globe shoots\n" +
          "at "+who->query_name()+", expodes and freezes your opponent !!!\n" );

   tell_object( who, TP->query_name() + " shoots an iceglobe at you and\n" +
                     "...FREEZES you !!!\n" );

   say( TP->query_name() + " shoots an ice-globe at "+
        who->query_name() + "\nand turns " + who->query_name() +
        " in a statue of ice !!!\n", who );

   formula = ( 20 + (8 * TP->query_wis()) - (2 * who->query_str()) ) / 4;

   if (formula < 8)
       formula = 2 + random(6);
   else if (formula > 16)
       formula = 8 + random(8);
   else 
       formula = random( formula );

   if (!who->query_npc())
       formula = 1 + formula/25;

   who->hold(TP, formula);

   if ( !present( "waskannom1", who ) ) {
      obj = clone_object( "/players/patience/guild/sorcerer_spells/wkn1" );
      move_object( obj, who );   
      obj->free_chance( formula ); /* wis depending */
   }

   TP->restore_spell_points( -1 * COST );

   if ( !TP->query_npc() )
      SR->advance_skill( TP, "freeze", 1, sMaxLevel );

   return( 1 );
#endif
}
