#define PPATH     "/players/tatsuo/ezo/ryuworld/"

object *ryu;

inherit PPATH+"genCave";

reset( arg )
{
   ::reset( arg );

/*
   if ( !ryu || !living( ryu ) && !find_living( "ryu" ) ) {
      ryu = clone_object( "/players/tatsuo/eastMonst/ryu" );
      move_object( ryu, this_object() );
   }
*/

"/players/tatsuo/eastMonst/ryu"->reset();

   if ( arg )
      return;

   dest_dir = ({ PPATH + "c3", "north",
                 PPATH + "c9", "east",
                 PPATH + "c13", "south"
              });
}
