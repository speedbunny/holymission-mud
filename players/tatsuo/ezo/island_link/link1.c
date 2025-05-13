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
   short_desc = "Dead end";
   long_desc = 
      "A really narrow tunnel, but at least you can crawl in it.\n"+
      "It is hewn out of the rock very unskillfully and you have to keep\n"+
      "your head down. Unfortunately the tunnel ends here.\n";

   items = ({"rock", "There appears to be a crack in the wall\n",
            "crack", "It is running from the ceiling to the floor", });
	dest_dir = ({ PPATH + "link2", "north", });
}

init()
{
   ::init();

   add_action( "do_enter", "enter" );
}

do_enter( what )
{
   if ( what != "crack" )
      return( 0 );

   this_player()->move_player( "into the wall#players/tatsuo/ezo/conn5" );

   return( 1 );
}
