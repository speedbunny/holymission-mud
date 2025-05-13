

/* pentagram.c */

inherit "obj/treasure";

#define MONK 7
#define TP this_player()

string owner;
object act, last;

void reset(int flag) 
{
     ::reset(flag);
   if (!objectp(environment()) || !living(environment()) && flag!=0)
   {
       call_out("dest_me",2);
   }
   if(flag==0) 
   {
      set_id("pentagram");
      set_long("A small pentagram, just read it for help.\n");
      set_light(2);
   }
}

string short()
{
     object env;

      env = environment();

      if (env && interactive(env))
         return "A pentagram (glowing)";
            
      return "A pentagram";
}
void init() 
{
   if (interactive(TP) && TP->query_guild()!=MONK &&
       TP->query_real_name()!=owner)
   {
      write("Suddenly the pentagram disappears from in hands.\n");
      destruct(this_object());
      return;
    }
   add_action("do_read","read");
   if (TP->query_guild()==MONK)
   {
     if (!stringp(owner))
      owner = TP->query_real_name();
      add_action("do_owner","owner");
   /* removed by whisky because teleport should be a mage feature
      add_action("do_rub","rub");
      add_action("do_turn","turn");
      add_action("do_weave","weave");
   */
   }
}
  
int do_owner(string arg) 
{
   if(!arg) 
   {
      notify_fail("The current owner is "+owner+".\n");
      return 0;
   }
   owner = arg;
   write("The current owner is now "+owner+".\n");
   return 1;
}


int do_read(string arg)  
{ 
   if (arg=="pentagram" && TP->query_real_name()==owner) 
   {
   if (TP->query_guild()==MONK)
   {
    write("You see a small pentagram the current owner is: "+owner+"\n"+
      "This small magic item gives you a free entrance to the monks-guild.\n"+
      "The pentagram will spend you some light in the darkness.\n");
   }
   else {
     write("You see a small pentagram. The current owner is: "+owner+"\n"+
           "It gives you a free entrance into the monks guild.\n");
    }
  }
   else if (arg=="pentagram" && TP->query_real_name()!=owner) 
   {
    write("You see a small pentagram.\n");
   } else
     return 0;
  return 1;
} 

int drop() 
{
   if (this_player()->query_guild()==MONK || TP->query_real_name()==owner) 
   {
      last = act = 0;
      return 0;
   }
   return 1;
}

/*
int get()
{
    write("As you take the pentagram, you wear it around your neck.\n");
    return 1;
}
  */
int do_turn(string arg) 
{
   string file;

   if (arg!="pentagram") return 0;

   if (environment(TP)->query_property("no_teleport") )
   {
       write("Somehow you don't manage to turn your pentagram.\n");
       return 1;
   }
   else if (TP->query_real_name()!=owner) 
      write("You are not the owner !\n"); 
   else if (TP->query_spell_points() <= 20) 
      write("You are too low on power to turn the pentagram !\n");
   else
   {
     write("You fade away.\n");

     if (!last)
     {
        last = environment(TP);
        TP->move_player("in a cloud of mushrooms#/players/whisky/guild/room/bar");
     } 
     else {
        act = last;
        last = environment(TP);
        file = file_name(act);
       TP->move_player("in a cloud of mushrooms#/"+file_name(act));
     }
         TP->restore_spell_points(-20);
   } 
   TP->command("look"); 
  return 1;
}
   
int do_rub(string arg)
{
   if (arg!="pentagram") return 0;
     say(TP->query_name()+" rubs a pentagram.\n");
      write("Your pentagram hums softly.\n");
      last = act = 0;
   return 1;
}

int do_weave(string arg)
{
    if (arg!="pentagram") return 0;
        write("You weave your pentagram.\n");
       say(this_player()->query_name()+" weaves a pentagram.\n");
        last = environment(TP);
      return 1;
}

void dest_me()
{
    if (!objectp(environment()) || !living(environment()))
     destruct(this_object());
}
int query_is_lit()
{
    return 1;
}
