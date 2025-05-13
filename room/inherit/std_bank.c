/*--------------------------------------------------------------------*/
/* This is the standard bank to inherit if you wish to create a bank. */
/* Below is a sample of what needs to be in the file.                 */
/*                                                                    */
/*  inherit "/room/inherit/std_bank";                                 */
/*                                                                    */
/*  void reset(int flag) {                                            */
/*    ::reset(flag);                                                  */
/*    if(flag) return;                                                */
/*                                                                    */
/*    short_desc = "bank"  // like a standard room                    */
/*    clerk = "Franz";     // needed for the name. should be cap'ed   */
/*    save_file = "/players/mangla/broker"; // the file where to save */
/*                                          // the accounts           */
/*    taxes = 0;           // percentage of taxes to take out daily   */
/*    items = ({                                                      */
/*      "sign","There is something written on it"                     */
/*    });                                                             */
/*    ::daily_taxes();     // you must include this if you want the   */
/*                         // taxation to work                        */
/*  }                                                                 */
/*    ps: this file is stored under the file_name.o never delete it   */
/*        unless the players loose all thier money                    */
/*--------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  -------------------------------------------------
Jun 6 1997   Kryll        Redid this file a little to incorporate an unused 
                          player variable so that if the game crashes,
                          players won't lose their entire bank account.
*/

#define MAX_CLEAR_TIME  60
#include "/obj/lw.h"
#include "/sys/defs.h"

inherit "/room/room";

//prototypes
nomask status clear_accounts(string str);
void daily_taxes();
 
static status clear_flag;
private mapping accounts;
private int clear_time;
string clerk;
int taxes;
string save_file;

int load_info() {
  if(stringp(save_file) && file_size(save_file+".o") != -1)
    restore_object(save_file);
}

void reset(int flag) {
  ::reset(flag);
  if(flag) return;

  accounts = ([]);
  clerk = "Testi";
  taxes = 0;
  save_file = "/room/inherit/BROKER"; 
  dest_dir =({});
  clear_time = 0;
  clear_flag = 0;
}


void daily_taxes() {
  string *clients;
  int    i, sz, balance, help;

  if(taxes < 1) return;

  clients = m_indices(accounts);

  for(sz=sizeof(clients), i=0; i<sz; i++) {
    balance = accounts[clients[i]];
    help    = balance * (100 - taxes) / 100;
    if((help + 10) > balance)
      balance = balance - 10;
    else 
      balance = help;
    accounts = m_delete(accounts, clients[i]);
    if(balance > 0)
      accounts += ([clients[i]:balance]);
  }
  save_object(save_file);
}

void init() {
  ::init();
  add_action("do_deposit", "deposit");
  add_action("do_withdraw", "withdraw");
  add_action("do_balance", "balance");
  add_action("do_read", "read");

  if(TP && !TP->query_npc() && TP->IMM)
    add_action("do_show", "show");

  if(TP && !TP->query_npc() && TP->query_archwiz()) {
    add_action("do_set", "set_account");
    add_action("clear_accounts", "del_account");
  }

  if(stringp(save_file))
    save_object(save_file);

  if(!clear_flag) {
    clear_time++;
    clear_flag = 1;
    if(clear_time > MAX_CLEAR_TIME)
      clear_accounts("all");
  }
}

nomask status clear_accounts(string str) {
  mixed *contains;
  int   i, sz;

  restore_object(save_file);

  if(!mappingp(accounts)) {
    accounts = ([]);
    clear_time = 0;
    save_object(save_file);
    return 1;
  }

  if(!str) {
    notify_fail("Remove what?\n");
    return 0;
  }
  else if(str == "all" || str == "accounts") {
    contains = m_indices(accounts);
    for(i=0, sz=sizeof(contains); i<sz; i++)
      accounts = m_delete(accounts, contains[i]);
  }
  else {
    str = lower_case(str);
    if(member(accounts, str))
      accounts = m_delete(accounts, str);
  }
  if(TP && TP->query_archwiz())
    write("Ok, " + str + " was removed.\n");
  save_object(save_file);
  return 1;
}

status do_set(string arg) {
  string who, how_many;

  if(!arg || sscanf(arg, "%s %s", who, how_many) != 2) {
    notify_fail("set <who> <how many> ?\n");
    return 0;
  }
  else if(!TP->query_archwiz()) { 
    writelw("Only Archwizes are allowed to set the amount "+
            "of a player.\n");
    return 1;
  }
  else if(!member(accounts, who)) {
    writelw(who + " has no account here.\n");
    return 1;
  }
  else if(!intp(to_int(how_many))) {
    writelw("You have to give an integer as second argument.\n");
    return 1;
  }
  else {
    accounts = m_delete(accounts,accounts[who]);
    accounts += ([who:to_int(how_many)]);
    save_object(save_file);
    write("Ok, " + who + "'s balance is now at " + how_many + " coins.\n");
  }
  return 1;
}
       
status do_read(string str) {
  if(str != "sign") {
    notify_fail("Read what?\n");
    return 0;
  }

  writelw("You are in " + clerk + "'s bank: Here you can "+
          "'deposit <money>' or 'withdraw <money>'. If you have "+
          "an account here you can type 'balance' to see your "+
          "statement. If you are new here and want to deposit "+
          "some money, an account will be automatically created for you.\n");
  if(taxes)
    writelw("The daily taxes are " + to_string(taxes) + " percent, down "+
            "to a minimum of 10 coins per day.\n");
  if(TP->IMM)
    write("Wiz extra command: 'show' or 'show <person>'\n");
  if(TP->query_archwiz()) {
    writelw("'set_account <player> <amount>' allows setting the balance of "+
            "a player's account.\n");
    writelw("'del_account all' or 'del_account <player>' will "+
            "remove all accounts or a single player's account "+
            "respectively.\n");
  }
  return 1;
}

// shows wizzes who has an account in the bank based on their records
status do_show(string str) {
  int    i, sz;
  string *clients;

  restore_object(save_file);
  if(mappingp(accounts))
    clients = m_indices(accounts);
  else
    accounts = ([]);

  if(!TP->IMM) {
    writelw(clerk + " whispers to you: Sorry, that's a bank secret.\n");
    return 1;
  }

  if(!str) {
    printf("%-20s %-20s\n", "Client", "Money");
    printf("%-20s %-20s\n", "--------------------", "--------------------");

    for(sz=sizeof(clients), i=0; i<sz; i++)
      printf("%-20s %-20s\n", clients[i], to_string(accounts[clients[i]]));
    if(!sz)
      printf("None\n");
  }
  else if(member(accounts, str))
    writelw(CAP(str) + " has " + to_string(accounts[str]) +
          " coins in our safe.\n");
  else
    write(CAP(str) + " does not have an acount with us.\n");
  return 1;
}
 
// to deposit money into your own bank account
status do_deposit(string str) {
  int balance, money, pl_bal, tprn;

  tprn = TP->RNAME;
  if(!stringp(str)) {
    notify_fail("Deposit what?\n");
    return 0;
  }

  if(!mappingp(accounts))
    accounts = ([]);

  if(m_sizeof(accounts) > 500 && member(accounts, tprn) != 1) {
    if((pl_bal = TP->query_balance()) > 0) {
      writelw(clerk + " says to you: Sorry, but due to the amount of "+
              "business we've had, we had to move your account to "+
              "a different bank.\n");
      return 1;
    }
    writelw(clerk + " whispers to you: Sorry, but we can't " +
            "accept any more clients at the moment.\n");
    return 1;
  }
  else if(intp(money = to_int(str))) {
    if(money < 500) {
      writelw(clerk + " whispers to you: Sorry, but we only "+
              "store amounts greater than 500 coins.\n");
      return 1;
    }
    else if(TP->query_money() < money) {
      writelw(clerk + " whispers to you: Sorry, but you don't "+
              "have that much money with you.\n");
      return 1;
    } 
    else {
      TELLR(TO, clerk + " says: Thank you " + TP->NAME +
            ", we will store it in our safe.\n");
      restore_object(save_file);
      TP->add_money(-money);  // Airborne: 06.08.97
      TP->add_balance(money);
      pl_bal = TP->query_balance();
      if(mappingp(accounts) && member(accounts, tprn)) {
        balance   = accounts[tprn] + money;
        if(pl_bal != balance)
          TP->set_balance(balance);
        accounts  = m_delete(accounts,accounts[tprn]); 
        accounts += ([tprn:balance]);
        save_object(save_file);
        return 1;
      }
      else {
        accounts += ([tprn:money]);
        if(pl_bal > money && pl_bal != accounts[tprn])
          accounts[tprn] = pl_bal;
        save_object(save_file);
        return 1;
      } /* endif */
    } /* endif */
  } /* endif */
  else {
    notify_fail(clerk + " shrugs helplessly.\n");
    return 0;
  }
  return 1;
}

// to withdraw money from your own bank account
status do_withdraw(string str) {
  int balance, money, pl_bal, tprn;

  if(!stringp(str)) {
    notify_fail("Withdraw what?\n");
    return 0;
  }

  if(!mappingp(accounts)) 
    accounts = ([]);

  if(intp(money = to_int(str))) {
    restore_object(save_file);
    if(money < 1) {
      writelw(clerk + " whispers to you: We do not do that.\n");
      return 1;
    }

    tprn = TP->RNAME;
    pl_bal = TP->query_balance();
    if(!member(accounts, tprn)) {
      if(pl_bal > 0) {
        if(m_sizeof(accounts) < 500) {
          if(!mappingp(accounts)) {
            accounts = ([]);
          }
          accounts += ([tprn:pl_bal]);
          save_object(save_file);
          restore_object(save_file);
        }
        else {
          writelw(clerk + " says to you: Sorry, but due to our "+
                  "booming business we had to move your account "+
                  "to another bank.\n");
          return 1;
        }
      }
      else {
        writelw(clerk + " whispers to you: Sorry, you do not "+
                "have an account here.\n");
        return 1;
      }
    } 

// check to see if the player's bank balance is equivalent to the
// banks. if not, then the bank is right.
    if(pl_bal != accounts[tprn])
      TP->set_balance(accounts[tprn]);

// check to see if there enough money in the account
    if(accounts[tprn] < money) {
      writelw(clerk + " whispers to you: Sorry, you only" +
              " have " + to_string(accounts[tprn]) + " coins left.\n");
      return 1;
    } 
    else {
      write(clerk + " gives you " + money + " coins.\n");
      say(clerk + " gives some money to " + TP->NAME + ".\n");
      TP->add_money(money);
      TP->add_balance(-money);
      balance   = accounts[tprn] - money;
      accounts  = m_delete(accounts, accounts[tprn]); 
      accounts += ([tprn:balance]);
      save_object(save_file);
      return 1;
    }
  }
  notify_fail(clerk + " shrugs helplessly.\n");
  return 0;
}

// to see your bank account
status do_balance() {
#if 0
  mapping dummy;

  restore_object(save_file);
  dummy = accounts;
  if(!mappingp(dummy)) return 1;
  if(member(dummy, TP->RNAME)) {
    writelw(clerk + " whispers to you: You have " +
            to_string(accounts[TP->RNAME]) + " coins left.\n");
#else
  if(TP->query_balance() > 0) {
    writelw(clerk + " whispers to you: You have " +
            to_string(TP->query_balance()) + " coins left.\n");
#endif
    return 1;
  }
  writelw(clerk + " whispers to you: You don't have an account here, "+
          "or you ran out of taxes.\n"); 
  return 1;
}

