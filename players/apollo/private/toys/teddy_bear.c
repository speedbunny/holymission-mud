
inherit "obj/treasure";
string target;

reset(arg)
{
  ::reset(arg);
  if(arg)
    return;
  set_name("bear");
  set_alt_name("bear");
  set_alias("bear");
  set_short("A little teddy bear");
  set_long("A cute little teddy bear, with button eyes.\n"+
           "Use <bhelp> to get help with the bear.\n"); 
  }

drop()
{
write("The teddy screams in agony as it rolls around on the ground.\n"+
      "Waldo appears in a puff of smoke. He says: 'Come here fella'.\n"+
      "The bear jumps into his arms and Waldo summons a gremlin to\n"+
      "take the bear back to his home.\n");
destruct(this_object());
return 1;
}

init()
{
  ::init();
  add_action("bear_help","bhelp");
  add_action("bear_send","bsend");
  add_action("hug","hug");
  add_action("go_home","go");
  add_action("pet","pet");
}

bear_help()
{
write ("The Ultimate teddy bear help\n"+
       "----------------------------\n\n"+
       "bhelp          - This little helper page\n"+
       "bsend <player> - Send the bear to <player>\n"+
       "bhug           - Hug the teddy bear\n"+
       "go             - Sends the bear away\n"+
       "pet            - Pets the bear\n"+
       "\n");
       return 1;
}

hug(str)
{
  if(!str)
    return;
  if(str == "bear")
    {
    tell_room(environment(this_player()),capitalize(this_player()->query_name())+" hugs the bear.\n");
    write("You hug the bear!\n");
    write("The bear sends you a mental picture....\n"+
          "   ___                          ___   \n"+
          " {~._.~}   I'm a teddy bear   {~._.~} \n"+
          "  ( Y )     You just gotta     ( Y )  \n"+
          " ()~*~()        love me       ()~*~() \n"+
          " (_)-(_)                      (_)-(_) \n"          );
    return 1;
    }
  }

pet(str)
{
  if(!str)
    return;
  if (str!="bear")
    return;
  else
     {
      tell_room(environment(this_player()),"Someone pets the bear.\n");
      tell_room(environment(this_player()),"The bear growls in pleasure.\n");
      return 1;
      }
  return;
}

go_home(str)
{
   if(!str)
     return;
   if (str == "home")
   {
     if (this_player()->query_level() < 30)
     {
       write("Bear says: Says who, you!\n");
       write("Bear giggles at you.\n");
       tell_room(environment(this_player()),"Bear giggles at "+this_player()+"'s command.\n");
       return 1;
       }
     else
       {
       tell_room(environment(this_player()),"Bear say: Yes boss.  BYE! *belch* It then disappears.\n");
       destruct(this_object());
       return 1;
         }
     }
  }

bear_send(str)
{
   object nextperson;
   if(!str) {
      write("Your bear looks confused!\n");
      return 1;
   }
   if (!find_player(str))
     {
       write("Teddy tells you: No such player.\n");
       tell_room(environment(this_player()),"Bear giggles at "+this_player()+".\n");
       return 1;
       }
   nextperson=find_living(str);
   write("You send the bear to "+nextperson->query_name()+".\n");
   shout("Someone sends a teddy bear across to "+capitalize(nextperson->query_name())+".\n");
   move_object(this_object(),nextperson);
   return 1;
}
