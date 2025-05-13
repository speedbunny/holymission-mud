#include "/spells/spell.h"
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "shadow" );
   set_level( 5 + random( 2 ) );
   set_size( 3 );
   set_race( "undead" );
   set_short( "a shadow" );
   set_long( "A shadowy, undead creature.\n" );
   set_aggressive(1);
   set_whimpy( 40 );
   set_n_wc( 15 );
}

query_invis()
{
   if ( query_attack() )
      return( 0 );
   return( 29 );
}

int attack( object weapon, int whichHand )
{
   object att, shad;

   att = query_attack();
   if ( att ) {
      tell_object( att, "The shadow touches you, " );
      if ( att->do_save(AGGRESSIVE,TOUCH,0,0,this_object()) == SAVE_FAILED ) {
         tell_object( att, "and you feel weaker !!!\n" );
         shad = clone_object( "/shadows/str_drain_shad" );
         shad->start_shadow( att, 20+random(10), 1 );
      }
      else
         tell_object( att, "but you resist the pain !\n" );
   }

   return( ::attack( weapon, whichHand ) );
}

int hit_player( int dam, int kind, mixed elem )
{
   object att;

   if ( kind != 0 )
      return( ::hit_player( dam, kind, elem ) );

   att = query_attack();
   if ( !att )
      return( ::hit_player( dam, kind, elem ) );

   if ( !(att->query_wielded_weapon(0)) && !(att->query_wielded_weapon(1)) )
      return( 0 );

   return( ::hit_player( dam, kind, elem ) );
}
