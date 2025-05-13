inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "ghast" );
   set_level( 15 + random( 5 ) );
   set_size( 3 );
   set_short( "an evil ghast" );
   set_long( "You shiver at the sight of the rotten corpse of this ghast.\n"+
             "One are is hanging limb at its side, one cheek is torn off and\n"+
           "reveals rotten teeth and black, bloody eyeholes staring at you!\n");
   
   set_chance( 15 );
   set_spell_mess1( "The gaki emits such a stench, it makes you puke!" );
   set_spell_mess2( "The gaki emits such a stench, it makes you puke !" );
   set_spell_dam( 10+random(30) );

   set_aggressive(1);
}
