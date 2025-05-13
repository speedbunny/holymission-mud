/* KBL's lover frog  */
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
  set_name("frog");
   set_alt_name("frog");
   set_alias("frog");
   set_race("monster");
   set_al(0);
   set_level(random(10)+5);
   set_wc(1);
   set_ac(15);
  add_money(random(query_level()*20)+150);
   set_short("A little green frog");
  set_long("A aqua-green frog with marmalade eyes.\n");
   load_chat(15,({
      "Why do you look that way, Frog says.\n",
      "Frog wants to follow somebody.\n",
      "Frog looks at you and says: Kiss me you lovely looking thing!\n",
      "Frog sticks out its tongue and catches a fly!\n",
      "Frog hops around.\n", "Frog belches!\n",
                }));
}


init()
{
  ::init();
  add_action("program","follow");
  add_action("kiss","kiss");
  add_action("go_home","go");
  add_action("pet","pet");
}

kiss(str)
{
  if(!str)
   return;
  if(str == "frog")
  {
    tell_room(environment(this_player()),capitalize(this_player()->query_name())+" kisses the aqua-green frog.\n");
    (this_player()->query_name()+" kisses the aqua-green frog.\n");
    write("You kiss the frog!\n");
    this_player()->frog_curse(1);
    return 1;
  }
}

pet(str)
{

  int event;

  if(!str)
   return;
  if(str == "frog")
  {
    tell_room(environment(this_player()),capitalize(this_player()->query_real_name())+" pets the frog.\n");
    write("You pet the green frog.\n");
     tell_room(environment(this_player()),"The frog belches loudly and shutters from the petting.\n");
    write("The frog belches loudly and shutters from the petting.\n");
    event = random(50);
    if(event == 40 || event == 45)
    {
     transfer(clone_object("players/kbl/objs/unfrog"),this_player());
tell_room(environment(this_player()),capitalize(this_player()->query_real_name())+" pulls a leaf off of the frog.\n");
     write("You find a leaf on the frog. It looks interesting...\n");
    }
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
       write("Frog says: Says who, you!\n");
       write("Frog falls down laughing.\n");
       tell_room(environment(this_player()),"Frog falls down laughing.\n");
       return 1;
     }
     else
     {
       tell_room(environment(this_player()),"Frog say: Yes boss.  BYE! *belch*  It then disappears.\n");
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
      chat_str[0] = "Frog hops around the room looking for flies.\n";
      chat_str[1] = "Frog looks up at " + capitalize(target) + " adoringly.\n";
      chat_str[2] = "Frog makes belching noises.\n";
      chat_str[3] = "Frog flips out tongue and catches a huge fly!\n";
     chat_str[4] = "Frog says: I love you "+capitalize(target)+"!\n";
      chat_str[5] = "Frog exclaims: Floors and secret doors, my my *8^)\n";
      chat_str[6] = "Frog says: Why are you so ugly!\n";
      chat_str[7] = "Frog lifts its left leg and farts rudely!\n";
    }
    if (!find_living(target))
    {
      tell_room(environment(this_object()),"Frog looks around and hribbbits! Then it disappears.\n");
      destruct(this_object());
      return 1;
    }
    if (!present(find_living(target), environment(this_object())))
    {
      tell_room(environment(this_object()),"Frog looks around for " + capitalize(target) + ", then hops away.\n")
;
      move_object(this_object(), environment(find_living(target)));
      tell_room(environment(this_object()),"A little green frog follows " + capitalize(target) + " into room.\n")
;
    }
    n = random(25);
    if(n < 8)
     tell_room(environment(this_object()),chat_str[n]);
    call_out("Search",3);
    return 1;
}

program(str)
{
  if(this_player()->query_level() < 10)
   {
     write("Frog says: I'm sorry I picked YOU!\n");
     return 1;
   }
   if (!str)
   {
     tell_object(this_player(), "Frog says: Program who?\n");
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
     tell_object(this_player(),"Frog says "+str+" is not in the game presently.\n");
     return 1;
   }
   tell_room(environment(this_object()),"Frog says: Ok!\n");
   set_long("A little froggy has taken a liken to " + capitalize(str) + ".\n");
   prg = 1;
   target = str;
   call_out("Search",3);
   return 1;
}
