inherit "obj/treasure";
#define TP this_player()

int flag;
static string maker;

reset(int arg)
{ ::reset(arg);
  if(arg) return 0;

  set_id("snare");
  set_name("snare");
  set_short("snare (unset)"),
  set_long("It's a thief's snare. Maybe you can 'set' it.\n");
  set_weight(1);
  set_value(500);
  flag=0;
}

int get()
{ if(flag==1)
    return 0;
  else
     return 1;
}

void init()
{ ::init();
  add_action("myset","set");
  if(!TP->query_immortal())
    if(flag!=0 && (TP->query_real_name()!=maker) 
       && !TP->query_npc() && (random(TP->query_dex())<20)){
      tell_room(environment(TP),TP->query_name()+" falls into a trap.\n");
      tell_object(TP,"You fall into a trap loose all your\n"+
		  "carried non-wielded stuff. Btw does the\n"+
		  "world look nicer from upside down ?\n");
      this_object()->drop_stuff(TP);
    }
}

int myset(string arg)
{ if(!arg) return 0;

  if(arg!="snare")
  { write("Set what ?\n");
    return 1;
  }

  if ((TP->query_guild()!=1)||(!TP->query_legend_level())) {
    write("You do not have the skill to set the snare.\n");
    return 1;
  }
  if(sizeof(all_inventory(environment(TP)))>1){
    write("You don't think you should set it here.\n");
    return 1;
  }

  flag=1;
  write("You set the snare. *GRIN*\n");
  this_object()->set_name("snare (set)");
  maker=TP->query_real_name();
  transfer(this_object(),environment(TP));
  return 1;
}

void drop_stuff(object tp)
{ object *env;
  int i,j;

  env=all_inventory(tp);
  for(i=0,j=sizeof(env);i<j;i++)
  {
    if (env[i]->query_armour()) {
      switch(env[i]->query_type()) {
        case "ring":
        case "helmet":
        case "amulet": transfer(env[i],environment(tp)); break;
        case "boot": transfer(env[i],environment(tp)); destruct(env[i]); break;
        default: break;
      }
    }
    if(!env[i]->query_wielded() && !env[i]->query_armour()){ 
      transfer(env[i],environment(tp));
    }
  }
  tp->hold(this_object(),10);
  call_out("destroy_snare",10,tp);
}

int destroy_snare(object tp){
  
  tell_room(environment(tp),"The snare is destroyed.\n");
  destruct(this_object());
  
}
