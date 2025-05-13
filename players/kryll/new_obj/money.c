/*-------------------------------------------------------------------------*/
/* FILE : money.c                                                          */
/*                                                                         */
/* Description : This is the inheritable file for money.                   */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Mar 14 1997  Kryll        Cleaned up this file. Removed extraneous comments,
                          added full USERDOCs.
 
*/

#include "/obj/obj_defs.h"

#pragma strict_types

int money;
mixed *amount_array;

/* PROTOTYPES */
void reset(int arg);
int query_weight();
string short();
string query_name();
void long();
nomask string query_amount_string();
mixed *get_amount_array();
int count(string str);
void init();
int get();
void set_money(int val);
int id(string str);
void dest_mon();


void reset(int arg) {
  if(arg) return;
  money = 1;
}

int query_weight() {
  return 0;
}

string short() {
  if(money == 0)
    return 0;
  if(money == 1)
    return "One gold coin";
  return (query_amount_string()+"gold coins");
}

string query_name() {
  return short();
}

void long() {
  write(short()+".\n");
}

nomask string query_amount_string() {
  int i, sz;

  if(!pointerp(amount_array))
    amount_array = get_amount_array();

  for(sz=sizeof(amount_array)/2, i=0; i<sz; i++) {
    if(money <= amount_array[i*2])
      return amount_array[i*2+1];
  }
  return "Mountains of ";
}

mixed *get_amount_array() {
#if 0
  if(file_name(TO) == "obj/money")
#endif
    return ({ 2, "Two ",
              4, "Very few ",
              6, "A few ",
              10, "Some ",
              15, "Quite some ",
              25, "A score of ",
              40, "A lot of ",
              60, "Many ",
              100, "A small pile of ",
              150, "A pile of ",
              250, "A large pile of ",
              400, "A small heap of ",
              600, "A heap of ",
              1000, "A large heap of ",
              1500, "A small treasure of ",
              2500, "A treasure of ",
              4000, "A large treasure of ",
              6000, "A huge treasure of "
    });
#if 0
  else
    return ("obj/money"->get_amount_array());
#endif
}

int count(string str) {
  if(!id(str))
    return 0;
  write("There are "+money+" coins.\n");
  return 1;
}

/*
 * If we are picked up by a player, then move the money to his "purse",
 * and destruct this object.
*/
void init() {
  if(ENV(TO) == TP) {
    count("money");
    TP->add_money(money);
    money = 0;
    call_out("dest_mon",1); 
  }
  else {
    add_action("count","count");
  }
}

int get() {
  return money>0;
}

/* USERDOC:
set_money
Function  : set_money(i)
Examples  : set_money(10)

This function sets the amount of money this particular pile of money is worth.
*/
void set_money(int val) {
  money = val;
}

int id(string str) {
  return (str=="coins" || str=="money" || str=="gold coins");
}

void dest_mon() {
  if(money < 1)
    destruct(TO);
}

