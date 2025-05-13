#define PPATH     "/players/tatsuo/ezo/ryuworld/"

inherit PPATH+"genCave";

reset( arg )
{
   ::reset( arg );

   if ( !present( "kojin", this_object() ) ) {
      move_object( clone_object( "/players/tatsuo/eastMonst/kojin" ),
                   this_object() );
      move_object( clone_object( "/players/tatsuo/eastMonst/kojin" ),
                   this_object() );
      move_object( clone_object( "/players/tatsuo/eastMonst/kojin" ),
                   this_object() );
   }

   if ( arg )
      return;

   dest_dir = ({ PPATH + "w5", "down",
                 PPATH + "ce", "west"
              });
}
