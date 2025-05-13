#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genCoast";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c1",   "north",
                 PPATH + "c2",   "northeast",
                 PPATH + "rf1",  "east",
                 PPATH + "rf11", "southeast",
                 PPATH + "rf10", "south",
              });
}

init( )
{
   ::init();
}
