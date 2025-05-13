#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "southeast and south" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c3",   "north",
                 PPATH + "c4",   "northeast",
                 PPATH + "rf3",  "east",
                 PPATH + "rf11", "southwest",
                 PPATH + "rf1",  "west",
                 PPATH + "c2",   "northwest",
              });
}

init( )
{
   ::init();
}
