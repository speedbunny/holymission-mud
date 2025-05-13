#define TP             (this_player())

inherit "obj/weapon";

#include "/players/patience/guild/nweap/nweap_mess.h"

int    damage, throw;
int    hit_fact, monst_hit_fact, needed_lvl_fst, needed_lvl_sec,
       raise_block;
string cap_name, owner;

reset(arg)
{
   ::reset(arg);
   if (arg) return;

   set_info( "ninja_weapon" );
   set_hit_func( this_object() );
}

init( arg )
{
   ::init( arg );
}

long( )
{
   ::long();
   if ( owner )
      write( "This "+capitalize(query_name())+" belongs to "+
             capitalize(owner)+".\n" ); 
}

int wield( string arg )
{
   if ( !arg || !present( arg, this_player() ) ) return( 0 );

   if ( owner && owner != "" ) {
      if ( TP->query_real_name() != owner ) {
         write( "The "+query_name()+" refuses to be wielded by you !\n" );
         return( 1 );
      }
   }

   return( ::wield( arg ) );
}

_voiinskreiz( )
{
   int    critHit, hitChnc, hitChncPer;

   if (!objectp(wielded_by)) return 0;

   if ( TP->query_guild() == 8 ) {
      hitChnc = TP->get_skill_value("critical-hitting")
                + (TP->query_dex()+TP->query_wis())/4;
      hitChnc /= 10;
      if ( hitChnc > random( 100 ) ) {
         critHit = (TP->query_dex()+TP->query_str()) * hit_fact;
         critHit = (critHit / 2) + random(critHit / 2);

         write( "CRITICAL HIT with the " + query_name() + " !!!\n" );
         tell_object( TP->query_attack(), TP->query_name() +
             " makes a CRITICAL HIT " + "with the " + query_name() + " !!!\n" );
         say( TP->query_name() + " makes a CRITICAL HIT with the " +
                 query_name() + " !!!\n", TP->query_attack() );

         if (this_player()->query_immortal()) write("HIT: "+critHit+".\n");

         return( critHit );
      }
   }
}

int throw_function( object thrower, object target )
{
   string tn, pn, n;
   int    dam;

   if ( !throw || thrower->query_guild() != 8 ) return( 0 );

   tn = this_player()->query_name();
   pn = target->query_name();
   if ( cap_name ) n = cap_name;
   else            n = (string)query_name();

   write( "You shoot the "+n+" at "+pn+" !!!\n" );
   say( tn+" shoots "+n+" at "+pn+" !!!\n", target );
   tell_object( target, tn+" shoots "+n+" at you !!!\n" );

   dam = damage * ((thrower->query_str()+thrower->query_dex())/2);
   return( dam/2 + random(dam/2) );
}

query_nin_dam()          { return( damage ); }
set_nin_dam( i )         { damage = i; }

query_can_throw( )       { return( throw ); }
set_can_throw( )         { throw = 1; }

query_cap_name()         { return( cap_name ); }
set_cap_name( s )        { cap_name = s; }

query_hit_fact()         { return( hit_fact ); }
set_hit_fact( hf )       { hit_fact = hf; }

query_needed_lvl_fst()   { return( needed_lvl_fst ); }
set_needed_lvl_fst(e)    { needed_lvl_fst = e; }

query_needed_lvl_sec()   { return( needed_lvl_sec ); }
set_needed_lvl_sec(e)    { needed_lvl_sec = e; }

query_raise_block()      { return( raise_block ); }

query_owner()            { return( owner ); }
set_owner(o)             { owner = o; }
