#define PPATH "/players/tatsuo/ezo/coast/"
#define FPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/coast/genShore";

reset( arg )
{
   set_rf_dirs( "northwest" );
   set_shore_dirs( "southeast and northwest" );
   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ FPATH + "f2",   "north",
                 FPATH + "f3",   "northeast",
                 FPATH + "f6",   "east",
                 PPATH + "sh9",  "southeast",
                 PPATH + "sh5",  "northwest",
              });
}

init( )
{
   ::init();
}
