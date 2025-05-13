/* Based on KBL's lover frog  */
inherit "obj/monster";
string target;
string chat_str;
int prg;

reset(arg)
{

   ::reset(arg);
   if(arg)
     return;
   prg = 0;
   set_name("harpy");
   set_alt_name("harpy");
   set_alias("bird");
   set_race("monster");
   set_level(1);
   set_hp(150);
   set_al(0);
   set_wc(1);
   set_sp(200);
   set_ac(1);
   set_short("A filthy harpy");
  set_long("A filthy harpy that you really don't want near you.\n");
   load_chat(8,({
      "Harpy pecks at your hair.\n",
      "Harpy wants to build a nest in your hair.\n",
      "Harpy says: Ack, you're so ugly only a harpy could love you!\n",
      "The harpies stench overpowers you!\n",
      "Harpy farts on you!\n",
                }));
 }


init()
{
  ::init();
  add_action("program","follow");
  add_action("program","program");
  add_action("go_home","go");
  add_action("look","look");
}
look(str)
{

  int event;

if(!str)
   return;
  if(str == "at harpy")
  {
    tell_room(environment(this_player()),capitalize(this_player()->query_real_name())+
    " looks disgustedly at the harpy.\n");
    write("Boy is it ugly!!\n");
     tell_room(environment(this_player()),"The harpy passes gas.\n");
    write("The harpy screeches loudly.\n");
   call_other(this_player(),"set_smell","Stinks of Harpy");
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
       write("Harpy says: Get a life!\n");
       write("Harpy musses your hair and start to build a nest.\n");
       tell_room(environment(this_player()),"Harpy is making a nest.\n");
       return 1;
 }
     else
     {
       tell_room(environment(this_player()),"Harpy says: Spoilsport!!\n");
       destruct(this_object());
       return 1;
     }
   }
}

Search()
{
    int n;
    
    if (!chat_str)
    {
      chat_str = allocate(8);
      chat_str[0] = "Harpy says:"+capitalize(target)+"is almost as ugly as me!\n";
      chat_str[1] = "Harpy tugs on the pants of" + capitalize(target) + ".\n";
      chat_str[2] = "Harpy says: Is that your hair? Or was it dragged up from the sea?\n";
      chat_str[3] = "Harpy struts around the room, showing it's tail feathers to all.\n";
      chat_str[4] = "Harpy pecks at your hair!\n";
    chat_str[5]="Harpy says: I'm ugly and my name is"+capitalize(target)+".\n";
      chat_str[6] = "Harpy says: I may be ugly but you're stupid! And i can have plastic surgery!\n";
      chat_str[7] = "Harpy starts cursing at the silly players!\n";
    }
    if (!find_living(target))
    {
      tell_room(environment(this_object()),"Harpy flies off leaving a stench.\n");
      destruct(this_object());
      return 1;
    }
if (!present(find_living(target), environment(this_object())))
    {
      tell_room(environment(this_object()),"Harpy sniffs the air for" + 
      capitalize(target) + ", flies away.\n");
      move_object(this_object(), environment(find_living(target)));
      tell_room(environment(this_object()),"A putrid smelling harpy follows " + 
      capitalize(target) + " into room.\n");
    }
    n = random(10);
    if(n < 8)
     tell_room(environment(this_object()),chat_str[n]);
    call_out("Search",3);
    return 1;
}

program(str)
 {
  if(this_player()->query_level() < 10)
   {
     write("Harpy says: @#^&@#@#@#@#@!)(!\n");
     return 1;
   }
   if (!str)
   {
tell_object(this_player(),"Harpy says: You want me to do what to whom?\n");
     return 1;
   }
   if(str == "me" || str == "self")
   {
     str = this_player()->query_real_name();
   }
   if(target)
if(target != str)
     chat_str = 0;
   if (!find_living(str))
   {
     tell_object(this_player(),"Harpy says: get real, "+str+" is not in the game presently.\n");
     return 1;
   }
   tell_room(environment(this_object()),"Harpy says: Ok!\n");
   set_long("A filthy bird is making " + capitalize(str) + "'s life miserable.\n");
   prg = 1;
   target = str;
   call_out("Search",3);
   return 1;
}
