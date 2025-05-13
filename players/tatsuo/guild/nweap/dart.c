#include "/players/tatsuo/guild/ndef.h"
/* 310793: Galadriel: changed a load of typos */
inherit "obj/weapon";

#define THROW_SKILL  (1)
#define NINJA_POISON "/players/tatsuo/guild/nother/ninja_poison"

int    damage, throw, poison;
string cap_name;

reset(arg)
{
   ::reset(arg);
   if (arg)
      return;

   set_name( "dart" );
   set_alias( "poison-dart" );
   set_alt_name( "poison dart" );
   set_short( "A dart" );
   set_long( "This is a quite normal looking dart. It is made of wolfram and\n" +
             "it has blue feathers at the end. It fits very good in your hand.\n" );
   set_class( 1 );
   set_value( 600 );
   set_weight( 2 );
   set_info( "ninja_weapon" );
   set_hit_func( this_object() );
   set_nin_dam( 3 );
   set_can_throw( );
   set_cap_name( "DART" );
}

init( arg )
{
   ::init( arg );
   
   add_action( "_throw", "throw" );
}

wield(str)
{
   if ( !str )
      return;
   
   if ( str == "dart" || str == "poison-dart" ) {
      write( "You can throw a dart, but not wield it.\n" );
      return( 1 );
   }
}

_throw( str )
{
   string what, swho;
   object who;
   
   if ( !str )
      return;
      
   if ( (!present("ninja_soul", this_player())) ) {                  /* ninja ?   */
      write( "Sorry, but only ninjas can do that.\n" );
      return( 1 );
   }
   else
      return( 0 );                                 /* at ninjas -> let the soul do it*/

   return( 1 );
}

query_nin_dam()
{
   return( damage );
}

set_nin_dam( i )
{
   damage = i;
}

query_can_throw( )
{
   return( throw );
}

set_can_throw( )
{
   throw = 1;
}

query_cap_name()
{
   return( cap_name );
}

set_cap_name( s )
{
   cap_name = s;
}

short()
{
   if ( poison > 0 ) {
      if ( poison < 101 ) 
         return( ::short() + " (a bit poisoned)" );
      else if ( poison < 201 )
         return( ::short() + " (barely poisoned)" );
      else if ( poison < 301 )
         return( ::short() + " (poisoned) " );
      else if ( poison < 401 )
         return( ::short() + " (very poisoned)" );

      return( ::short() + " (strongly poisoned)" );
   }
   
   return( ::short() );
}

add_dart_poison( v )
{
   poison += v;
   if ( poison < 0 )
      poison = 0;
   if ( poison > 500 )
      poison = 500;
}

query_npowder_throw( )
{
   return( poison );
}

throw_powder( arg )
{
   object who, p, nsoul;
   int    i;

   who = present( arg, environment(this_player()) );
   if ( !who ) {
      write( "Sorry, but there is no opponent present !\n" );
      return( 1 );
   }
   nsoul = present( "ninjasoul", this_player() );
   if ( !nsoul ) {
      write( "You are no ninja, you cannot use this dart !!!\n" );
      return( 1 );
   }

  if( random(100) < THROWSKILL) {
      if ( transfer( this_object(), who ) )
         move_object( this_object(), who );

      tell_object( this_player(),
              "You THROW a poison-dart at your opponent and POISON it !!!\n" );
      tell_object( who,
              TP->query_name() +
              " throws a poison-dart at you and poisons you !!!\n" );
      say( TP->query_name() + " throws a poison-dart at " + 
              who->query_name() + " and poisons it !!!\n",
              who );
              
     who->hit_player(poison/2, 9);
     if (who && living(who))
       who->add_poison(poison/10);
      poison = 0;
              
      who->attacked_by( TP );
   }
   else
     write("You cannot get a good aim.\n");

   return( 1 );
}
