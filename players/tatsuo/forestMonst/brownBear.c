#define PPATH ("/players/tatsuo/forestMonst/")
inherit "obj/monster";

reset(arg)
{
   object fur;

   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "bear" );
   set_alias( "brown bear" );
   set_level( 8 + random( 5 ) );
   set_size( 4 );
   set_short( "a brown bear" );
   set_long( "A brown bear. It doesn't seem to be interested in combat.\n" );
   
   set_chance( 15 );
   set_spell_mess1( "The bear makes a hit with his paw !!!" );
   set_spell_mess2( "The bear hits you with its paw !!!" );
   set_spell_dam( 30 );

   fur = clone_object( PPATH + "brownBear_fur" );
   if ( transfer( fur, this_object() ) )
      destruct( fur );
   else
      command( "wear fur" );

   set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );
}
