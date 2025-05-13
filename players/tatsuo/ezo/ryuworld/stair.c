#define PPATH     "/players/tatsuo/ezo/ryuworld/"

inherit "room/room";

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   short_desc= "Standing on a stair";
   long_desc="This is a stair in the caves of ezo. Looking up can you\n" +
             "see the the caves expanding and to your west is a heavy\n" +
             "iron grid.\n";

   items = ({ "wall", "Pitch black",
             "walls", "Pitch black",
             "grid", "A heavy iron grid. It is @@check_grid@@.\n" +
                     "Behind the grid can you see a more caves"
           });

   dest_dir = ({ PPATH + "cd", "up"
              });
}

init()
{
   ::init();

   add_action( "lock", "lock" );
   add_action( "unlock", "unlock" );
   add_action( "open", "open" );
   add_action( "close", "close" );
   add_action( "enter", "enter" );
   add_action( "enter", "west" );
}

enter( arg )
{
   if ( arg == "grid" || (query_verb()=="west" && !arg) ) {
      if ( (PPATH + "c10")->query_closed() )
         this_player()->move_player( "west#"+PPATH+"c10" );
      else {
         write( "You run against the closed grid.   OUCH !!!\n" );
         say( this_player()->query_name() + " runs against the grid.\n" +
              "Not very effective!\n" );
      }
      return( 1 );
   }
}

lock( arg )
{
   return( (PPATH + "c10")->lock(arg) );
}

unlock( arg )
{
   return( (PPATH + "c10")->unlock(arg) );
}

open( arg )
{
   return( (PPATH + "c10")->open(arg) );
}

close( arg )
{
   return( (PPATH + "c10")->close(arg) );
}

check_grid()
{
   return( (PPATH + "c10")->check_grid() );
}
