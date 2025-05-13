#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genCoast";

reset( arg )
{
   set_tekagi();

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c5",  "east",
                 PPATH + "rf4", "southeast",
                 PPATH + "rf3", "south",
                 PPATH + "rf2", "southwest",
                 PPATH + "c3",  "west",
              });
}

init( )
{
   ::init();
}
