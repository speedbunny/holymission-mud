#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "northeast" );
   set_up_dir( PPATH + "t6" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f3",  "north",
                 PPATH + "f7",  "east",
                 PPATH + "f11", "southeast",
                 SPATH + "sh9", "south",
                 SPATH + "sh7", "west",
                 PPATH + "f2",  "northwest",
              });
}

init( )
{
   ::init();
}
