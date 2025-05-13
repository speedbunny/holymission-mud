#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genCoast";

reset( arg )
{
   set_tekagi();

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c10",  "east",
                 PPATH + "rf9", "southeast",
                 PPATH + "rf8", "south",
                 PPATH + "rf7", "southwest",
                 PPATH + "c8",  "west",
              });
}

init( )
{
   ::init();
}
