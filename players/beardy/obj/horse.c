inherit "obj/treasure";

object *saddle1;

reset(int arg)
{ if(arg) return 0;

  saddle1=allocate(10);
  set_name("invis_horse");
}

void init()
{ ::init();
  add_action("myput","put");
  add_action("myget","get");
}

int myput(string str)
{ string item,place;
  int i,j,dummypl,flag;
  object dummy;

  if(!str) return 0;
  flag=0;

  sscanf(str,"%s into %s",item,place);
  if(!item || !place )
  { write("Wrong syntax !\n");
    return 1;
  }

  dummy=present(item,this_player());
  if(!dummy)
  { write("You don't have that item.\n");
    return 1;
  }

  if(place=="saddlebag")
  { for(i=0,j=sizeof(saddle1);i<j;i++)
      if(saddle1[i]==0)
      { dummypl=i;
        flag=1;
        break;
      }
    if(flag!=0)
    { saddle1[dummypl]=dummy;
      write("You are in.\n");
      move_object(dummy,"players/beardy/obj/horsebag");
    }
    return 1;
  }
  return 0;
}

int myget(string str)
{ int i,j,dummypl,flag;
  string item,place;

  if(!str) return 0;  
  flag=0;
  sscanf(str,"%s from %s",item,place);

  if(!item || !place)
  { write("Wrong syntax !!\n");
    return 1;
  }

  if(place=="saddlebag")
  { for(i=0,j=sizeof(saddle1);i<j;i++)
      if(saddle1[i]->query_name()==item)
      { dummypl=i;
        flag=1;
        break;
      }
    
    if(flag!=0)
    { write("You get a thing from the saddlebag.\n");
      move_object(saddle1[dummypl],this_player());
      saddle1 = saddle1 - ({ saddle1[dummypl] });
    }
    return 1;
  }
  return 0;
}
