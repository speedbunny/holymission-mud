#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "southeast, south and southwest" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c4",   "north",
                 PPATH + "c5",   "northeast",
                 PPATH + "rf4",  "east",
                 PPATH + "rf2",  "west",
                 PPATH + "c3",   "northwest",
              });
}

init( )
{
   ::init();
}
