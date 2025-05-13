id(str) { return str=="trashbin" || str=="bin"; }

short() { return "A trashbin"; }

long() {
  write("This is a trashbin. Please trash items you don't need anymore.\n"+
        "You can do a great service to environment with that.\n");
}

init() {
 add_action("trash","trash");
} 

trash(item) {
  object ob;

  if(!item) {
    write("What do you want to trash ?\n");
    return 1;
  }
  ob=present(item,this_player());
  if(!ob) {
    write("You don't have such an item.\n");
    return 1;
  }
  if(living(ob)) {   /* maybe someday you can take livings */
    write("You can not trash a living.\n"); 
    return 1;
  }
  if(!transfer(ob,"players/kelly/store")) {
    write("You trash "+item+".\n");
    say(this_player()->query_name()+" trashes "+item+".\n");
    write("You receive a coin for keeping the environment clean.\n");
    this_player()->add_money(1);
  }
  else
    write("Sorry, you can not get rid of that.\n");
  
  return 1;
}
