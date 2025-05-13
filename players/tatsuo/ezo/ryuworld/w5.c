#define PPATH    "/players/tatsuo/ezo/ryuworld/"

inherit PPATH + "genWater";

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   dest_dir = ({ PPATH + "w4", "down",
                 PPATH + "cf", "up"
              });
}

init()
{
   object *diver;

   ::init();

   if ( this_player()->query_npc() )
      return;

   diver = present( "diver", this_player() );
 
   if ( !diver ) {
      diver = clone_object( PPATH + "diver" );
      move_object( diver, this_player() );
      diver->start_dive(this_player());
   }
   else
      diver->start_dive(this_player());
}
   
