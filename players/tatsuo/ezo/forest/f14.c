#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "northwest, north and northeast" );
   set_up_dir( PPATH + "t14" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f15",  "east",
                 PPATH + "f22",  "southeast",
                 PPATH + "f21",  "south",
                 PPATH + "f20",  "southwest",
                 PPATH + "f13",  "west",
              });
}

init( )
{
   ::init();
}
