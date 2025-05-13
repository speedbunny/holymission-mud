inherit "obj/treasure";

string h1;

#define TP (this_player())

reset( arg )
{
   if ( arg )
      return;
      
   name = "meditator";
}


init( )
{
   ::init();
   
   add_action( "stop_meditate",  "wakeup" );
   add_action( "stop_meditate","wu");
   add_action( "start_meditate", "clean"  );
 
   add_action( "block", "", 1 );
}

block( arg )
{
   object soul;

   soul = present( "ninjasoul", TP );
   if ( !soul )
      return;
      
   if ( soul->query_meditate() ) {
      if ( query_verb() == "wakeup" || query_verb() == "dump" || query_verb() == "who" ||
           query_verb() == "hp" || query_verb() == "score" || query_verb() == "help" ||
           query_verb() == "i" || query_verb() == "say" || query_verb() == "ninja" ||
        query_verb()=="'" ||
           query_verb() == "tell" || query_verb() == "look" || query_verb() == "l" ||
          query_verb()=="stats"||query_verb()=="ninja/"||
           query_verb() == "save" || query_verb() == "alias" ||
           sscanf(query_verb(),"nshake%s",h1) == 1)
      {
         return( 0 );
      }
      write( "You can't do that while cleaning your spirit. <to stop type \"wakeup\">\n" );
      return( 1 );
   }

}

start_meditate( arg )
{
   object soul;
   
   if ( !arg || arg != "spirit" )
      return;
   
   soul = present( "ninjasoul", TP );

   if ( !soul ) {
      write( "You're no ninja !!!\n" );
      return( 1 );
   }

   if ( arg == "spirit" ) {
      if ( soul->query_meditate() )
         write( "You already cleaning your spirit.\n" );
      else {
         soul->set_meditate();
         if ( TP->query_religion() == "Amaterasu" )
            write( "You kneel down and become one with the void.\n" );
         else
            write( "You sit down in the lotus-position and begin to meditate about ZEN.\n" );
         say( TP->query_name() + " sits down in the lotus-position and begins to " +
              "meditate.\n" );
      }
   }
   
   return( 1 );
}

stop_meditate( arg )
{
   object soul;
   
   soul = present( "ninjasoul", TP );

   if ( !soul ) {
      write( "You're no ninja !!!\n" );
      return( 1 );
   }

   if ( soul->query_meditate() ) {
      soul->cancel_meditate();
      write( "You stop cleaning your spirit.\n" );
      say( TP->query_name() + " stops cleaning " + TP->query_possessive() + " spirit.\n" );
      destruct( this_object() );
   }
   else {
      write( "You aren't cleaning your spirit.\n" );
      destruct( this_object() );
   }
   return( 1 );
}
