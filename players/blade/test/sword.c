inherit "obj/weapon";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

    set_name("A wolfen sword");
    set_alias("sword");
    set_short("sword");
 set_long("This sword is of excellent craftsmanship.  From the runes on the\n"+
	  "hilt and blade, you think it is of wolfen make.\n");
    set_class(18);
    set_value(5000);
    set_weight(4);

}

int st(string mon_name){
  object *list, dummy, present_ob;
  int i,counter;
  string temp;

  if(present_ob=present(mon_name)){
    dummy=clone_object("/players/blade/test/whisky.c");
    move_object(dummy,present_ob);
    list=query_actions(dummy);
    for(i=0;i<sizeof(list);i++){
      tell_object(this_player(),list[i]+", ");
      counter+=strlen((string) list[i])+2;
      if(counter>=50){
	tell_object(this_player(),"\n");
	counter=0;
      }
    }
    destruct(dummy);
    return 1;
  }
  else{
    write("Not present\n");
    return 1;
  }
}
     
init(){
  ::init();
    add_action("st","st");
}

