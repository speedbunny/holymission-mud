#define PPATH     "/players/tatsuo/ezo/ryuworld/"

inherit PPATH+"genCave";

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   dest_dir = ({ PPATH + "cd", "north",
                 PPATH + "cb", "west"
              });
}
