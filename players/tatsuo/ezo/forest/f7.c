#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "north and northeast" );
   set_up_dir( PPATH + "t7" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f8",  "east",
                 PPATH + "f12", "southeast",
                 PPATH + "f11", "south",
                 SPATH + "sh9", "soutwest",
                 PPATH + "f6",  "west",
                 PPATH + "f3",  "northwest",
              });
}

init( )
{
   ::init();
}
