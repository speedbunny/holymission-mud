#define PPATH    "/players/tatsuo/ezo/ryuworld/"

inherit PPATH + "genWater";

reset( arg )
{
   ::reset( arg );

   if ( !present( "kojin", this_object() ) && random(2) )
      move_object( clone_object("/players/tatsuo/eastMonst/kojin" ),
                   this_object() );

   if ( arg )
      return;

   dest_dir = ({ PPATH + "wo2", "east",
                 PPATH + "w2", "west"
              });
}
