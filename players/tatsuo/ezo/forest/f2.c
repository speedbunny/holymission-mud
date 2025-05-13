#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "north and northeast" );
   set_up_dir( PPATH + "t2" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f3",  "east",
                 PPATH + "f6",  "southeast",
                 SPATH + "sh7", "south",
                 SPATH + "sh5", "west",
                 SPATH + "sh3", "northwest",
              });
}

init( )
{
   ::init();
}
