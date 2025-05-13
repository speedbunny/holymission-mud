inherit "obj/weapon";

int    damage, throw;
string cap_name;

reset(arg)
{
   ::reset(arg);
   if (arg)
      return;

   set_name( "caltrops" );
   set_short( "some caltrops" );
   set_long( "Caltrops are a ninja-weapon. Caltrops are spikes with one spike always\n" +
             "at the top. They will be dropped by ninjas to make following harder.\n" );
   set_class( 1 );
   set_value( 50 );
   set_weight( 1 );
   set_info( "ninja_weapon" );
   set_nin_dam( 1 );
   set_can_throw( );
   set_cap_name( "CALTROPS" );
}

init( arg )
{
   ::init( arg );
}

get( str )
{
   write( "You think, that you could hurt yourself by picking them up,\n" +
          "so you decide to stop your attempt.\n" );
          
   return( 0 );
}

wield(str)
{
   if ( !str )
      return;
      
   if ( str == "aikuchi" ) {
      write( "You can drop or throw caltrops, but not wield them.\n" );
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
