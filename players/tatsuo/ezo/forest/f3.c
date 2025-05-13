#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "northwest, north, northeast and east" );
   set_up_dir( PPATH + "t3" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f7",  "southeast",
                 PPATH + "f6",  "south",
                 SPATH + "sh7", "southwest",
                 PPATH + "f2",  "west",
              });
}

init( )
{
   ::init();
}
