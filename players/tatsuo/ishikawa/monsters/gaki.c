#define PPATH ("/players/patience/forestMonst/")
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "gaki" );
   set_alias( "evil gaki" );
   set_level( 10 + random( 5 ) );
   set_size( 3 );
   set_short( "an evil gaki" );
   set_long( "A gaki is a ghost. It appears as an insubstantial or transparent shape,\n" +
             "with a normal upper torso, a belly bloated as with malnutrition, and a\n" +
             "lower torso trailing away to a misty, swirling column.\n" );
   
   set_chance( 60);
   set_spell_mess1( "The gaki tries a possession !!!" );
   set_spell_mess2( "The gaki tries to possess you !!!" );
   set_spell_dam( 20 );

   set_dead_ob( "/players/patience/eastMonst/monst_died" );
}
