inherit "obj/treasure";

#define TO (this_object())
  
reset(arg) {
    
  if (arg) return;

  set_name( "torn piece of paper" ); 
  set_alt_name( "paper" );
  set_alias( "piece" );
  set_short("A torn piece of paper");
  set_long("A torn piece of paper. Some nihonese runes are written at it.\n");
}

init()
{
   ::init();

   add_action( "do_read", "read" );
}

do_read( arg )
{
   if ( this_object()->id( arg ) ) {
      ltell( this_player(), "on the paper is the following:",
           "\n...............x.....................v........exe...........\n"+
             ".......... ou know, dear Hawakusa-san, the pas..ord:........\n"+
"...At the gate, say in nihonese.............................\n"+
             "...In the n.me of .m....asu, I com.and thee to .pen.........\n"+
             "...But, ..ar Hawa..sa-san, be carefull ..th this .ape.......\n"+
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
