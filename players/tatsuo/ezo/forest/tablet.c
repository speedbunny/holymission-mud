inherit "obj/treasure";

#define TO (this_object())
  
reset(arg) {
    
  if (arg) return;

  set_name( "A stone tablet");
set_weight(80);
  set_alt_name( "tablet" );
  set_alias( "stone" );
  set_short("A stone tablet");
  set_long("A stone tablet. Some nihonese runes are written at it.\n");
}

init()

{
   ::init();

   add_action( "do_read", "read" );
}

do_read( arg )
{
   if ( this_object()->id( arg ) ) {
      ltell( this_player(), "on the tablet is the following:",
           
           "\n...............x.....................v........exe...........\n"+
             ".......... ou know, dear Hawakusa-san, the ma.g.c ords......\n"+
             "...to mu.ble in th. ma.ing of bl.nd.ng eg.s..a.e............\n"+
             "............takayoto ai gemosa..............................\n"+
             "...But, ..ar Hawa..sa-san, be carefull ..th this ...........\n"+
             "............................................................\n",



             this_object() );
       return( 1 );
   }

   return( 0 );
}

int speaks_in()          { return( 1 ); }
int act_language_skill() { return(100); }
int language_skill( int lang ) { if (lang==1) return 100; return 0; }
string query_real_name() { return("Written"); }
 

