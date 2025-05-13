
/* --------------------------------------------------------------------
    The standard bank: 
    
inherit "/room/std_bank";

void reset(int flag) {

    ::reset(flag);
    if (flag) return;

    short_desc = "bank"   ect like a standard room
    clerk = "Franz";      
    save_file = "/players/whisky/broker"; the file where to save
    taxes = 0;
    items = ({
              "sign","There is something written on it" });
// If you want taxes.
    ::daily_taxes();
}
    ps: this file is stored under the file_name.o never delete it
        unless the players loose all thier money
------------------------------------------------------------------ */

#define tp this_player()
#define to this_object()
#define tpn tp->query_name()
#define tpr tp->query_real_name()
#define E environment
#define SAY(x) tell_room(to,x)

inherit "/room/room";

mapping accounts;
string clerk;
int taxes;
string save_file;

int load_info() {

    if (stringp(save_file) && file_size(save_file+".o") != -1 )
        restore_object(save_file);
}


void reset(int flag) {

    ::reset(flag);
    if (flag) return;

    accounts = ([]);
    clerk = "Testi";
    taxes = 0;
    save_file = "/players/whisky/BROKER"; 
    dest_dir =({});
}


void daily_taxes() {

    string *clients;
    int i, sz;
    int balance, help;

    clients = m_indices(accounts);

    for(sz = sizeof(clients),i = 0; i < sz; i++) {
         balance = accounts[clients[i]];
         help = balance * (100 - taxes) / 100;
         if ( (help + 10) > balance)
             balance = balance - 10;
         else 
             balance = help;
         accounts = m_delete(accounts,clients[i]);
         if (balance > 0)
             accounts = accounts + ([clients[i]:balance]);
    }
    save_object(save_file);
}

void init()
{
   ::init();
   add_action("do_deposit","deposit");
   add_action("do_withdraw","withdraw");
   add_action("do_balance","balance");
   add_action("do_show","show");
   add_action("do_read","read");
   add_action("do_set","set");
   if (stringp(save_file)) /* to be sure */
       save_object(save_file);
}

int do_set(string arg)
{
   string who, how_many;

    if (!arg || sscanf(arg,"%s %s",who,how_many) !=2 )   
    {
       notify_fail("set <who> <how many> ?\n");
       return 0;
    }
    else if (!tp->query_archwiz())
    { 
       notify_fail(
       "Only Archwizes are allowed to set the amount of a player.\n");
       return 0;
    }
    else if (!member(accounts,who))
    {
       notify_fail(
       who +" is no has no account here.\n");
       return 0;
    }
    else if (!intp(to_int(how_many)))
    {
       notify_fail("You have to give an integer as second argument.\n");
       return 0;
    }
    else 
    {
       accounts = m_delete(accounts,accounts[who]);
       accounts = accounts + ([who:to_int(how_many)]);
       save_object(save_file);
       write("Ok, "+who+"'s balance is now at "+how_many+" coins.\n");
    }
  return 1;
}
       
        
     
int do_read(string arg)
{
    if (arg != "sign") return 0;

    write("You are in "+clerk+"'s bank: Here you can 'deposit'<money>\n"+
          "or 'withdraw' <money>. If you have an account here you can\n"+
          "type 'balance' to see your statement. If you are new here\n"+
          "and want to deposit some money you will automatically get an\n"+
          "account. The daily taxes are "+to_string(taxes)+" percent, down "+
          "to a minimum\nof 10 coins per day.\n");
    if (tp->query_immortal())
        write("Wiz extra command: show or show <person>\n");
    if (tp->query_arch_wiz())
    {
        write("With set <player> <amount> you can set the balance of\n"+
              "a player.\n");
    }
   return 1;
}

int do_show(string arg)
{
int i, sz;
string *clients;

    restore_object(save_file);
    if(mappingp(accounts))
    clients = m_indices(accounts);

    if (!arg && tp->query_immortal())
    {
       printf("%-20s %-20s\n\n","Client:","Money:");

       for(sz = sizeof(clients),i = 0; i < sz; i++)
           printf("%-20s %-20s\n",clients[i],to_string(accounts[clients[i]]));
       return 1;
    }
    else if (tp->query_immortal())
    {
         if (member(accounts,arg))
            write(arg+" has "+to_string(accounts[arg])+" coins in our safe.\n");
         return 1;
    }
    write(clerk+" whispers to you: "+"Sorry, that's a bank secret.\n");
  return 1;
}
 
int do_deposit(string money)                              
{
int balance;

    if (!stringp(money)) 
         return 0;
    else if (m_sizeof(accounts) > 500 && member(accounts,tpr)!=1)
    {
       notify_fail(clerk+" whispers to you:\n     Sorry, but we can't "+
                   "accept more clients at the moment.\n");
       return 0;
    }
    else if ( intp(to_int(money)) )
    {
          if (to_int(money) < 10)
          {
              notify_fail(clerk+" whispers to you:\n     Sorry, but we only "+
                          "store money about 10 coins.\n");
              return 0;
          }
          else if (tp->query_money() < to_int(money))
          {
              notify_fail(clerk+" whispers to you:\n     Sorry, but you don't "+
                          "have that much money with you.\n");
              return 0;
          } 
          else
          {
             SAY(clerk +" says: Thank you "+tpn+
                 " we store it in our safe.\n");
             restore_object(save_file);
             tp->add_money(-to_int(money));
             if (mappingp(accounts) && member(accounts,tpr))
             {
                balance = accounts[tpr] + to_int(money);
                accounts = m_delete(accounts,accounts[tpr]); 
                accounts = accounts + ([tpr:balance]);
                save_object(save_file);
                return 1;
             }
             else 
             {
/*
                accounts =([]);
*/
                if(!mappingp(accounts)) { accounts = ([]) ; }
                accounts = accounts + ([tpr:to_int(money)]);
                save_object(save_file);
                return 1;
             } /* endif */
         } /* endif */
      } /* endif */
      else
       write(clerk+" shrugs helplessly.\n");
  return 1;
}
                 
                
int do_withdraw(string money)                              
{
int balance;

    if (!stringp(money)) 
         return 0;
    else if ( intp(to_int(money)) )
    {
          restore_object(save_file);
          if (to_int(money) < 1)
          {
              notify_fail(clerk+" whispers to you:\n     "+
                          "Hehe we don't do that.\n");
              return 0;
          }
          else if (!member(accounts,tpr))
          {
              notify_fail(clerk+" whispers to you:\n     Sorry, you don't"+
                          "have an account here or you ran out of taxes.\n");
              return 0;
          } 
          else if (accounts[tpr] < to_int(money))
          {
              notify_fail(clerk+" whispers to you:\n     Sorry, you only"+
                          " have "+to_string(accounts[tpr])+" coins left.\n");
              return 0;
          } 
          else
          {
                write(clerk+" gives you "+money+" coins.\n");
                say(clerk+" gives some money to "+tpn+"\n");
                tp->add_money(to_int(money));
                balance = accounts[tpr] - to_int(money);
                accounts = m_delete(accounts,accounts[tpr]); 
                accounts = accounts + ([tpr:balance]);
                save_object(save_file);
                return 1;
           }
   }
   else
      write(clerk+" shrugs helplessly.\n");
   return 1;
}
          
int do_balance()
{
    mapping dummy;
    string tprn;

    tprn = this_player()->query_real_name();

    restore_object(save_file);
    dummy = accounts;
    if(!mappingp(dummy)) return 1;
    if (member(dummy,tprn))
    {
      write(clerk+" whispers to you:\n     You have "+to_string(accounts[tpr])+
            " coins left.\n");
      return 1;
    }
      write(clerk+" whispers to you:\n     You don't have an account here, "+
            "or you ran out of taxes.\n"); 
    return 1;
}
              
    
    

