/* Generic shop code */
string short_desc, long_desc, storeroom, storeexit, storeexitmesg;
string exitlist, exits;  /* 2-d array of exits and destinations */
 
set_store_exit(arg) { storeexit=arg; }
set_store_exit_mesg(arg) { storeexitmesg=arg; }
set_store_room(arg) { storeroom=arg; }
set_short(arg) { short_desc=arg; }
set_long(arg) { long_desc=arg; }
add_exit(arg) { 
   string exit,room,old;
   int i,len;
   if (sscanf(arg,"%s#%s",exit,room)!=2) {
      write("ERROR: Invalid arguement to add_exit.  Please notify "+
            creator(this_object())+".\n");
      return 1;
   }
   len=0;
   if (exits) {
      len=sizeof(exits);
      exitlist="There are exits to the "+exits[0][0];
   } else
      exitlist="     The only obvious exit is ";
   old=allocate(len+1);
   i=0;
   while (i<len) {
      old[i]=allocate(2);
      old[i][0]=exits[i][0];
      old[i][1]=exits[i][1];
      if (i) exitlist+=", "+exits[i][0];
      i+=1;
   }
   old[i]=allocate(2);
   if (len) exitlist+=" and ";
   exitlist+=exit+".\n";
   old[i][0]=exit;
   old[i][1]=room;
   exits=old;
}
 
short() { return short_desc; }
 
long(arg) {
   if (!arg) {
      write(long_desc);
      write(exitlist);
      return 1;
   }
}
 
init() {
   add_action("sell"); add_verb("sell");
   add_action("value"); add_verb("value");
   add_action("buy"); add_verb("buy");
   add_action("list"); add_verb("list");
   if (exits) {
      int i, len;
      i = 0;
      len = sizeof(exits);
      while(i<len) {
         add_action("move"); add_verb(exits[i][0]);
         i += 1;
      }
   }
   if (storeexit) {
      add_action("move"); add_verb(storeexit);
   }
}
 
reset(arg) {
   if (arg) return;
   short_desc = "The shop";
   long_desc = 
	 "You are in a shop. You can buy or sell things here.\n" +
	 "Commands are: 'buy item', 'sell item', 'sell all', 'list',\n" +
	 "'list weapons', 'list armours' and 'value item'.\n" +
	 "There is an opening to the north, and some shimmering\n" +
	 "blue light in the doorway.\n";
   exitlist="     There are no obvious exits.\n";
   storeexitmesg="You wriggle through the force field...";
   set_light(1);
}
 
move() {
   int i,len;
   i=0; len=0;
   if (exits) len=sizeof(exits);
   if (query_verb()==storeexit) {
      if (this_player()->query_level()<20) {
         write("A strong magical force stops you.\n");
         say(this_player()->query_name()+" tries to go through the field but fails.\n");
      } else {
        write(storeexitmesg+"\n");
        this_player()->move_player(storeexit+"#"+storeroom);
      }
      return 1;
   }
   while (i<len) {
      if (query_verb()==exits[i][0]) {
         this_player()->move_player(query_verb()+"#"+exits[i][1]);
         return 1;
      }
      i+=1;
   }
}
 
query_nosucko() { return 1; }
 
sellall(who) {
   object current;
   int count;
   if (!who || environment(who)!=this_object()) return;
   current=first_inventory(who);
   while (current) {
      object next;
      string str;
      next=next_inventory(current);
      str=current->short();
      if (str && !current->id("ND")) {
         tell_object(who,str+"... ");
         sell_ob(current,who);
      }
      count+=1;
      if (count > 8) {
         call_out("sellall",1,who);
         return;
      } 
      current=next;
   }
}
 
sell(item) {
    int value;
    object name_of_item,ob;
    if (!item) return 0;
    if (item=="all") {
        sellall(this_player());
	return 1;
    }
    name_of_item=present(item, this_player());
    if (!name_of_item) {
	write("You can't sell what you do not have.\n");
	return 1;
    }
    return sell_ob(name_of_item,this_player());
}
 
sell_ob(ob,player) {
    int value;
    value=ob->query_value();
    if (!value) {
        tell_object(player,"Item has no value.\n");
        return 1;
    }
    if (environment(ob)==player) {
        if (ob->drop()) {
	    tell_object(player,"I can't take it from you!\n");
	    return 1;
	}
        player->add_weight(-ob->query_weight());
        if (value>1000) {
           int n;
	   n=random(125)+random(125)+1000;
	   if (n<value) {
              value=n;
              tell_object(player,"The shop is low on money...\n");
           }
       }
       tell_object(player,"You get "+value+" gold coins.\n");
       say(player->query_name()+" sells "+ob->short()+".\n",player);
       player->add_money(value);
       storeroom->store(ob);
    }
    return 1;
}
 
value(item) {
    int value;
    object name_of_item;
    if (!item) return 0;
    name_of_item=present(item);
    if (!name_of_item) name_of_item=present(item,this_player());
    if (!name_of_item) {
	if (call_other(storeroom,"value",item)) return 1;
	write("No such item ("+item+") here\n");
	write("or in the store.\n");
	return 1;
    }
    value=name_of_item->query_value();
    if (!value) {
	write(item+" has no value.\n");
	return 1;
    }
    if (value < 1001)
       write("You would get "+value+" gold coins.\n");
    else {
       write("It's really worth "+value+" gold coins.\n");
       write("But the store is low on money, so you would get about 1000.\n");
    }
    return 1;
}
 
buy(item) {
    if (!item) return 0;
    storeroom->buy(item);
    return 1;
}
 
list(obj) {
    storeroom->inventory(obj);
    return 1;
}
