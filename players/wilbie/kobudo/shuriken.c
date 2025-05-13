inherit "/players/patience/guild/nweap/genNinWeap";

reset(arg)
{
   ::reset(arg);
   if (arg)
      return;

   set_name( "shuriken" );
   set_alias( "platinum shuriken" );
   set_short( "A platinum shuriken" );
   set_long( "A shuriken is a ninja-weapon. It is designed for throwing.\n" +
             "The platinum shuriken looks extremely sharp.\n" );
   set_class( 1 );
   set_value( 1500 );
   set_weight( 3 );
   set_info( "ninja_weapon" );
   set_hit_func( this_object() );
   set_nin_dam( 3 );
   set_can_throw( );
   set_cap_name( "PLATINUM SHURIKEN" );
}

wield(str)
{
   if ( !str )
      return;
   
   if ( str == "shuriken" || str == "platinum shuriken" || id(str) ) {
      write( "You can throw a shuriken, but not wield it.\n" );
      return( 1 );
   }
}
