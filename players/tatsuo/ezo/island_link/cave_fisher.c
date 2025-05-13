inherit "obj/monster";

#define TO (this_object())

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "cave fisher" );
   set_alt_name( "fisher" );
   set_alias( "cave" );
   set_level( 15 + random( 5 ) );
   set_size( 4 );
   set_short( "A cave fisher" );
   set_long( "This monster looks like a very huge antbear. Its fangs are\n"+
             "clasping, frantically trying to slice you apart !!!\n" );
   
   set_chance( 20 );
   set_spell_mess1( "The cave fisher bites !" );
   set_spell_mess2( "You feel numb for a moment as the cave fisher's fangs close around your neck,\nbut fortunately the effect fades." );
   set_spell_dam( 30 );

   set_aggressive(1);
   transfer( clone_object("/players/tatsuo/ezo/island_link/p_parch"), TO );
}

init()
{
   ::init();

   add_action( "west", "west" );
   add_action( "west", "w" );
}

west( arg )
{
   if ( this_player() == this_object()->query_attack() ) {
      write( "You are entangled by the cave fisher !!!\n" );
      return( 1 );
   }
}
