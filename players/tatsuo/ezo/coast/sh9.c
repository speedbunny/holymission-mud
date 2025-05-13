#define PPATH "/players/tatsuo/ezo/coast/"
#define FPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/coast/genShore";

reset( arg )
{
   set_rf_dirs( "" );
   set_shore_dirs( "south and northwest" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ FPATH + "f6",   "north",
                 FPATH + "f7",   "northeast",
                 FPATH + "f11",  "east",
                 FPATH + "f18",  "southeast",
                 PPATH + "sh11", "south",
                 PPATH + "sh7",  "northwest",
              });
}

init( )
{
   ::init();
}
