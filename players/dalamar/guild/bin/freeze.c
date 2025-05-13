
#include "/players/tatsuo/guild/ndef.h"


main( arg )
{
   


   object who, obj;
   mixed  *skill;
   int    sLevel, sMaxLevel, formula;

  if(environment(TP)->query_property("no_fight")){ 
  return printf("This is not a place of violence.\n"),1; }
 
if(!arg && !TP->query_attack()) return printf("Freeze whom?\n"),1;

  if(TPL < 28 ) return printf("You cannot cast such powerful shadowmagic.\n"),1;
   
   if ( arg )
      who = present( arg, environment( this_player() ) );
   else
      who = this_player()->query_attack();
   if(!who) return printf("Not here to freeze.\n"),1;
  
 if(who->query_interactive()) return printf("No freezing players.\n"),1;

   if ( TP->query_sp() < FREEZE_COST ) {
      write( "You are too low on power to freeze someone.\n" );
      return( 1 );
   }
 

   if ( !who || !living( who ) || environment(who)!=environment(TP) ) {
     write("You cannot freeze someone, " +
           "who isn't here or who is dead!\n");
      return( 1 );
   }

   if ( random( 120 ) > SHADOWMAGIC )   /* skillfailur */
   {
      write( "You fail to freeze " + who->query_name() + " ...\n");
      return( 1 ); 
   }

   write( "You turn your open hands towards " + who->query_name() + ".\n" +
          "The air between your hands begins to shine in a blue color and\n" +
          "you feel it getting colder. Suddenly a blue ice-globe shoots\n" +
           "at "+who->query_name()+", explodes and freezes your opponent !!!\n" );

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
      obj = clone_object( "/players/tatsuo/guild/sorcerer_spells/wkn1" );
      move_object( obj, who );   
      obj->free_chance( formula ); /* wis depending */
   }

   TP->restore_spell_points( -1 * FREEZE_COST );

   
  return 1;
}

