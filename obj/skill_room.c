inherit "room/room";

#define SM   "/obj/skill_master"

reset( arg )
{
   if ( arg )
      return;

   set_light( 1 );
   short_desc = "skill-room";
   long_desc = "This is the skill-room.\n" +
               "I hoff, des reicht, wei mehr fait ma net ein!\n"+
               "Aso, wenn du huefe brauchst, tipp oinfoch \"help\".\n";
}

init( )
{
   ::init();

   add_action( "help", "help" );
   add_action( "dump", "dump" );
   add_action( "add_spell", "add" );
}

help()
{
   write( "wia du vielleicht schon erroten host, bin i z'faul dazu *grin*\n" );
   return( 1 );
}

dump( arg )
{
   mixed *arr;
   int   i;

   if ( arg == "spell-desc" ) {
      arr = SM->dump_spells();
      if ( arr ) {
         printf( "%-20s %-40s %5s\n", "spell-name", "path", "time" );
         printf( "-------------------------------------------------------------------\n" );
         for ( i = 0; i < sizeof( arr[0] ); i++ )
            printf( "%-20s %-40s %4d\n", arr[0][i], arr[1][i],
                   arr[2][i] );
         printf( "-------------------------------------------------------------------\n" );
      } 
      else
         write( "No spell-desc saved (strange)\n" );
      return( 1 );
   }
   else if ( arg == "skills" ) {
      arr = SM->dump_skills();
      if ( arr ) {
         printf( "%-20s %5s\n", "skill-name", "level" );
         printf( "--------------------------\n" );
         for ( i = 0; i < sizeof(arr[0]); i++ )
            printf( "%20s %4d\n", arr[0][i], arr[1][i] );
         printf( "--------------------------\n" );
      }
      else
         write( "No skills saved\n" );
      return( 1 );
   }
   
   if ( dump_spell( arg ) ) return( 1 ); 
 
   write( "wrong arg: you can use \"spell-desc\", \"skills\",\n"+
	  "           \"<player> <spell>|all\"\n" );
   return( 1 );
}

add_spell( arg )
{
   object who;
   string name, n;
   int    l, m, t, ret;

   if ( !arg )
      return( 1 );

   if ( sscanf( arg, "%s '%s' %d, %d, %d", name, n, l, m, t ) != 5 ) {
      write( "wrong number of arguments, aborted\n" );
      return( 1 );
   }
 
   if ( !name ) {
      write( "Add whom a spell ?\n" );
      return( 1 );
   }

   who = find_player( name );

   if ( !who ) {
      write( "No such player online. aborted\n" );
      return( 1 );
   }

   ret = who->change_spell( n, l, m, t );

   write( "skill changed. <return> = " + ret + "\n" );

   return( 1 );
}

dump_spell( arg )
{
   object who;
   string name, what;
   int    i;
   mixed  *arr;

   if ( !arg )
      return( 0 );

   if ( sscanf( arg, "%s %s", name, what ) != 2 )
      return( 0 );

   who = find_player( name );
   if ( !who ) {
      write( "no such player online, aborted\n" );
      return( 1 );
   }

   if ( what == "all" ) {
      arr = who->get_spell( -1 ); 
      if ( arr ) {
         for ( i = 0; i < sizeof( arr[0] ); i++ )
            printf( "%20s %10d %10d %10d\n", arr[0][i], arr[1][i],
                                             arr[2][i], arr[3][i] );
      }
      else
         write( "this player has no spells\n" );
   }
   else {
      arr = who->get_spell( what );
      if ( arr )
            printf( "%20s %10d %10d %10d\n", arr[0], arr[1],
                                             arr[2], arr[3] );
      else 
         write( "no such spell available at this player\n" );
   }

   return( 1 );
}
