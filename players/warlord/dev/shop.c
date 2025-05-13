/* SHOP.C - Programmed by Herp */
/* 231092: Moonchild: Value modified */
/* 150993: Ethereal Cashimor: Weight bug fixed */
/* 170993: Ethereal Cashimor: Userdocs added */

/* USERDOC:
general
This file is used to make shops without bugs. If you inherit this file, your
shop will always be rather up to date. A shop acts like an ordinary room, but
also has some special functions, as well as some generally defined functions:
set_short, set_long.
*/

#define TP	this_player()
#define TO	this_object()

inherit "room/room";
object store_room;
string store_exit;

reset(arg) { ::reset(arg); }

init() {
  ::init();
  add_action("list","list");
  add_action("buy","buy");
  add_action("sell","sell");
  add_action("value","value");
  add_action("move","move");
}

set_short(str) { short_desc=str; }
set_long(str) { long_desc=str; }

/* USERDOC:
set_store_room
Format: set_store_room(s)
Example: set_store_room("room/store")
See also: set_store_exit.
This function sets the store room to use. Don't use a store room from another
shop, unless they are close and actually CAN share a store room. The store room
is the place where all objects of the shop are stored.
*/
set_store_room(ob) {
  store_room=ob;
  log_file("SHOPS",file_name(this_object())+" : "+ ob+"\n");
}

/* USERDOC:
set_exits
Format: set_exits(s)
Example: set_exits(({"room/vill_road2","south"}))
This function behaves just like dest_dir=s. In fact, it is entirely
superfluous.
*/
set_exits(str) { 
  dest_dir=str; 
}

/* USERDOC:
set_store_exit
Format: set_store_exit(s)
Example: set_store_exit("north")
See also: set_store_room.
This function sets the direction of the store room. Players usually can't enter
the store room, but wizards should be able to.
*/
set_store_exit(str) { store_exit=str; }

move(str) {
  if (!str) str=query_verb();
  if (str==store_exit) {
     if (!TP->query_wizard()) {
	write("A strong magic force stops you.\n");
	say(TP->query_name()+" tries to go through the field but fails.\n");
	return 1;
    }
    write("You wriggle through the force field ...\n");
    TP->move_player(str,store_room);
    return 1;
  }
  return ::move(str);
}

list(str) {
  store_room->inventory(str);
  return 1;
}

buy(str) {
  if (!str) return;
  if (TP->query_ghost()) {
     write("You have no body to carry items with you.\n");
     return 1;
  }
  store_room->buy(str);
  return 1;
}

sell(str) {
object ob,*in;
int i,do_destroy;
  
  if (!str) return;
  if (str=="all") {
     in=all_inventory(TP);
     for (i=0;i<sizeof(in);i++)
	if (!in[i]->drop() && in[i]->query_value()) do_sell(in[i]);
     write("Ok.\n");
     return 1;
  }
  if (!(ob=present(str,TP)) && !(ob=present(str,TO))) {
     write("No such item ("+str+") here.\n");
     return 1;
  }
  do_sell(ob);
  return 1;
}

do_sell(ob) {
int value,do_destroy;

  if (!(value=ob->query_value())) {
     write(ob->short()+" has no value.\n");
     return 1;
  }
  if (value>2600 || ob->query_quest_item()) do_destroy=1;
  if (environment(ob)==TP) {
     int weight;
     if (ob->drop()) {
	write("I can't take it from you.\n");
	return 1;
     }
     weight=ob->query_weight();
     if(!do_destroy) TP->add_weight(-weight);
  }
   if (value>2600){
     write("The shop is low on money ...\n");
     value=(1000 + (TP->query_chr() *40));
  }
  write("You get "+value+" gold coins.\n");
  say(TP->query_name()+" sells "+ob->short()+".\n");
  TP->add_money(value);
#if 0
  add_worth(value,ob);
#endif
  if (do_destroy) {
     write("The valuable item is hidden away.\n");
     destruct(ob);
     return 1;
  }
  store_room->store(ob);
  return 1;
}

value(str) {
object ob;
int i,z;

  if (!str) return;
  z=0;
  if (!(ob=present(str,TP)) && !(ob=present(str,TO))) z=1;
  if (z && !(ob=present(str,find_object(store_room)))) {
     write("No such item ("+str+") here or in the store.\n");
     return 1;
  }
  if (z) {
	write("The " + ob->short() + " would cost you " + ob->query_value() * 2
	+ " gold coins.\n");
	return 1;
  }
  if (!(i=ob->query_value())) {
     write(ob->short()+" has no value.\n");
     return 1;
  }
  write("You would get "+i+" gold coins.\n");
  return 1;
}

query_drop_caste() { return 1; } 








