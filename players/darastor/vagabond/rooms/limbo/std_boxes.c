

/* boxes */

/* -----------------------------------------------------------------
   This are the so discussed boxes, therefore i give info about it:

   cost: 

          a box costs 1000 coins a week

   storing items:

          A player can store till maximum 8 items. Anytime she stores
          it she has to pay extra 10 + (itemvalue * _fc)/2. Master objects,
          items without a name, query_quest_object() are inpossible
          to store. When the renttime is over, the box and all items
          are deleted. If you dont want that your item cant be stored,
          put at the end a query_no_store() { return 1; }

   advantage:

         The box is rebootsecure.

   ---------------------------------------------------------------- */

#define _tp this_player()
#define _tpn _tp->query_name()
#define _tpr _tp->query_real_name()
#define _c   _tp->query_chr()
#define _fc  ((_c >= 40) ? 1 : ((40 - _c) / 5))

inherit "/room/room";

mapping boxes;
string clerk;
string save_file;
int cost;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        boxes = ([]);
        clerk = "Test";
        save_file = "/players/whisky/BOXES";
        cost = 1000;
        dest_dir = ({});
     }
}

void check_boxes()
{
   int i,sz,a,b;
   mixed *clients;
   string pl;
   mixed *arr;
   mixed *hilf;
   int time;

   if (stringp(save_file) && file_size(save_file+".o")!=-1)
   {
      restore_object(save_file);
      clients = m_indices(boxes);
      if ( (sz = sizeof(clients)) > 0)
      {
          for (i=0; i < sz; i ++)
          {
              arr = boxes[clients[i]];

              if (intp(arr[0]) && arr[0] < 1)
                  m_delete(boxes,clients[i]);
              else 
              {
               if (intp(arr[0]))
               {
                 time = arr[0] - 1;
                 arr = arr - ({ arr[0] });
                 hilf = ({ time }) + arr;
               }
                else
                 hilf = ({ 7 }) + arr;
                 pl = clients[i];
                 m_delete(boxes,clients[i]);
                 boxes = boxes + ([pl:hilf]);
              }
          }
      }
   }
}

void init()
{
  ::init();
  add_action("do_rent","rent");
  add_action("do_store","store");
  add_action("do_remove","remove");
  add_action("do_restore","restore");
  add_action("do_debug","debug");
  add_action("do_delete","delete");
  add_action("do_offer","offer");
  add_action("do_show","show");
  add_action("do_read","read");
  if (stringp(save_file))
      save_object(save_file);
}

int do_offer(string arg)
{
   object mob;
   int cost;

   if (!arg) 
       return 0;

   mob = present(arg,_tp);
   

   if (objectp(mob))
   {
      cost = 10 + (mob->query_value() * _fc) / 2;
      write(clerk+" tells you: \n"+
      "Storing that item would cost "+to_string(cost)+" gold coins.\n"); 
      return 1;
   }
      notify_fail(clerk+" tells you: \n"+
      "But, you dont have that "+arg+"\n"); 
      return 0;
}


int do_debug(string arg)
{
  mixed *arr;
  mixed *res;
  int i,sz;
  object ob;
  string name;
  int value;

  restore_object(save_file);

    if (!arg)
    {
        notify_fail("Debug whom ?\n");
        return 0;
    }
    else if (_tpr!=lower_case(arg) && _tp->query_level() < 33 
             && _tp!=this_object())
    {
        notify_fail("But you are not the owner of this box.\n");
        return 1;
    }
    else if (member(boxes,_tpr)!=1)
    {
        notify_fail("Sorry, but "+arg+" has not box.\n");
        return 0;
    }
    arr = boxes[arg];
    if (!intp(arr[0]))
        res = ({7});
     else 
        res = ({arr[0]});
    

    for (sz = sizeof(arr), i = 1; i < sz;i ++)
    {
        if (file_size(arr[i]+".c") > 0)
        {
            call_other(arr[i],"???");
            ob = find_object(arr[i]);
            if (!stringp(ob->query_name()))
                name = "dummy";
            else 
                name = ob->query_name();
            if (!intp(ob->query_value()))
                value = 1;
            else 
                value = ob->query_value();

            res = res + ({ name, arr[i], value });
        }
    }
   boxes = m_delete(boxes,lower_case(arg));
   boxes = boxes + ([lower_case(arg):res]);
   save_object(save_file);
   write("Ok.\n");
   return 1;
}
            
            

int do_remove(string arg)
{

      restore_object(save_file);
    if (arg!=_tpr)
    {
       boxes = m_delete(boxes,arg);
       write("Ok.\n");
       save_object(save_file);
       return 1;
    }
    write("You can't do that.\n");
  return 1;
}
int do_read(string arg)
{
    if (arg!="sign")              
       return 0;
    
    write("\n"+
    "You are in "+clerk+"'s box office. Here you can <store> your items.\n"+
    "You can type 'rent' and get a box for 1000 coins and the duration of\n"+
    "7 reboots. When you type rent again you get the box 7 reboots longer.\n"+
    "With the command 'store' 'itemname' you can store till 8 items. With\n"+
    "The command 'restore' 'itemname' you get your item again. To restore\n"+
    "your item you have to type the exact itemname, which you can get with\n"+
    "the command 'show'. Any storing of items costs extra, which you can \n"+
    "see with the command 'offer' 'itemname'. If your box has a bug, just\n"+
    "use the command 'debug' 'yourname'.\n\n"+
    "Please notice, that these boxes arn't sure of robbery. There is no\n"+
    "guarantee that you get your items back.\n");
    return 1;
}


int do_rent(string arg)
{
  mixed *cont;
  int time;

    if (arg!="box")   
        return 0;

    restore_object(save_file);

    if (sizeof(m_indices(boxes)) > 200)
    {
      notify_fail(clerk+" tells you: \n"+
      "Sorry, but there is no free box at the moment.\n");
      return 0;
    }
    else if (member(boxes,_tpr)==1)
    {
      if (_tp->query_money() >= 1000)
      {
          write(clerk+" tells you: \n"+
          "Ok, you can keep your box for 7 days longer.\n");
          cont = boxes[_tpr];
          time = cont[0] + 7;
          cont = cont - ({ cont[0] });
          cont = ({ time }) + cont;
          boxes = m_delete(boxes,_tpr);
          boxes = boxes + ([_tpr:cont]);
          _tp->add_money(-1000);
          save_object(save_file);
          return 1;
      }
         notify_fail(clerk+" tells you: \n"+
         "You already have a security box.\n");
         return 0;  
    } 
    else if (_tp->query_money() < 1000)
    {
      notify_fail(clerk+" tells you: \n"+
      "Sorry, but the rent of a box costs you "+to_string(cost)+" coins.\n");
      return 0;
    }
    tell_object(_tp,
      clerk+" tells you: \n"+
      "    Ok, you got your own box.\n");
      _tp->add_money(-1000);
      boxes = boxes + ([_tpr:({7})]); 
      save_object(save_file);
    return 1;
}

int do_store(string arg)
{
  object item;
  mixed *cont;
  string *file;
  int value;
  int cost;

    if (!arg) 
         return 0;

    restore_object(save_file);
    item = present(arg,_tp);

    if (member(boxes,_tpr)!=1)
    {
      notify_fail(clerk+" tells you: \n"+
      "Sorry, but first you have to rent a box.\n");
      return 0;
    }
    else if (!objectp(item)) 
    {
      notify_fail(clerk+" tells you: \n"+
      "Sorry, but you can't store something you don't have.\n");
      return 0;
    } 
     else if (explode(file_name(item),"/")[0]!="players" || 
              sizeof(explode(file_name(item),"#")) < 2 ||
              item->query_type()=="guild" ||
              !stringp(item->query_name()) || stringp(item->query_auto_load())
              || item->query_quest_item() || item->query_no_store())
    {
      notify_fail(clerk+" tells you: \n"+
      "Sorry, but I refuse to store that item.\n");
      return 0;
    } 
    else if (item->query_wielded() || item->query_worn())
    {
        notify_fail(clerk+" tells you: \n"+
        "Sorry, but i refuse to store wielded or worn things.\n");
        return 0;
    }
    else if (sizeof(boxes[_tpr]) >= 25)
    {
      notify_fail(clerk+" tells you: \n"+
      "Sorry, but your box is too small to store more than 8 items.\n");
      return 0;
    }
    cost = 10 + (item->query_value() * _fc) / 2;
    if (_tp->query_money() <  cost )
    {
       notify_fail(clerk+" tells you: \n"+
       "Sorry, but storing this item costs you "+  
       to_string(cost)+" extra coins.\n");
       return 0;
    }

    write("You pay "+to_string(cost)+
          " coins to "+clerk+".\n");
    _tp->add_money(-cost);
    write(clerk+" tells you: \n"+
      "Ok, I have stored your "+item->query_name()+".\n");
    file = explode(file_name(item),"#");
    if (!intp(item->query_value()))
         value = 1;
    else 
         value = item->query_value();
        
    cont = boxes[_tpr] + 
           ({ item->query_name(),file[0], value }); 
    boxes = m_delete(boxes,_tpr);
    boxes = boxes + ([_tpr:cont]);
    item->drop();
    destruct(item);
    save_object(save_file);
   return 1;
}

int do_restore(string arg)
{
  mixed *cont;
  mixed *res;
  int item;
  string name;
  string file;
  int value;
  int i,sz,j;
  object mob;

    restore_object(save_file);

    if (!arg)
    {
       notify_fail("Restore what ?\n");
       return 0;
    }
    if (member(boxes,_tpr)!=1)
    {
      notify_fail(clerk+" tells you: \n"+
      "Sorry, but don't have an own box.\n");
      return 0;
    }

   cont = boxes[_tpr];

   if ( (item = member_array(arg,cont))==-1 && !intp(arg) )
   {
      notify_fail(clerk+" tells you: \n"+
      "Sorry, but "+arg+" isn't stored in our box.\n");
      return 0;
   }
     call_other(cont[(item+1)],"???");
     mob =clone_object(cont[(item+1)]);

      if (file_size(cont[(item+1)]+".c") < 0)
     {
         write(clerk+" tells you: \n"+
         "Sorry, the "+arg+" was robbed, but I'll give you your money.\n");
         _tp->add_money(cont[(items+2)]/2);
         /* name file value */
         cont = cont - ({cont[item],cont[(item+1)],cont[(item+2)]});
         boxes = m_delete(boxes,_tpr);
         boxes = boxes + ([_tpr:cont]);
         save_object(save_file);
      return 1;
     }
     else if (transfer(mob,_tp) > 0)
     {
        notify_fail(clerk+" tells you: \n"+
        "Sorry, but you can't carry that much weight.\n");
        destruct(mob);
        return 0;
     }
      write(clerk+" gives you your "+arg+"\n");
      say(clerk+" gives "+arg+" to "+_tpn+"\n",_tp);
      sz = sizeof(cont);
      i = 1;
      j = 0;
      res = ({cont[0]});
      while( i < sz)
      {
         if (arg == cont[i] && j==0)
         {
             i = i + 3; 
             j = 1;
         }
         if (i < sz)
             res = res + ({ cont[i] });
         i++;
      }
      boxes = m_delete(boxes,_tpr);
      boxes = boxes + ([_tpr:res]);
      save_object(save_file);
   return 1;
 }
   
int do_show()
{
  int i,sz;
  mixed *cont;

    restore_object(save_file);
      
    if (member(boxes,_tpr)!=1)
    {
      notify_fail(clerk+" tells you: \n"+
      "Sorry, but don't have an own box.\n");
      return 0;
    }
    write("Your box contains:\n\n");
        
    cont = boxes[_tpr];

    for (sz = sizeof(cont), i = 1; i < sz; i = i + 3)
         write(cont[i]+"\n");
    write("\n\nRenttime: "+to_string(cont[0])+"\n");   
    save_object(save_file);
    return 1;
} 

    
int do_delete(string arg)
{
  mixed *arr;
  int num, money;

    restore_object(save_file);

    if (member(boxes,_tpr)!=1)
    {
      notify_fail(clerk+" tells you: \n"+
      "Sorry, but don't have an own box.\n");
      return 0;
    }
     arr = boxes[_tpr];

     if ( (num = member_array(arg,arr) )== -1)
     {
      notify_fail(clerk+" tells you: \n"+
      "Sorry,  don't have this item on my list.\n");
      return 0;
     }
      money = arr[(num + 2)]/2;

      arr = arr - ({ arr[num] , arr[(num + 1)], arr[(num + 2)] }); 
      boxes = m_delete(boxes,_tpr);
      boxes = boxes + ([_tpr:arr]);
      write(clerk+" tells you: \n"+
      "Ok,  I deleted "+arg+" from my list. Here you have your money back.\n");
      _tp->add_money(money);
      save_object(save_file);
    return 1;
}
         
       
