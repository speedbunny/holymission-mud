/* mud@alijku05.edvz.uni-linz.ac.at Herp (Herbert Rosmanith) */

/* shop.c ... inheritance for shops
 *
 * set_short
 * set_long
 * set_store_room
 * set_store_exit
 * set_exits
 *
 */

#define TP	this_player()
#define TO	this_object()

inherit "players/qclxxiv/myroom";
object store_room;
string store_exit;

/* buy_result:  -2, -1, 0, 1 on : too expensive, too heavy, not present, ok*/
int buy_result;
int bought;
query_bought() { return bought; }

reset(arg) { ::reset(arg); }

init() {
  ::init();
  add_action("list","list");
  add_action("buy","buy");
  add_action("sell","sell");
  add_action("value","value");
  add_action("move",store_exit);
}

set_short(str) { short_desc=str; }
set_long(str) { long_desc=str; }
set_store_room(ob) { store_room=ob; }
set_exits(str) { dest_dir=str; }
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
  buy_result = store_room->buy(str);
  return 1;
}

sell(str) {
object ob,*in;
int i,do_destroy;
object bag;
  
  if (!str) return;
  if (sscanf(str,"all from %s",ob)) {
	bag = present(ob,TP);
	if (bag) {
     in=all_inventory(bag);
     for (i=0;i<sizeof(in);i++)
	if (!in[i]->drop() && in[i]->query_value()) do_sell(in[i]);
     write("Ok.\n");
     return 1;
	}
  }
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
  if (environment(ob)==TP) {
     int weight;
     if (ob->drop()) {
	write("I can't take it from you.\n");
	return 1;
     }
     weight=ob->query_weight();
     TP->add_weight(-weight);
  }
  if (value>3500 || ob->query_quest_item()) do_destroy=1;
  if (value>1000) {
     write("The shop is low on money ...\n");
     value=1000+random(500);
  }
  write("You get "+value+" gold coins.\n");
  say(TP->query_name()+" sells "+ob->short()+".\n");
  TP->add_money(value);
  bought += value;
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
int i;

  if (!str) return;
  if (!(ob=present(str,TP)) && !(ob=present(str,TO))) {
     write("No such item ("+str+") here or in the store.\n");
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
