inherit "obj/treasure";

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_id("jumper");
  }
}

void init()
{ ::init();
  add_action("myjump","jump");
}

int myjump(string arg)
{ int flag,i,j,place;
  object *env;
    
  env=all_inventory(environment(this_player()));
  
  for(i=0,j=sizeof(env); i<j; i++) 
  { if(env[i]->query_real_name()==arg)
    { flag=1;
      write("Found it.\n");
      place=i;
      break;
    }
  }

   transfer(this_player(),env[place]);
   return 1;
}
