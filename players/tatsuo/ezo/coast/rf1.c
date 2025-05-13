#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "southeast" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c2",   "north",
                 PPATH + "c3",   "northeast",
                 PPATH + "rf2",  "east",
                 PPATH + "rf11", "south",
                 PPATH + "rf10", "southwest",
                 PPATH + "c11",  "west",
                 PPATH + "c1",   "northwest",
              });
}

init( )
{
   ::init();
}
