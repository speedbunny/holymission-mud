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
  
   if ( throw ) 
      add_action( "_throw", "throw" );
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
   object ns;
   int    critHit, hitChnc, hitChncPer;

   if (!objectp(wielded_by)) return 0;

   ns = present( "ninja_soul", wielded_by );
   if ( ns ) {
      hitChnc = ns->query_accuracy() + (TP->query_dex()+TP->query_wis())/4;
      hitChnc /= 10;
      if ( hitChnc > random( 100 ) ) {
         critHit = (TP->query_dex()+TP->query_str()) * hit_fact;
         critHit = (critHit / 2) + random(critHit / 2);

         write( "CRITICAL HIT with the " + query_name() + " !!!\n" );
         tell_object( TP->query_attack(), TP->query_name() +
             " makes a CRITICAL HIT " + "with the " + query_name() + " !!!\n" );
         say( TP->query_name() + " makes a CRITICAL HIT with the " +
                 query_name() + " !!!\n", TP->query_attack() );

         if ( ns->query_accuracy() <= raise_block ) ns->weapon_hit( 1 );
         if (this_player()->query_immortal()) write("HIT: "+critHit+".\n");

         return( critHit );
      }
      if ( ns->query_accuracy() <= raise_block )
         ns->weapon_hit( 0 );
   }
   else if ( TP->query_npc() && TP->query_ninja() ) {                /* for monsters */
      hitChnc = TP->query_accuracy();
      if ( hitChnc > random( 100 ) ) {
         critHit = TP->query_level() * monst_hit_fact;
         if ( critHit > (this_player()->query_attack())->query_ac() ) {
            write( "CRITICAL HIT with the " + query_name() + " !!!\n" );
            tell_object( TP->query_attack(), TP->query_name() + " makes a CRITICAL HIT " +
                         "with the " + query_name() + " !!!\n" );
            say( TP->query_name() + " makes a CRITICAL HIT with the " + query_name() +
                 " !!!\n", TP->query_attack() );
         }
         return( critHit );
      }
   }
}

_throw( str )
{
   string what, swho;
   object who;
   
   if ( !str )
      return;
      
   if ( (!present("ninja_soul", this_player())) ) {             /* ninja ?   */
      write( "Sorry, but only ninjas can do that.\n" );
      return( 1 );
   }
   else
      return( 0 );                        /* at ninjas -> let the soul do it*/

   return( 1 );
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
