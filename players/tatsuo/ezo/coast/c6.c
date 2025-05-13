#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genCoast";

reset( arg )
{
   set_tekagi();

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c7",  "east",
                 PPATH + "rf6", "southeast",
                 PPATH + "rf5", "south",
                 PPATH + "rf4", "southwest",
                 PPATH + "c5",  "west",
              });
}

init( )
{
   ::init();
}
