/*--------------------------------------------------------------
  filename: shop.c  last edit: 5.2. whisky uni-linz.ac.at
  Just inherit this file. You can then set extra fol. variables:
  type =  (trader | smithy | armoury) ps: smity only buys weapons
  store = the roomfile you like to use as store. default: room/store
  maxlist = how many items the shop has in it's list: so 20 is ok    
  keeper =  Its the name of the shopkeeper you like for your shop.
  examples: ~whisky/seaworld/room/sw_shop.c and sw_store.c
 -------------------------------------------------------------- */

#define tp       this_player()
#define tpn      this_player()->query_name();
#define MAXVAL   1000

inherit "/room/room";

/* prototyping */
public int    sell_fcn(object sob,object player,int i);
public int    check_transfer(object sob,object player);
string        query_type();
object        query_store();
public int    player_buy(object player, object ob);
public nomask int check_value(object pob, object player);
int           clear_up();

string        store, type, keeper;
int           maxlist;
mixed         *list;
string        *names;

void reset(int arg) {

  ::reset(arg);

  if(arg) return;

  list       = ({});
  names      = ({});
/*
  short_desc = "shop";
  long_desc  = "shop.\n";
*/
  store      = "/room/room";
  set_light(1);
  type       = "trader";
  keeper     = "Franz";
  maxlist    = 20;
}
  

/*--------------------------------------------------------------
   Function: unique_string
   Returns: an array of string of unique objects
   Usage: for the list command of the player
  -------------------------------------------------------------- */

string *unique_list(object *obj_arr, string separator) {

  mixed *nobj_arr;
  mixed *mix_arr;
  int i, num;

  nobj_arr = unique_array(obj_arr, separator);

  mix_arr=({ });
  for(i=0;i<sizeof(nobj_arr);i++) {
    num=sizeof(nobj_arr[i]);
    mix_arr+=({ ({i,                         /* index */
                  num,                        /* how many */
                  (string)nobj_arr[i][0]->query_name(),
                  nobj_arr[i][0] })            /* object */
                });
  }
  return mix_arr;
}

init() {

  add_action("get_list","list");
  add_action("buy_object","buy");
  add_action("do_sell","sell");
  add_action("do_value","value");
  ::init();
}

/*--------------------------------------------------------------
   Function: get_list
   Usage:  lists all items available in the store
  -------------------------------------------------------------- */

public int get_list(string arg) {

  int i,max;
  object ob;
  string size;

  if(!sizeof(all_inventory(query_store()))) {
    write("Sorry, but the store is empty.\n");
    return 1;
  }
  list = unique_list(all_inventory(query_store()),"query_name");

  if(sizeof(list) > maxlist)
    max = maxlist;
  else 
    max = sizeof(list);
  
  printf("%-8s%-20s%-30s%-8s%-6s\n", "Num:", "Store:", "Name:", "Size:", "Value:");
  for(i=0;i<max;i++) {
    switch(list[i][3]->query_size()) {
    case 1: size = "Tiny"; break;
    case 2: size = "Small"; break;
    case 3: size = "Medium"; break;
    case 4: size = "Large"; break;
    case 5: size = "XLarge"; break;
    default: size = "Any"; break;
    }
    printf("#%-7i%-20i%-30s%-8s%-6i\n",
           (list[i][0]+1),list[i][1],list[i][2],
           size, (list[i][3]->query_value()*2));
    names += ({ list[i][2] });
  }
  write( "Commands: buy <num>, buy <item>, sell <item>, " +
                   "sell <all>, value <item>.\n");
  return 1;
}

/*--------------------------------------------------------------
   Function: buy_object
   Usage: if the player wants to buy something
  -------------------------------------------------------------- */

public int buy_object(string arg) {

  object ob;
  int i,x;

  if(!arg) return 0;

  if(!sizeof(list)) {
   list = unique_list(all_inventory(query_store()),"query_name");
   for( i = 0;i<sizeof(list);i++) {
     names += ({ list[i][2] });
   }
  }

  if(x = to_int(arg)) {
    if(x && x <= sizeof(list) ) {
      ob = list[(x-1)][3];
      player_buy(tp,ob);
    } 
  }
  else if (ob = present(arg,query_store())) {
    player_buy(tp,ob);
  }
  else {
    write("No such item in the store.\n"); 
  }
  return 1;
}

/*--------------------------------------------------------------
   Function: player_buy
   Usage:  checking if the transfer is ok 
  -------------------------------------------------------------- */

public int player_buy(object player,object ob) {

  if (player->query_money() < ob->query_value()*2)
    write(keeper+" tells you: Sorry you need more money.\n");   
  else if (transfer(ob,player))
    write(keeper+" tells you: Sorry you can't carry that weight.\n"); 
  else {
    write(keeper+" gives you "+ob->short()+" for "+(ob->query_value()*2)+
                 " coins.\n");
    player->add_money(- (ob->query_value()*2));
    list = unique_list(all_inventory(query_store()),"query_name");
  }
  return 1;
}

/*--------------------------------------------------------------
   Function: do_value
   Usage: prints out the value of a present object in this_player
  -------------------------------------------------------------- */

public nomask int do_value(string what) {

  object pob;
  int amo;

  if (!what)
    return 0;
  else if (pob=present(what,tp)) {
    amo=check_value(pob,tp);
    write(keeper+" tells you: I guess it's worth "+amo+" gold coins.\n");
    return 1;
  }  
  write(keeper+" tells you: You don't have that item.\n");
  return 1;
}

/*--------------------------------------------------------------
   Function: check_value
   Usage: calculates the value a player gets for her item
  -------------------------------------------------------------- */

public nomask int check_value(object pob,object player) {

  int val,mval;

  val = (pob->query_value()*2);
   
  if(!val)
    return 0;
  else if(val > MAXVAL)
    mval = 1000;
  else if(val <= 100)
    mval = 1+val/2; 
  else 
    mval = val/3 + val/60 * player->query_chr();
  return mval;
}

/* --------------------------------------------------------------
   Function: do_sell
   Usage: when the player wants to sell something
  -------------------------------------------------------------- */

public nomask int  do_sell(string what) {

  object *inv;
  int i;

  if (!what)
    return 0;
  else if (what=="all") {
    inv = all_inventory(tp);
    for (i=0;i<sizeof(inv);i++)
      if (!inv[i]->query_worn() && !inv[i]->query_wielded()
                                && !inv[i]->query_autoload())
        sell_fcn(inv[i],tp,0);
  }
  else if (!present(what,tp))
    write(keeper+" tells you: You don't have that item.\n");
  else 
    sell_fcn(present(what,tp),tp,1);
  return 1;
}
        
public int sell_fcn(object sob,object player,int i) {

  switch(query_type()) {
    case"armourer":    
      if(!sob->query_armour()) {
        if(i)
          player->catch_tell(keeper+" tells you: I only buy armours.\n");
      }
      else 
        check_transfer(sob,player);
      break;
    case "smithy":
      if(!sob->query_weapon()) {
        if(i)
          player->catch_tell(keeper+" tells you: I only buy weapons.\n");
      }
      else 
        check_transfer(sob,player);
      break;
    default:
      check_transfer(sob,player);
      break;
  }
  return 1;
}
      

/*--------------------------------------------------------------
   Function: check_transfer
   Usage: checks if the player can sell the item
  -------------------------------------------------------------- */

public int check_transfer(object sob,object player) {

  int money;

  if(player->query_ghost())
    write(keeper+" tells you: I don't trade with ghosts.\n");
  else if(!sob->query_value())
    write(keeper+" tells you: I don't buy worthless items.\n");
  else if(transfer(sob,query_store()))
    write(keeper+" tells you: I don't manage to get your item.\n");
  else {
    if(sob->query_name()) {
      write(keeper+" buys your "+sob->query_name()+" for "+
      check_value(sob,player)+" coins.\n");
      say(player->query_name()+" sells "+player->query_possessive()+
          " "+sob->query_name()+".\n",player);
      money = check_value(sob,player);
    }
    else {
      write(keeper+" tells you: I don't need that item, try another shop.\n");
      return 1;
    }
    player->add_money(money);
    call_out("clear_up",1);
  }
  return 1;
}
   
/*--------------------------------------------------------------
   Function: query_type
   Usage: returns the type of the shop def: trader, armourer, smithy
  -------------------------------------------------------------- */
string query_type() {
  return type;
}

/* --------------------------------------------------------------
   Function: query_keeper
   Usage: returns the name of the shopkeeper
  -------------------------------------------------------------- */

string query_keeper() {
  return keeper;
}

/* --------------------------------------------------------------
   Function:  query_maxlist
   Usage: returns how many items the shop can store
  -------------------------------------------------------------- */

int query_maxlist() {
  return maxlist;
}

/* --------------------------------------------------------------
   Function: query_store
   Usage: returns and sets a store if needed
  -------------------------------------------------------------- */

object query_store() {

  object this_store;

  call_other(store,"???");
  if(!find_object(store))
    this_store = find_object("/room/store"); 
   else 
    this_store = find_object(store);

  return this_store;
}
  
/*--------------------------------------------------------------
   Function: clear_up 
   Usage: destructs items in the store, when the list is full  
  -------------------------------------------------------------- */
  
int clear_up() {

  object *items;
  int i;

  if(items = all_inventory(query_store()) ) {
    if(sizeof(items) > maxlist) {
      for(i=0;i<sizeof(items);i++) {
        if(random(2) && !items[i]->no_clear())
          destruct(items[i]);
      }
    }
  }
  return 1;
}
