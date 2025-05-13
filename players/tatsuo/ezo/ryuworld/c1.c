#define PPATH     "/players/tatsuo/ezo/ryuworld/"

inherit PPATH+"genCave";

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   dest_dir = ({ PPATH + "c2", "east",
                 PPATH + "c6", "south"
              });
}

mixed move(string arg)
{
    if (!arg) arg = query_verb();
    if (arg=="east" && present("fire giant",this_object()))
    {
       tell_object(this_player(),
       "You try to go east, but the fire giant is in the way.\n");
       return 1;
    }
   return ::move(arg);
}
