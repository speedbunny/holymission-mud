#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "" );
   set_up_dir( PPATH + "t21" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f14",  "north",
                 PPATH + "f15",  "northeast",
                 PPATH + "f22",  "east",
                 PPATH + "f27",  "southeast",
                 PPATH + "f26",  "south",
                 PPATH + "f25",  "southwest",
                 PPATH + "f20",  "west",
                 PPATH + "f13",  "northwest",
              });
}

init( )
{
   ::init();
}
