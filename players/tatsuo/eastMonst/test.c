#define PPATH ("/players/tatsuo/forestMonst/")
inherit "obj/the_monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "gaki" );
   set_alias( "evil gaki" );
   set_level( 10 + random( 5 ) );
   set_size( 3 );
   set_short( "an evil test-gaki" );
   set_long( "A gaki is a ghost. It appears as an insubstantial or transparent shape,\n" +
             "with a normal upper torso, a belly bloated as with malnutrition, and a\n" +
             "lower torso trailing away to a misty, swirling column.\n" );

   recalc_boni();   
}
