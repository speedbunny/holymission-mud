#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "west, northwest and north" );
   set_up_dir( PPATH + "t9" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f4",  "northeast",
                 PPATH + "f10", "east",
                 PPATH + "f17", "southeast",
                 PPATH + "f16", "south",
                 PPATH + "f15", "southwest",
              });
}

init( )
{
   ::init();
}
