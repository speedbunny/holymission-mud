#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "" );
   set_up_dir( PPATH + "t23" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f16",  "north",
                 PPATH + "f17",  "northeast",
                 SPATH + "sh12", "east",
                 SPATH + "sh14", "southeast",
                 PPATH + "f28",  "south",
                 PPATH + "f27",  "southwest",
                 PPATH + "f22",  "west",
                 PPATH + "f15",  "northwest",
              });
}

init( )
{
   ::init();
}
