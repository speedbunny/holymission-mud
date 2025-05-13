inherit "obj/treasure";
  
reset( arg )
{
   if ( arg )
      return;
   
   set_name( "bloodscroll" );
   set_alias( "scroll" );
   
   set_short( "A strange looking scroll" );
   set_long( "This scroll looks very strange and someone has\n" +
             "written something at it in nihonese letters.\n" );

   set_read( "You cannot understand this language.\n" );
}

read( str )
{
   if ( !id(str) )
      return;
  
   if ( this_player()->query_guild( 8 ) ) {
      write( "teg eht doolb fo eht owt tnereffid serutaerc ohw evil ni eht\n" +
             "onacluv fo eht dnalsi fo oze dna tup ti otni na gge neht uoy\n" +
             "evah a yrev llufrewop nopaew fi uoy dnatsrednu ot esu ti thgir\n" + 
             "dna ruoy ik si hgih hguone\n" );
      return( 1 );
   } 

   return( ::read( str ) );
}

drop( )
{   
   write( "As the scroll leaves your hands, it flames and burns to ashes !!!\n" );
   destruct( this_object() );

   return( 1 );
}
