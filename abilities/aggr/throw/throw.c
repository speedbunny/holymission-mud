// ------------------------------------------------------------------------ 
// karate
// used at the ninjas
// patience
// ------------------------------------------------------------------------ 

inherit  "/abilities/ability";
#include "/spells/spell.h"

private string add_art( string s );

void reset( int tick )
{
   ::reset(tick);
   if ( tick ) return;

   set_name( "throw" );
   set_syntax( "throw <item> [at <opponent>]" );
   set_speed( NEXT_HB );
   set_guild_allowed( 8, 10 );
   set_kind( AGGRESSIVE );
   set_cost( 10 );
   set_auto_inc();
   set_player_help( 
     "With this ability you can throw items at your opponent. The damage you\n"+
     "will inflict depends upen the item you throw. Some items have special\n"+
     "effects when they are thrown onto your opponent." );
}

void display_prepare( object who )
{
   ;
}

void release( string arg, int act_skill, int max_skill )
{
   object oppo, item;
   int    dam;
   string oppo_name, tp_name, item_name, sitem, soppo;

   if ( !arg ) {
      write( "Throw what at whom ?\n" );
      return;
   }
   else if ( !(this_player()->query_hands_free()) ) {
      write( "You need a free hand to throw something.\n" );
      return;
   }
   else if ( sscanf( arg, "%s at %s", sitem, soppo ) != 2 ) {
      if ( arg ) {
         soppo = 0;
         sitem = arg;
      }
      else {
         write( "What do you want to throw at ?\n" );
         return;
      }
   }

   item = present( sitem, this_player() );
   if ( !item ) {
      write( "You frantically search around for "+add_art(sitem)+", but you "+
             "cannot find it !\n" );
      return;
   }

   oppo = check_target( soppo );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;

   oppo_name = funcall( call, oppo, "query_name" );
   tp_name = funcall( call, TP, "query_name" );
   item_name = item->query_name();

   if ( check_success( act_skill, max_skill ) ) {
      dam = item->throw_function( this_player(), oppo );
      if ( !dam ) {
         dam = item->query_weight()+TP->query_str();
         if ( item->query_weapon() ) dam += item->weapon_class();
         dam = dam/2 + random(dam/2);
         write( "You shoot the "+item_name+" at "+oppo_name+" !\n" );
         say( tp_name+" shoots "+add_art(item_name)+" at "+oppo_name+" !\n",
              oppo );
         tell_object( oppo,tp_name+" shoots "+add_art(item_name)+" at you !\n");
      }
      if ( !oppo ) {
         log_file( "ILLEGAL", "ability: 'throw', TP: "+tp_name+", opponent: "+
                   oppo_name+", item: "+item_name+"\nINSTANT KILL (in throw_"+
                   "function) !!\n" );
      }
      if ( item ) {
         transfer( item, oppo );
         // maybe move_blocked, it not ok
      }
      dam = oppo->hit_by_ability( dam, 0 );
      TP->attack_object( oppo );
   }
   else {
      write( "The "+item_name+" just flies an inch over the head of "+
             oppo_name+".\n" );
      say( tp_name+" shoots "+add_art(item_name)+" at "+oppo_name+", but "+
           "missed.\n", oppo );
      tell_object( oppo, tp_name+" shoots "+add_art(item_name)+" at you, but "+
                   "missed you.\n" );
      oppo->attacked_by( TP );
   }
}

private string add_art( string s )
{
   switch( s[0] ) {
      case 'a': case 'e': case 'i': case 'o': case 'u':
      case 'A': case 'E': case 'I': case 'O': case 'U':
         return( "an "+s );
   }
   return( "a "+s );
}
