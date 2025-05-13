inherit "room/room";
#define BAT "/players/kbl/objs/bat"
int found;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Small pit";
    long_desc = "A small narrow pit. Not much to see here.\n";
    dest_dir = ({
                 "/players/kbl/dungeon/dun12","up",
                 "/players/kbl/expa/exp3","climb",
                });
    items = ({
              "pit","Lined with moss and very damp",
              "narrow pit","Lined with moss and very damp",
              "moss","Green moss",
             });
  }
  event();
  found = 0;
}

init()
{
  ::init();
  add_action("get","get");
  add_action("enter","enter");
  add_action("search","search");
}

event()
{
  if(random(65) > 60)
   transfer(clone_object(BAT),this_object());
}

get(str)
{
  if(!str)
   return;
  switch(str)
  {
    case "moss":
         tell_object(this_player(),"You cannot get the moss.\n");
         return 1;
  }
}

enter(str)
{
  if(!found || !str)
   return;
  switch(str)
  {
    case "crawl space":
         transfer(this_player(),"/players/kbl/dungeon/dun14");
         tell_room(this_object(),capitalize(this_player()->query_real_name())+
                   " enters a crawl space under a ledge.\n");
         command("look",this_player());
         return 1;
  }
}


search(str)
{
  if(!str)
  {
    tell_object(this_player(),"Search what??\n");
    return 1;
  }
  switch(str)
  {
    case "pit":
         if(found)
          tell_object(this_player(),"You see a crawl space under a ledge"+
                                    "near the bottom of the pit.\n");
         else
         {
          tell_object(this_player(),"You find a crawl space under a ledge"+
                                    "near the bottom of the pit.\n");
          found = 1;
         }
         return 1;
  }
}
