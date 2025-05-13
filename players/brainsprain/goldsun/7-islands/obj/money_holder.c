inherit "obj/treasure";
#define MAX_AMOUNT 50000000  
 
int amount;

void reset(int i)
{ 
 ::reset(i);
 if (i) return;
 set_name("ice chest");
 set_alias("chest");
 set_short("An ice chest");
 set_long("Small ice chest. It is not common chest but only small imitation\n"+
	  "of chest. On the cover you can see Sighart's note: 'ravanata'\n"+
	  " 'atanavar'  'rechecor'\n");
 set_weight(1);
 set_value(12000);
 amount=0;
}

void init()
{
 ::init();
 add_action("_ravanata","ravanata");
 add_action("_atanavar","atanavar");
 add_action("_rechecor","rechecor");
}

int _ravanata(string amo)
{
 int num;
 notify_fail("Ravanata how much?\n");
 if (!amo) return 0;
 if (sscanf(amo,"%d",num)==1)
 {
   if (this_player()->query_money()<num)
   {
      write("A small ice duck jumps from the chest and duckes you:\n");
      write("You haven't "+num+" coins.\n");
      write("Ice duck jumps back to the chest.\n");
      return 1;
   }
   if (num> MAX_AMOUNT - amount)
   {
      write("A small ice duck jumps from the chest and duckes you:\n");
      write("The duck tells you: . There is not enough room in her for that amount.\n");
      write("Ice duck jumps back to the chest.\n");
      return 1;
   }
   write("A small ice duck jumps from the chest and takes the money from you.\n");
   write("Ice duck jumps back to the chest.\n");
   amount+=num;
   this_player()->add_money(-num);
   return 1;
 }

}

/*
int _ravanata()     
{
object ob, room_;
int i, count;
 
 ob=clone_object("obj/monster");
 ob->set_name("ice duck");       //         ICE DUCK       
 ob->set_level(99);
 ob->set_ac(12000);
 ob->enable_commands();

 room_=first_inventory(environment(this_player()));
 while(room_)
 {
  if (room_->query_money()) count++;
  room_=next_inventory(room_);
 }

 write("A small ice duck jumps from the chest.\n");
 transfer(ob,environment(this_player()));

 
 for(i=0;i<count;i++)
 {
   command("get coins",ob);      // this allowed xyz to hinder money ??   
   if (ob->query_money() <= MAX_AMOUNT-amount)
           amount+=ob->query_money();
   else write("Duck duckes you: There is not enough room for this amount.\n");
   ob->add_money(-ob->query_money());
 }

 destruct(ob);
 write("Ice duck jumps back to the chest.\n");
 return 1;
}

*/

int _rechecor()
{
  write("A small ice duck jumps from the chest and duckes you:\n");
  write("There are "+amount+" coins.\n");
  write("Ice duck jumps back to the chest.\n");
  return 1;
}

int _atanavar()
{
 object ob;
 ob=clone_object("/obj/money");
 ob->set_money(amount);
 write("A small ice duck jumps from the chest.\n");
 write("Ice duck drops coins.\n");
 say("Ice duck drops coins.\n");
 write("Ice duck jumps back to the chest.\n");
 transfer(ob,environment(this_player()));
 amount=0;
 return 1;
}


