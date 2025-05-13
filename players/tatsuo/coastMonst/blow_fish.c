inherit "/obj/monster";

#define FUGU  "/players/tatsuo/guild/nother/fugu"

object fugu;

reset(arg)
{
   ::reset(arg);
   
   if ( arg )
      return;

   set_name( "blowfish" );
   set_alias( "fish" );
   set_alt_name( "blow fish" );
 
   set_race("fish");
   set_has_gills();
   set_no_ears();
   set_al( 10 );
   
   set_short( "a blowfish" );
   set_long( "A blowfish, swimming near the coast.\n" );
   set_level( random(3) + 5 );
   
   fugu = clone_object( FUGU );
   transfer( fugu, this_object() );
}
