/*
 * Author : Uglymouth
 * Date   : 10-AUG-1993
 */
#include "path.h"
#define  TP     this_player()
#define  TPQN   (string)TP->query_name()
#define  TPSE   TP->setenv
#define  TPQE   TP->queryenv
#define  TPQM   (int)TP->query_money()

inherit "room/room";
int interest;
string checked_account;

void reset(int arg) {
  
  interest = 2 - random(10);
  checked_account = 0;
  tell_room(this_object(),"A clerk comes running in, waving with a long list.\n"
      + "The clerk says: The latest results of our investments have come in.\n");
  if(arg) return;

  set_light(1);
  short_desc = "The 'Forest Investers Co-operation'";
  long_desc = "You have entered the office of the 'Forest Investers Co-operation'.\n"
        + "The FICO offers banking services to the inhabitants of this\n"
        + "village and any interested outsider with some money in his\n"
        + "pockets. Over the reinforced counter, you see the big vault\n"
        + "where the bank stores its clients' money. Bank clerks are\n"
        + "coming and going to process every client's orders to the\n"
        + "bank's best ability. A small plaque hangs over the counter.\n";
  dest_dir = ({ PATH+"road2","south" });
  items = ({"office","The FICO is housed in a fancy stone building",
        "building","It is built to look like a big, stone treasure chest",
        "counter","A marble counter with barred windows",
        "windows","Through the windows you can see the vault",
        "vault","A strong iron vault, built into the wall of the bank",
        "clerks","Overly active and too precise clerks, checking it all at least three times",
        "plaque","A gold plaque, engraved with the words: Type 'help bank' for more info",
        });
  property = ({ "no_steal" });
  smell = "You are overwhelmed by the dirty smell of money, money, money...\n";
  checked_account = "dummy";
  }

void init() {
  ::init();
  add_action("help_bank","help");
  add_action("open_account","open");
  add_action("close_account","close");
  add_action("read_balance","balance");
  add_action("do_deposit","deposit");
  add_action("do_withdraw","withdraw");
  add_action("do_invest","invest");
  add_action("show_interest","interest");
  add_action("show_userlist","userlist");
  }

int help_bank(string str) {
  if(str!="bank") return 0;
  write("A clerk hurries to you and puts a thick leather book on the counter.\n"
      + "He opens it at the chapter 'General Information on Banking'. It reads:\n\n");
  if(TP->query_immortal())
    write("   Wizinfo: This bank holds the following wizard commands...\n"
        + "     'interest' - shows the current interest percentage,\n"
        + "     'userlist' - gives list of players logged in and their balance.\n\n");
  TP->more( PATH+"bank.doc");
  return 1;
  }

int open_account(string str) {
int has_account;  
string name,time,lasttime,nowtime,*list,*monlist,lmon,nmon;  
int i,lmonnr,nmonnr,lyr,nyr;
mixed junk;
  if(str!="account") return 0;
  has_account = (int)TPQE("FICO-BALANCE");
  
  if(has_account) {
    write("A clerk opens a thick leather book. He checks, and checks, and checks again.\n"
        + "The clerk says: You already have an account here.\n" 
        + "    We can allow only one account per person.\n");
    return 1;
    }
  
  if(TPQM < 600) {
    write("The clerk tells you: we require an initial fee of 500 coins,\n"
        + "    and a minimal balance of 100 gold coins. It seems that\n"
        + "    you don't have that much money. Good day!\n");
    return 1;
    }

  /* now open the account */
  TPSE("FICO-BALANCE", 100);
  TP->add_money(-600);
/*
  log_file("FICO",ctime(time()) +" open account: " + TP->query_real_name() + "\n");
*/
  write("The clerk starts writing in one of the bank's thick leather books.\n"
      + "Then he takes the initial fee plus 100 coins from you and puts it safely\n"
      + "in the vault. The clerk says: Welcome to our bank, " + TPQN + ".\n");
  say(TPQN + " opens an account.\n");
  return 1;
  }

int close_account(string str) {
int amount;
  if(str!="account") return 0;
  amount = (int)TPQE("FICO-BALANCE");

  if(!amount) {
    write("A clerk opens a thick leather book. He checks, and checks, and checks again.\n"
        + "The clerk tells you: You don't have an account here, so don't waste my time.\n");
    return 1;
    }

  TP->unsetenv("FICO-BALANCE");
  TP->add_money(amount);
  log_file("FICO.CLOSE",ctime(time()) +" close account: " + amount +" "+ TP->query_real_name() + "\n");
  write("The clerk opens a thick leather book and a red pencil and marks the\n"
      + "page with your account on it with a big cross. The clerk sighs sadly.\n"
      + "The clerk tells you: Your account is closed...\n");
  say(TPQN + " closes " + TP->query_possessive() + " account at this bank.\n");
  return 1;
  }

int read_balance() {
int amount,comp;
  amount = (int)TPQE("FICO-BALANCE");

  if(!amount) {
    write("A clerk opens a thick leather book. He checks, and checks, and checks again.\n"
        + "The clerk tells you: You don't have an account here, so don't waste my time.\n");
    return 1;
    }

  write("A clerk opens a thick leather book. He checks, and checks, and checks again.\n"
      + "The clerk looks up and tells you: Your current balance at our bank amounts\n"
      + "    to: " + amount + " gold coins. But of course this amount still has to be\n"
      + "    modified for interest.\n");
  if(amount < 100 && TPQM >= 100) {
    comp = 100 - amount;
    TPSE("FICO-BALANCE", 100);
    TP->add_money( -comp );
    write("The clerk says surprisedly: Hey, your balance is below the minimum!\n"
        + "The clerk takes some of your money to update your balance.\n");
    }
  say(TPQN + " asks a clerk after " + TP->query_possessive() + " balance.\n");
  return 1;
  }

int do_deposit(string str) {
int amount,i;
  amount = (int)TPQE("FICO-BALANCE");

  if(!amount) {
    write("A clerk opens a thick leather book. He checks, and checks, and checks again.\n"
        + "The clerk tells you: You don't have an account here, so don't waste my time.\n");
    return 1;
    }

  if(!str) return 0;
  if(sscanf(str,"%d coin",i)!=1 || sscanf(str,"%d coins",i)!=1) {
    write("Please type 'deposit <x> coins' (or 1 coin).\n");
    return 1;
    }

  if(i < 1) {
    write("A clerk politely explains to you that you cannot deposit negative\n"
      + "amounts of money.\n");
    return 1;
    }

  if((int)TPQM < i) {
    write("The clerk looks at your purse with an almost insulting sneer.\n"
        + "The clerk tells you: You don't have that much money. Good day!\n");
    return 1;
    }

  /* now do the deposit */
  amount += i;
  TPSE("FICO-BALANCE", amount);
  TP->add_money( -i );                            
  log_file("FICO",ctime(time()) +" deposit: " + i +" "+ TP->query_real_name() + " balance: " + amount + "\n");
  write("A clerk takes your money and puts it safely into the vault.\n"
      + "The clerk takes a thick leather book and starts writing.\n"
      + "After a while the clerk says: " + i + " Gold coins added to your\n"
      + "    account. You now have " + amount + " gold coins invested here.\n");
  say(TPQN + " deposits some money.\n");
  return 1;
  }

int do_withdraw(string str) {
int amount,i;
string fortune;  
  amount = (int)TPQE("FICO-BALANCE");

  if(!amount) {
    write("A clerk opens a thick leather book. He checks, and checks, and checks again.\n"
        + "The clerk tells you: You don't have an account here, so don't waste my time.\n");
    return 1;
    }

  if(!str) return 0;
  if(sscanf(str,"%d coin",i)!=1 || sscanf(str,"%d coins",i)!=1) {
    write("Please type 'withdraw <x> coins' (or 1 coin).\n");
    return 1;
    }

  if(i < 1) {
    write("A clerk politely explains to you that you cannot withdraw negative\n"
      + "amounts of money.\n");
    return 1;
    }

  if(amount < i) {
    write("The clerk opens a thick leather book. He checks, and checks and checks again.\n"
        + "The clerk tells you: You don't have that much money invested here, and we\n"
        + "    do NOT give out loans. Good day!\n");
    return 1;
    }

  /* calculate interest to bay payed (up to 7%) or gained 
     (up to 2%) by the player */
  amount = (amount * (interest + 100)) / 100;
  if(amount - i < 100) {
    write("A clerk takes a long list. He checks, and checks and checks again.\n" 
      + "The clerk says: If you withdraw this amount of money, your balance,\n"
      + "    modified for interest, would drop below the minimum. Please\n"
      + "    withdraw a smaller amount.\n");
    return 1;
    }

  /* now do the withdrawal and update the account by interest */
  amount -= i;
  TPSE("FICO-BALANCE", amount);
  TP->add_money( i );                             
  log_file("FICO",ctime(time()) +" withdraw: " + i +" "+ TP->query_real_name() + " balance: " + amount + "\n");
  write("The clerk takes your money from the vault and gives it to you.\n"
      + "The clerk takes a thick leather book and starts writing.\n"
      + "After a while the clerk says: " + i + " Gold coins subtracted from\n"
      + "    your account. You now have " + amount + " gold coins invested here.\n");
/*
  if(member_array((string)TP->query_real_name(),checked_account) == -1) {
    fortune = "lost";
    if(interest == 0) fortune = "gained nor lost";
    if(interest  > 0) fortune = "gained"; 
    write("    Due to the current situation on the investment market, you have\n"
        + "    " + fortune + " money on your balance.\n");
    checked_account[sizeof(checked_account)] = TP->query_real_name();
    }
*/
  say(TPQN + " withdraws some money.\n");
  return 1;
  }

int do_invest() {
  write("The office for investments is closed at the moment.\n" 
      + "Please try again some other day.\n");
  return 1;
  }

int show_interest() {
  if(!TP->query_immortal()) return 0;
  write("A clerk shows you a thick leather book with the banks interest figures.\n"
      + "You read that at this moment the interest is " + interest + " percent.\n");
  return 1;
  }

int show_userlist() {
object *u;  
int i,amount;
  if(!TP->query_immortal()) return 0;
  u = users();
  for(i=0;i<sizeof(u);i++) {
    if(u[i]->query_invis() < TP->query_level() && u[i] != TP) {
      amount = u[i]->queryenv("FICO-BALANCE");
      if(!amount) write(u[i]->query_short_name() + " has no account here.\n");
      else
      write(u[i]->query_short_name() + " has " + amount + " gold coins on "
          + u[i]->query_possessive() + " account.\n");
      }
    }
  return 1;
  }

