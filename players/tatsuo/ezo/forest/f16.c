#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "northwest" );
   set_up_dir( PPATH + "t16" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f9",   "north",
                 PPATH + "f10",  "northeast",
                 PPATH + "f17",  "east",
                 SPATH + "sh12", "southeast",
                 PPATH + "f23",  "south",
                 PPATH + "f22",  "southwest",
                 PPATH + "f15",  "west",
              });
}

init( )
{
   ::init();
}
