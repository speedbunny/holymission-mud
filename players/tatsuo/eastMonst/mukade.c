#define PPATH ("/players/tatsuo/eastMonst/")
inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "mukade" );
   set_alias( "giant mukade" );
   set_level( 18 );
   set_ep( 1000 );
   set_size( 4 );
   set_short( "a giant mukade" );
   set_long( "A mukade is a giant centipede-like creature with great glowing eyes.\n" +
             "This beast has 20 legs on each side and looks very aggressive.\n" );

   set_no_ears();
   set_chance( 15 );
   set_spell_mess1( "The giant mukade makes a bite with its giant fangs !!!" );
   set_spell_mess2( "The giant mukade bites you with its fangs !!!" );
   set_spell_dam( 50 );

   set_aggressive( 1 );

   transfer( clone_object( PPATH + "mukade_blood" ), this_object() );

   set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );
}
