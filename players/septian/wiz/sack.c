inherit "obj/container";

reset(arg) {
    ::reset(arg);
    if (!arg) {
      set_weight(1);
      set_max_weight(99999);
      set_value(35);
      set_name("a big sack");
      set_alias("sack");
      set_can_close(1);
    }
}

long(){
  
  if(environment(this_player())==this_object()){
    write("This is a small cramped sack that you have been stuffed into.\n");
    write("You could have wished for more room, but it is livable.\n");
    write("        Sack contains:\n");
    call_out("see_objs",0);
    return 1;
  }
  write("A sack that you could probably stuff someone into.\n");
  return 0;
}

int see_objs(){
  int i, j, sz;
  object *inv;

  if (!first_inventory(this_object())) return 0;

     inv = all_inventory(this_object());

     for (j=sizeof(inv), i = 0; i < j; i++)
       write(inv[i]->query_name()+"\n");
     return 1;
}

init(){
  ::init();
    add_action("stuff","stuff");
    add_action("unstuff","unstuff");
  }

int stuff(string str_arg){
  object ob;
  string player_name;

  if(ob=present(str_arg,environment(this_player()))){
    player_name=(ob->query_name());
    write("You stuff "+player_name+" into a sack.\n");
    move_object(ob,this_object());
    say(this_player()->query_name()+" stuffs "+player_name+" into a sack.\n");
    tell_object(ob,this_player()->query_name()+" stuffs you into a sack.\n");
  }
  return 1;
}

int unstuff(string str_arg){
  object ob;
  string player_name;
  if(ob=present(str_arg,this_object())){
    player_name=(ob->query_name());
    write("You dump "+player_name+" onto the floor.\n");
   say(this_player()->query_name()+" dumps "+player_name+" onto the floor.\n");
    tell_object(ob,this_player()->query_name()+" dumps you onto the floor.\n");
    move_object(ob,environment(this_player()));
  }
  return 1;
}

