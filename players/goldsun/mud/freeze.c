#define TP     (this_player())
#define COST   (TP->query_wis())*3

do_spell( arg, skill )
{
   object who, obj;

   if ( !skill[0] )
      return;

   if ( arg )
      who = present( arg, environment( this_player() ) );
   else
      who = this_player()->query_attack();

   if ( TP->query_sp() < COST ) {
      write( "You are too low on power to freeze someone.\n" );
      return( 1 );
   }

   if ( !who || !living( who ) || environment(who)!=environment(TP) ) {
     write("You cannot freeze someone, " +
           "who isn't here or who is dead!\n");
      return( 1 );
   }
   else if ( !(who->query_npc()) && !(interactive(who)) ) {
      write( "You cannot freeze a linkdead player.\n" );
      return( 1 );
   }

   if ( random( skill[1] ) > skill[0] ) {
      write( "You fail to freeze " + who->query_name() + " ...\n");
      return( 1 ); 
   }

   write( "You turn your open hands towards " + who->query_name() + ".\n" +
          "The air between your hands begins to shine in a blue color and\n" +
          "you feel it getting colder. Suddenly a blue ice-globe shoots\n" +
          "at "+who->query_name()+", expodes and freezes your opponent !!!\n" );
   tell_object( who, TP->query_name() + " shoots an iceglobe at you and\n" +
                     "...FREEZES you !!!\n" );
   say( TP->query_name() + " shoots an ice-globe at "+
        who->query_name() + "\nand turns " + who->query_name() +
        " in a statue of ice !!!\n", who );

   if ( !present( "waskannom1", who ) ) {
      obj = clone_object( "/players/patience/guild/sorcerer_spells/wkn1" );
      move_object( obj, who );   
      obj->free_chance( skill[0] * 2 / 3);
   }

   TP->restore_spell_points( -1 * COST );

   return( 1 );
}

query_name()
{
   return( "Freeze" );
}

query_command()
{
   return( "freeze <who>" );
}

cast_info()
{
   return(
      ({ "start to concentrate on the freeze." }) +
      ({ "starts to concentrate." }) + ({ 0 })
   );
}
