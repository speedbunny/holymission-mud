#define PPATH ("/players/tatsuo/forestMonst/")
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "gaki" );
   set_alias( "evil gaki" );
   set_level( 10 + random( 5 ) );
   set_ep( 500 );
   set_size( 3 );
   set_short( "an evil gaki" );
   set_long( "A gaki is a ghost. It appears as an insubstantial or transparent shape,\n" +
             "with a normal upper torso, a belly bloated as with malnutrition, and a\n" +
             "lower torso trailing away to a misty, swirling column.\n" );
   
   set_chance( 20 );
   set_spell_mess1( "The gaki tries a possession !!!" );
   set_spell_mess2( "The gaki tries to possess you !!!" );
   set_spell_dam( 20 );

   set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );
}
