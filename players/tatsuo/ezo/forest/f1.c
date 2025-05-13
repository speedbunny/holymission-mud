#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "west, northwest and north" );
   set_up_dir( PPATH + "t1" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ SPATH + "sh2",   "northeast",
                 SPATH + "sh4",   "east",
                 SPATH + "sh6",   "southeast",
                 PPATH + "f5",    "south",
                 PPATH + "f4",    "southwest",
              });
}

init( )
{
   ::init();
}
