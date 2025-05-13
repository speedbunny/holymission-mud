#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genCoast";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c3",  "east",
                 PPATH + "rf2", "southeast",
                 PPATH + "rf1", "south",
                 PPATH + "c11", "southwest",
                 PPATH + "c1",  "west",
              });
}

init( )
{
   ::init();
}
