inherit "obj/treasure";

int arrow_num,max_arrow_num;

reset(int arg)
{ ::reset(arg);
  if(arg) return 0;

  
  max_arrow_num=60;

  set_name("arrowbag");

  set_short("arrowbag ("+arrow_num+")");
  set_long("This is a arrowbag with "+arrow_num+" arrows in it.\n");

  set_value(100);
  set_weight(1);
}

int query_arrows()
{ return arrow_num;
}

int add_arrows(int arg)
{ if(arrow_num>max_arrow_num)
  {
  tell_room(environment(environment(this_object())),"An arrow falls out of the bag.\n");
    arrow_num=max_arrow_num;
    return 1;
  }
  else
    arrow_num+=arg;
  set_short("arrowbag ("+arrow_num+")");
  return 1;
}

int query_max_arrows()
{ return max_arrow_num;
}
