inherit "obj/weapon";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

    set_name("A wolfen sword");
    set_alias("sword");
    set_short("sword");
 set_long("This sword is of excellent craftsmanship.  From the runes on the\n"+
	  "hilt and tatsuo, you think it is of wolfen make.\n");
    set_class(18);
    set_value(5000);
    set_weight(4);

}

init(){
  ::init();
    add_action("qb","qb");
  }

int qb(string str_arg){
  int i, j, total, ic, jc, carried_coins;
  object *inv, *invc, ob;

  if (!str_arg){ 
    write("What would you like to value?\n");
    return 1;
  }

  if (!(ob=present(str_arg,this_player()))){
    if (!(ob=present(str_arg,(environment(this_player()))))){
      write("That is not present\n");
      return 1;
    }
  }

  inv = deep_inventory(ob);
  total =0;
  j=sizeof(inv);
  for (i=0; i < j; i++){
    total+=(inv[i]->query_value());
  }

  if(!(living(ob))){
    total+=ob->query_value();
    write(capitalize(ob->query_name())+" is worth "+total+" in coins.\n");
  }

  if(living(ob)){
    carried_coins=ob->query_money();
    carried_coins+=random(carried_coins/4)-random(carried_coins/4);
    carried_coins/=100;
    carried_coins*=100;
    write(capitalize(ob->query_name())+" is carrying "+total+" worth in coins.\n");
    write(capitalize(ob->query_name())+" has "+carried_coins+" coins.\n");
  }
  return 1;
}








