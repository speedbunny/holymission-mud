#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "northwest" );
   set_up_dir( PPATH + "t5" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f1",  "north",
                 SPATH + "sh4", "northeast",
                 SPATH + "sh6", "east",
                 SPATH + "sh8", "south",
                 PPATH + "f10", "southwest",
                 PPATH + "f4",  "west",
              });
}

init( )
{
   ::init();
}
