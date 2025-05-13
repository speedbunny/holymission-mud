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
      "The ceiling has collapsed here and a lot of huge boulders prevents\n"+
      "any move further. The only way is back to the southeast ...\n";

   items = ({ "ceiling", "It has collapsed",
              "boulders", "There are a lot of small ones and two larger ones",
              "boulder", "Do you have any particular in mind ?",
              "larger boulder", "It appears like you could see THROUGH it",
              "larger boulders", "It appears like you could see THROUGH it",
              "large boulder", "It appears like you could see THROUGH it",
              "large boulders", "It appears like you could see THROUGH it",
              "small boulders", "Solid rock",
              "small boulder", "Solid rock",
              "smaller boulders", "Solid rock",
              "smaller boulder", "Solid rock",
           });

	dest_dir = ({ PPATH + "link6", "southeast",
				 });
}

init()
{
   ::init();

   add_action( "_enter", "enter" );
}

int _enter( string arg )
{
   if ( arg != "large boulder" && arg != "larger boulder" &&
        arg != "larger boulder" && arg != "larger boulders" )
      return( 0 );

   write( "Damned illusions !\n" );
   this_player()->move_player( "disappears behind the boulders#"+
                               PPATH+"link8" );

   return( 1 );
}
