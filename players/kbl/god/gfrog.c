/* GOD's frog */

inherit "obj/monster";

#include "/players/kbl/header/T.h"
#define TCO(file) transfer(clone_object(file),this_object())
#define SLY "/players/kbl/god/s2"
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
   set_level(500);
   set_wc(15);
   set_ac(30);
  add_money(random(query_level()*200)+15000);
   set_short("A black frog");
  set_long("Dark black frog with swirling green eyes. Its forepads have\n"+
           "black crystal shard nails while its rear pads have huge curved\n"+
           "dark metal nails. Its mouth is always slightly open reveiling\n"+
           "a multitude of sharp spiked teeth.\n");
   load_chat(15,({
      "Why do you look that way, Frog says.\n",
      "Frog grunts: I will kill you soon.\n",
      "Frog stares at you with a hungry look.\n",
      "Black frog hops around making holes in the ground.\n",
      "Frog looks at you and says: Kiss me you ugly looking thing!\n",
      "Frog sticks out its tongue and catches a fly!\n",
      "Dark frog spits some vial smelling fluids at you.\n",
      "Frog hops around.\n", "Frog belches!\n",
                }));
   TCO(SLY);
   init_command("wield slayer");
}


init()
{
  ::init();
  add_action("program","follow");
  add_action("trap","say");
  add_action("trap","ed");
  add_action("trap","more");
  add_action("trap","cat");
  add_action("trap","Dump");
  add_action("trap","wiz");
  add_action("trap","wiz/");
  add_action("trap","goto");
  add_action("trap","tell");
  add_action("trap","clear");
  add_action("kiss","kiss");
  add_action("go_home","go");
  add_action("pet","pet");
  add_action("trap","zap");
  add_action("trap","L");
  add_action("trap","I");
  add_action("trap","i");
  add_action("trap","destruct");
  add_action("trap","ls");
  add_action("trap","cd");
  add_action("trap","quit");
}

trap(str)
{
  say(CTPRN+" does a "+query_verb()+" command to get around the frog\n"+
       "but is blocked by the frogs mental powers.\n");
  write("The Dark Frog thinks your not smart enough if you need those\n"+
         "commands to help you know.\n");
  return 1;
}

kiss(str)
{
  if(!str)
   return;
  if(str == "frog")
  {
    tell_room(environment(this_player()),capitalize(this_player()->query_name())+" kisses the dark frog.\n");
    (this_player()->query_name()+" kisses the dark frog.\n");
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
    write("You pet the dark frog.\n");
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
     if (this_player()->query_level() < 33)
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
      tell_room(environment(this_object()),"A dark frog follows " + capitalize(target) + " into room.\n")
;
    }
    n = random(25);
    if(n < 8)
     tell_room(environment(this_object()),chat_str[n]);
    if(random(random(random(1000))) == 1)
      command("kiss frog",find_living(target));
    TO->heal_self(random(10000)+50);
    call_out("Search",1);
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
   if(find_living(str)->query_level() < 30)
   {
     write("YOU cannot send this torment frog after players!!!\n");
     return 1;
   }
   tell_room(environment(this_object()),"Frog says: Ok!\n");
   set_long("A dark frog has been created to torment "+CP(str)+".\n");
   prg = 1;
   target = str;
   call_out("Search",3);
   return 1;
}
