#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "northwest, north, northeast and east" );
   set_up_dir( PPATH + "t8" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f13", "southeast",
                 PPATH + "f12", "south",
                 PPATH + "f11", "southwest",
                 PPATH + "f7",  "west",
              });
}

init( )
{
   ::init();
}
