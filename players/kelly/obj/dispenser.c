status open;
string read_msg,items;
int amount,all_money;
 
init() {
  add_action("insert","insert");
  add_action("kick","kick");
  add_action("read","read");
  add_action("press","press");
  add_action("open","open");
}
 
reset() {
  read_msg="0 coins\n";
  open=0;
  amount=0;
  all_money=0;
  items=({"players/kelly/obj/knife",
          "players/kelly/obj/glowworm",
          "players/kelly/obj/watch",
          "players/kelly/guild/lightsaber",
          "players/kelly/guild/cape", 
          "players/kelly/obj/salve",
  });
}
 
id(str) {
  return (str=="dispenser"||str=="slot"||str=="mcd"||str=="manual"
      ||str=="buttons"||str=="drawer");
}
 
short() {
  return "A dispenser";
}
 
long(str) {
 if(str=="dispenser") {
  write("This is a goodie-dispenser.\n");
  write("A manual, several buttons, a MCD, and a drawer are\n");
  write("attached to the dispenser.There's a slot to insert coins.\n");
  return 1;
 }
 if(str=="manual") write("You can read it!\n");
 if(str=="slot") write("A slot to insert gold coins.\n");
 if(str=="buttons") buttons();
 if(str=="drawer")
   if(open) 
     write("A drawer(open).\n");
   else write("A drawer(closed).\n");
 if(str=="mcd") {
   write("It's a Magic Crystal Display.\n");
   if(read_msg) write("It reads: "+read_msg);
   else write("Nothing displayed.\n");
 }
}
 
kick(str) {
  if (!id(str)) return 0;
  write("The dispenser grows legs and kicks you back! \n");
  say(this_player()->query_name()+" rudely kicks the dispenser. \n");
  say("You don't believe your eyes as the dispenser grows legs ");
  say("and kicks "+this_player()->query_name()+" back.\n");
  return 1;
}
 
insert(str) {
  int much;
  if(!str) return 0;
  if(sscanf(str,"%d coins",much)!=1) {
    write("How much coins do you want to insert?\n");
    return 1;
  }
  if(this_player()->query_money()>=much) { 
    amount=amount+much;
    all_money=all_money+much;
    read_msg=amount+" coins.\n";
    write("You insert "+much+" coins into the slot.\n");
    say(this_player()->query_name()+" inserts "+much+" coins into the "+
     "dispenser.\n");
    this_player()->add_money(-much);
  }
  else
    write("You don't have "+much+" coins.\n");
  return 1;
}
 
press(str) {
  int nr;
  if(sscanf(str,"button %d",nr)!=1) return ;
  if(nr<1 || nr>=sizeof(items)+2) {
    write("No such labeled button.\n");
    return 1;
  }
  buy_item(nr-2);
  return 1;
}
 
read(str) {
  if(str=="manual") {
    say(this_player()->query_name()+" reads the manual.\n");
    write("You read the manual.\n");
    cat("/players/kelly/obj/dispmanual");
    return 1;
  }   
  else 
   if(str=="mcd") {
     write("It reads: "+read_msg); 
     return 1;
   }
   return 0;
}
 
buy_item(nr) {
  object obj;
  if(sizeof(items)<nr) {
    write("This button has no function at the moment.\n");
    return 1;
  }
  if(nr==-1) {
    write("You've press the CANCEL-button.\n");
    if(!random(100) && all_money) {
      read_msg="MALFUNCTION.\n";
      write("The MCD twinkles red.\n");
      lose_money(all_money);
      return 1;
    }
    if(amount) 
      lose_money(amount);
    read_msg="0 coins.\n";
    return 1;
  }
  if(items[nr]->query_value()*2>amount) {
    write("Nothing happens.\n");
    return 1;
  }
  obj=clone_object(items[nr]);
  amount-=2*obj->query_value();
  read_msg=amount+" coins.\n";
  write("You can hear the touchdown of an object in the dispenser.\n");
  say("You can hear the touchdown of an object in the dispenser.\n");
  move_object(obj,this_object());
  return 1;
}
 
lose_money(many) {
  object money;
  write("You can hear a rustling noise from the dispenser.\n");
  say("You can hear a rustling noise from the dispenser.\n");
  money=clone_object("obj/money");
  money->set_money(many);
  move_object(money,this_object());
  all_money=all_money-many;
  amount=0;
}
 
open(str) {
  if(str!="drawer" && str!="dispenser") return;
  if(!open) {
    write("You open the drawer.\n");
    say(this_player()->query_name()+" opens the drawer of the dispenser.\n");
    open=1;
    call_out("close",30);
  }
  else
  {
    write("The drawer is already open.\n");
  }
  return 1;
}
 
close() {
  tell_room(environment(this_object()),"The draw closes.\n");
/*
    Taken out because it told you about drawer AFTER you left room.
  write("The drawer closes silently.\n");
  say("The drawer closes silently.\n");
*/
  open=0;
}


query_weight() { return 1000; }

can_put_and_get() {
  return open; 
}

get() { return 1; }

buttons() {
  int nr,i; 

  nr=sizeof(items);

  write("The first "+(nr+1)+" buttons are labeled.\n"); 
  printf("Button %-4d %-30s\n",1,"Cancel-Button");
  for(i=0;i<nr;i++) 
  printf("Button %-4d %-30s %-4d\n",i+2,items[i]->short(),items[i]->query_value()*2);
} 
