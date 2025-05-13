
inherit "/obj/treasure";

void reset(int arg)
{
   if (arg) return;

   set_name("scroll");
   set_alias("red scroll");
   set_short("a red scroll");            
   set_long(
   "You see a small red scroll. Written on it are the words: "+
                      "\n'despel evil' , 'remove curse'.\n");

   set_weight(1);
}

init()
{
  ::init();
  add_action("do_read","read");
  add_action("do_read","recite");
}

int do_read(string arg)
{
  int i,sz;
  object *inv;

   if (arg!="scroll" && arg!="red scroll") return 0;
   write("As you read the red scroll it bursts into flames.\n");
   say(this_player()->query_name()+" reads a red scroll.\n");

   inv = all_inventory(environment(this_player()));

   for (sz=sizeof(inv),i=0;i<sz;i++)
   {
     if (living(inv[i]) && inv[i]->query_alignment() < 0)
     {
         if (inv[i]->query_alignment() < 0)
             inv[i]->set_alignment(100);
         else 
             inv[i]->set_alignment(inv[i]->query_alignment()+100);
         tell_object(inv[i],"You feel somehow holier !\n");
     }
     if (inv[i]->query_cursed())
     {
         inv[i]->remove_curse();
         tell_room(environment(this_player()),
         inv[i]->query_name()+" glows red and then white.\n");
     }
   }
  destruct(this_object());
  return 1;
}
     
   

