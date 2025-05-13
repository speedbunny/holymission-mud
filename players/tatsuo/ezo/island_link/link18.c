#define PPATH "/players/tatsuo/ezo/island_link/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     this_object();

inherit "/room/room";

reset( arg )
{
   if ( arg )
      return;
      
   set_light(0);
   short_desc = "A tunnel";
   long_desc = 
        "A narrow tunnel, mostly natural, with slight human (or dwarvish)\n"+
        "modifications. It is high enough so that you can walk upright.\n" +
        "It slopes downward. To the west a narrow hole can be seen.\n";

	dest_dir = ({ PPATH + "link17", "east" });

   items = ({"hole", "You surely can craw through. Just enter it" });
}

init()
{
   ::init();

   add_action( "do_enter", "enter" );
}

do_enter( arg )
{
   if ( !arg )
      return;

   if ( arg != "hole" ) 
      write( "This is not possible....\n" );
   else {
      write( "You enter the hole and crawl through to the other side....\n" );
      TP->move_player( "through the hole#"+PPATH+"link19" );
   }
 
   return( 1 );
}
