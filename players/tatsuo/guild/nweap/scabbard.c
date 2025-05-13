#define TP      (this_player())

object cont;

id( str )
{
   return( str = "scabbard" );
}

short()
{
   return( "A scabbard" );
}

long()
{
   write( "This is a sword-scabbard. This scabbard is specially made for\n" +
          "shutos and katanas.\n" );
   if ( cont )
      write( "   It contains a " + cont->query_name() + ".\n" );
}

query_weight( ) { return(10); }

init()
{
   add_action( "do_draw", "draw" );
   add_action( "do_put", "put" );
}

do_put( arg )
{
object what;

   if ( arg == "shuto in scabbard" )
      what = present( "shuto", this_player() );
   else if ( arg == "katana in scabbard" ) 
      what = present( "katana", this_player() );
   else 
      return;

   if ( !what )
      write( "You only can put weapons in the scabbard, you have.\n" );
   else if ( cont )
      write( "The scabbard already contains a " + cont->query_name()+".\n");
   else {
      cont = what;
      transfer( cont, this_object() );
   }
  
   return( 1 );
}

do_draw( arg )
{
   if ( id( arg ) ) {
      write( "You draw the " + cont->query_name() + ".\n" );
      say( TP->query_name() + " draws a " + cont->quey_name()+".\n",0,TP);
      transfer( cont, environment(this_object()) );
      cont = 0;
   }
}

drop()
{
   if ( cont ) {
      transfer( cont, environment(this_object()) );
      write( "You you drop the scabbard, the sword move in your hand.\n" );
   }
}

get()
{
   return( 1 ); 
}
