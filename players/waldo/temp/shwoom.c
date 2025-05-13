inherit "room/room";
#define WIZ 40
string items;  
string beer_type; 
string short_desc; 
string long_desc; 
string base_dir; 
string empty_desc; 
string empty_short; 
string drink_msg; 
status empty;

can_put_and_get()
{
  if(!inside(this_player())) return 1;
  return 0;
}

get() { return 1; }

drop() { return 0; }

id(str)
{
int i;

  if(!inside(this_player()))
   return str=="beer" || str=="bottle";
  if(!items)
   return;
  while(i<sizeof(items))
   {
     if(items[i]==str)
      return 1;
     i+=2;
   }
  return 0;
}

init()
{
  add_action("climb","climb");
  add_action("enter","enter");
  add_action("drink_me","drink");
}


long(str)
{
int i;

  if(!inside(this_player()))
   {
     if(!empty)
      {
        write("A bottle of "+beer_type+" beer.\n");
        if(first_inventory(this_object()))
         write("There's is somebody or something floating in it.\n");
        return;
      }
     else
      {
        write("An empty bottle.\n");
        if(first_inventory(this_object()))
         write("There's is somebody or something in it.\n");
        return;
      }
   }
  if(set_light(0)==1)
   {
     write("It is too dark.\n");
     return;
   }
  if(!str)
   {
     if(empty) write(empty_desc);
     else write(long_desc);
     return;
   }
  if(!items) return;
  i=0;
  while(i<sizeof(items))
   {
     if(items[i]==str)
      {
        write(items[i+1]+".\n");
        return;
      }
     i+=2;
   }
}


short()
{
  if(!inside(this_player()))
   {
     if(!empty)
       return "A bottle of beer";
     else
       return "An empty bottle";
   }
  if(set_light(0))
   {
     if(!empty) return short_desc;
     else return empty_short;
   }
  return "Dark room";
}

inside(what)
{
  if(present(what,this_object()))
   return 1;
  return 0;
}

query_long()
{
  return long_desc;
}

query_value() { if(!empty) return 12; else return 10; }
query_weight() { return 1; }
query_drop_castle() { return 0; }

climb(arg)
{
   if(!inside(this_player())) return 0;
   if(arg!="out")
    {
      write("Climb where?\n");
      return 1;
    }
   say(this_player()->query_name()+" climbs out of the bottle.\n");
  
tell_room(environment(this_object()),this_player()->query_name()+
             " comes climbing out of the bottle.\n");
   move_object(this_player(),environment(this_object()));
   this_player()->look();
   return 1;
}

enter(arg)
{
  if(!inside(this_player()))
   {
     if(arg=="bottle")
      {
        if(this_player()->query_level()<WIZ) return 0;
        say(this_player()->query_name()+" leaves climbing into the bottle.\n");
        tell_room(this_object(),this_player()->query_name()+
                  " comes falling in.\n");
        move_object(this_player(),this_object());
        this_player()->look();
        return 1;
      }
   }
}

drink_me(arg)
{
  if(arg && arg!="beer" && arg!="from bottle") return 0;
  if(empty) return 0;
  if(!inside(this_player()))
   {
     if(!this_player()->drink_alcohol(2)) return 1;
     write(drink_msg+".\n");
     say(this_player()->query_name()+" drinks a bottle of beer.\n");
     tell_room(this_object(),
               "Suddenly "+this_player()->query_name()+
               " drinks the bottle, You are almost swallowed.\n"+
               "Luckily you got stuck in the bottle!\n");
     empty=!empty;
     return 1;
   }
  write("You take a deep dive in the beer and swallow a mouthfull of beer.\n"+
        "You don't think you will empty it this way before the reboot.\n");
  say(this_player()->query_name()+" swallows a mouthfull of beer.\n");
  tell_room(environment(this_object()),
            "You think you hear a faint SSlllurp from the bottle,\n"+
            "but you could be imagining.\n");
  this_player()->add_intoxination(2);
  return 1;
}

reset(arg)
{
  ::reset();
  if(!arg)
  {
    set_light(1);
    short_desc="A bottle of beer";
    long_desc="You're floating in a bottle full of "+beer_type+" beer.\n"+
              "The glass breaks the view from the outside.\n"+
              "You think it is possible to climb out.\n";
    empty_desc="You're standing on the bottom of an empty bottle.\n"+
               "You'd better refill it somewhere.\n";
    items=({"bottle","a bottle of beer",
            "glass","the glass of the bottle",
            "view","the glass blurrs the view",});
  }
}

