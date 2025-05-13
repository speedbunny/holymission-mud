
#define _file "/players/beardy/walhalla/obj/thor_shad"

inherit"obj/weapon";

void reset(int arg)
{ ::reset(arg);
  if(!arg)
  {
    set_name("hammer");
    set_alt_name("thor's hammer");

    
    set_short("thor's hammer");
    set_long("This is Thor's famous warhammer. Where did you get it \\n");

    set_type(1);
    set_class(20);
    set_value(9000);
    set_weight(4);
  }
}

int wield(string arg)
{
  object shad;

    if (id(arg) && !query_wielded())
    {
        if (this_player()->query_hands_free())
        { if(this_player()->query_guild()!=3)
          {
            write("You are not worth wielding such a wonderful weapon.\n");
            return 1;
           }
           shad = clone_object(_file);
           shad->start_shadow(this_player(),0,"thor_shad");
       }
    }
   return ::wield(arg);
}

int un_wield()
{
    if (this_player()->thor_shad())
        destruct(this_player()->thor_object());
   ::un_wield();
}


