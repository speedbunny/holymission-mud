#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "" );
   set_up_dir( PPATH + "t17" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f10",  "north",
                 SPATH + "sh8",  "northeast",
                 SPATH + "sh10", "east",
                 SPATH + "sh12", "south",
                 PPATH + "f23",  "southwest",
                 PPATH + "f16",  "west",
                 PPATH + "f9",   "northwest",
              });
}

init( )
{
   ::init();
}
