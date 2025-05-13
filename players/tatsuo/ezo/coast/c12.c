#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genCoast";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "rf13", "south",
                 PPATH + "rf12", "southwest",
                 PPATH + "rf9",  "west",
                 PPATH + "c10",  "northwest",
              });
}

init( )
{
   ::init();
}
