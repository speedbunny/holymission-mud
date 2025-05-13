inherit "obj/weapon";

int    damage, throw;
string cap_name;

reset(arg)
{
   ::reset(arg);
   if (arg)
      return;

   set_name( "aikuchi" );
   set_short( "An aikuchi" );
   set_long( "An aikuchi is a ninja-weapon. It is a throwing-dagger with no hilt.\n" +
             "The aikuchi looks sharp.\n" );
   set_class( 1 );
   set_value( 100 );
   set_weight( 1 );
   set_info( "ninja_weapon" );
   set_hit_func( this_object() );
   set_nin_dam( 2 );
   set_can_throw( );
   set_cap_name( "AIKUCHI" );
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
      
   if ( str == "aikuchi" ) {
      write( "You can throw an aikuchi, but not wield it.\n" );
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
