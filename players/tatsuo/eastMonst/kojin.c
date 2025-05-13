inherit "obj/monster";

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

  set_level(40 +random (20) );

   set_name( "kojin" );
   set_short( "A kojin" );
   set_long( "This humanoid has the head of a shark.\n" +
             "It serves the Dragon-King.\n" );
 
   set_chance( 25 );
   set_spell_dam ( 75 + random(10) );
   set_spell_mess1( "The kojin bites around !!!" );
   set_spell_mess2( "The kojin BITES you with its sharp teeth !!!" );

   if (random(2) ) {
      move_object(clone_object("/players/tatsuo/guild/nweap/sai"),
                  this_object() );
      command( "powerup" );
   }

   set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );

   set_aggressive( 1 );
}

