#define PPATH    "/players/tatsuo/ezo/ryuworld/"

inherit PPATH + "genWater";

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   dest_dir = ({ PPATH + "w3", "down",
                 PPATH + "w5", "up"
              });
}
