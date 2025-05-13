#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

object *ob;

reset( arg )
{
   set_rf_dirs( "west, northwest and north" );
   set_up_dir( PPATH + "t4" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f1",  "northeast",
                 PPATH + "f5",  "east",
                 SPATH + "sh8", "southeast",
                 PPATH + "f10", "south",
                 PPATH + "f9",  "southwest",
              });
}

init( )
{
   ::init();
}
