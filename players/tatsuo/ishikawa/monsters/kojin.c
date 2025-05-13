inherit "obj/monster";

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   set_level( 20 + random(10) );

   set_name( "kojin" );
   set_short( "A kojin" );
   set_long( "This humanoid has the head of a shark.\n" +
             "It serves the Dragon-King.\n" );
 
   set_chance( 25 );
   set_spell_dam( 25 + random( 50 ) );
   set_spell_mess1( "The kojin bites around !!!" );
   set_spell_mess2( "The kojin BITES you with its sharp teeth !!!" );

   if (random(2) ) {
      move_object(clone_object("/players/patience/guild/nweap/sai"),
                  this_object() );
      command( "powerup" );
   }

   set_dead_ob( "/players/patience/eastMonst/monst_died" );

   set_aggressive( 1 );
}

