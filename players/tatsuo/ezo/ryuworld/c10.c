#define PPATH     "/players/tatsuo/ezo/ryuworld/"

inherit PPATH+"genCave";

#define TP     (this_player())

int locked, closed;

reset( arg )
{
   ::reset( arg );

   locked = closed = 1;

   if ( arg )
      return;

   long_desc += "At the ceiling can you see the outlines of a trapdoor and\n"+
                "in the eastern wall is a heavy iron grid.\n";

   items += ({ "trapdoor", "It is the one, through which you felt",
               "grid", "The iron grid is @@check_grid@@.\n" +
                       "Behind it can you see a stair ascending",
               "stair", "It is behind the grid" });

   dest_dir = ({ PPATH + "c5", "north",
                 PPATH + "c15", "south",
                 PPATH + "c9", "west"
              });
}

init()
{
   ::init();

   add_action( "unlock", "unlock" );
   add_action( "open", "open" );
   add_action( "lock", "lock" );
   add_action( "close", "close" );
   add_action( "enter", "enter" );
   add_action( "enter", "east" );
}

enter( arg )
{
   if ( arg == "grid" || (query_verb()=="east" && !arg) ) {
      if ( !closed )
         this_player()->move_player("east#"+PPATH+"stair");
      else {
         write( "You run against the closed grid.   OUCH !!!\n" );
         say( this_player()->query_name() + " runs against the closed grid.\n"+
              "Not very effective !\n" );
      }
      return( 1 );
   }
}

unlock( arg )
{
   string key;

   if ( arg == "grid" ) {
      write( "Your nose is key-shaped, I suppose ?\n" );
      return( 1 );
   }

   if ( sscanf( arg, "grid with %s", key ) != 1 )
      return;

   if ( !locked )
      write( "The grid is already unlocked.\n" );
   else if ( (key=="key" || key=="bone key") && present( "_bone_key_", TP ) ) {
      write( "You unlock the grid with the bone key and the key crumbles to dust.\n" );
      destruct( present("_bone_key_", TP ) );
      locked = 0;
   }
   else if ( present( "key", TP ) )
      write( "This key won't fit.\n" );
   else 
      write( "And your nose is key-shaped, I suppose.\n" );

   return( 1 );
}

lock( arg )
{
   string key;

   if ( arg == "grid" ) {
      write( "Your nose is key-shaped, I suppuse ?\n" );
      return( 1 );
   }

   if ( sscanf( arg, "grid with %s", key ) != 1 )
      return;

   if ( locked )
      write( "The grid is already locked.\n" );
   else if ( (key=="key" || key=="bone key") && present( "_bone_key_", TP ) ) {
      write( "You lock the grid with the bone key and the key crumbles to dust.\n" );
      destruct( present("_bone_key_", TP ) );
      locked = 1;
   }
   else if ( present( "key", TP ) )
      write( "This key won't fit.\n" );
   else 
      write( "And your nose is key-shaped, I suppose.\n" );

   return( 1 );
}

open( arg )
{
   if ( arg == "grid" ) {
      if ( locked ) 
         write( "It is locked !\n" );
      else if ( !closed )
         write( "Open an open door !? Strange concept.\n" );
      else {
         write( "You open the grid.\n" );
         say( this_player()->query_name() + " opens the grid.\n" );
         closed = 0;
      }
      return( 1 );
   }
}

close( arg )
{
   if ( arg == "grid" ) {
      if ( locked )
         write( "The grid is locked, you cannot close it.\n" );
      else if ( closed )
         write( "The grid is already closed.\n" );
      else {
         write( "You close the grid.\n" );
         say( this_player()->query_name() + " closes the grid.\n" );
         closed = 1;
      }
      return( 1 );
   }
}

query_closed() { return( closed ); }

check_grid()
{
   if ( locked && closed )
      return( "locked and closed" );
   else if ( closed )
      return( "closed" );
   return( "open" );
}
