inherit "obj/thing";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("applepie");
  set_alias("pie");
  set_short("A delicious applepie");
  set_long("This is a very delicious looking applepie.\n");
  set_weight(1);
}

init()
{
  add_action("throw_me","throw");
  add_action("throw_me","toss");
  add_action("eat_me","eat");
}

throw_me(arg)
{
string s1,s2;
object ob;
  if(!arg)
   {
     notify_fail("Throw what??\n");
     return 0;
   }
  if(sscanf(arg,"%s at %s",s1,s2)!=2)
   return 0;
   else
   {
     if(id(s1))
      {
        if(!ob=present(s2,environment(this_player())))
         {
           notify_fail("Throw pie at whom??\n");
           return 0;
         }
        else
         {
           write("You throw a pie at "+s2+".\n");
           say(this_player()->query_name()+" throws a pie at "+s2+".\n",ob);
           tell_object(ob,this_player()->query_name()+" throws a pie "+
                       " in the middle of your face.\n");
           destruct(this_object());
           return 1;
         }
      }
    }
}

eat_me(arg)
{
  if(id(arg))
   {
     write("You eat the pie, it tastes great!\n");
     say(this_player()->query_name()+" seems to enjoy a pie!\n");
     destruct(this_object());
     return 1;
   }
}
