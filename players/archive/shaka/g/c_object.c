/* THIS A TEST VERSION DON'T USE WHEN SHAKA IS NOT AROUND
   THANK YOU!!!! */
#define CHAT_ROOM "players/shaka/g/chat_room"
#define VOID      "players/shaka/g/my_void"
#define CHAT(x) tell_room(find_object(CHAT_ROOM),x)
object owner,chatter;

id(str) { return str=="chatter" || str=="SHK_chatter"; }
short() { return "A chatter"; }
long() { write("A general Shaka-Talker(test version).\n");
         write("Commands are:\n"+
               "chat <msg>         say <msg> over the line.\n"+
               "chat !<command>    do <command> over the line.\n"+
               "chatters           online shaka talkers.\n"+
               "leave              leave the line.\n");
}
get() { return 1; }
drop() { return 1; }

init()
{
  if(!environment()) return;
  if(!find_object(CHAT_ROOM)) clone_object(CHAT_ROOM);
  owner=environment();
  if(chatter=present(owner->query_real_name(),find_object(CHAT_ROOM)))
    destruct(chatter);
  chatter=clone_object("players/shaka/g/receiver");
  chatter->set_name(owner->query_real_name());
  chatter->set_receiver(owner);
  move_object(chatter,find_object(CHAT_ROOM));
  add_action("chat_func","chat");
  add_action("d_online","chatters");
  add_action("quit","quit");
  add_action("leave","leave");
}
d_online()
{
object u;
int i;

  write("Online shaka talkers:\n");
  u=users();
  for(i=0;i<sizeof(u);++i)
   {
     if(present("SHK_chatter",u[i]))
       write(" "+capitalize(u[i]->query_real_name())+".\n");
   } 
  return 1;
}
chat_func(arg)
{
object previous;
string comm;
  if(!arg) return 0;
  if(sscanf(arg,"!%s",comm))
   {
      write("[* Shaka Talk *] ");
      previous=environment(owner);
      move_object(chatter,VOID);
      move_object(owner,CHAT_ROOM);
      command(comm,owner);
      move_object(owner,previous);
      move_object(chatter,CHAT_ROOM);
      return 1;
   }
  else
  {
   if(find_object(CHAT_ROOM)) clone_object(CHAT_ROOM);
   CHAT(capitalize(owner->query_real_name())+": "+arg+".\n");
   return 1;
  }
}
     
quit() { if(chatter) destruct(chatter); }
leave() { if(chatter) destruct(chatter); destruct(this_object()); return 1; }
