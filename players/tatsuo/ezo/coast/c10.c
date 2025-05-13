#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genCoast";

reset( arg )
{
   set_tekagi();

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c12", "southeast",
                 PPATH + "rf9", "south",
                 PPATH + "rf8", "southwest",
                 PPATH + "c9",  "west",
              });
}

init( )
{
   ::init();
}
