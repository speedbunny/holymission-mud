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

void init(){
  ::init();
  add_action("myset","set");
  if(!TP->query_immortal())
    if(flag!=0 && (TP->query_real_name()!=maker) 
       && !TP->query_npc() && (random(TP->query_dex())<20)){
//      tell_room(environment(TP),TP->query_name()+" falls into a trap.\n");
      say(TP->query_name()+" falls into a trap.\n", this_player());
      tell_object(TP,"You step into a trap!\n");
      if (this_object()->hide_shadow()) this_object()->end_shadow();
// if hidden by a thief, reveal snare
                  /* "You drop all your\n"+
                  "carried non-wielded stuff. Btw does the\n"+
                  "world look nicer from upside down ?\n");
                  */
      //      this_object()->drop_stuff(TP);
      call_out("drop_stuff",1,this_player());

    }
}

int myset(string arg){

  if(!arg) return 0;

  if(arg!="snare"){
    write("Set what ?\n");
    return 1;
  }

  if ((!TP->thief_object())||(TP->query_level()<27)) {
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
{ 
object *env;
object shad;
  int i,j;

  env=all_inventory(tp);
  for(i=0,j=sizeof(env);i<j;i++){
    if( !env[i]->query_wielded() && !env[i]->query_worn() &&
        env[i]->query_name()){ 
      //this_player()->drop(env[i]);
      transfer(env[i],environment(tp));
      say(this_player()->query_name()+" drops "+
          env[i]->query_name()+".\n");
    }
    else
      if (env[i]->query_worn()) {
        switch(env[i]->query_type()) {
        case "ring":
        case "helmet":
        case "amulet": transfer(env[i],environment(tp)); 
          say(this_player()->query_name()+" drops "+
              env[i]->query_name()+".\n");
          break;
        case "boot": transfer(env[i],environment(tp)); 
          destruct(env[i]); 
          write("Your "+env[i]->query_name()+
                " are destroyed by the snare!\n");
          say(this_player()->query_name()+" looses his "+
              env[i]->query_name()+" to the jaws of the snare.");
          break;
        default: break;
        }
      }
  }
  //   tp->hold(this_player(),100000000);
  shad = clone_object( "guild/master"->query_dir(1) +"/obj/snare_shadow.c" );
  shad->start_shadow( this_player(), 15);  
  call_out("destroy_snare",15);
}

int destroy_snare(){
  
//  tell_room(environment(this_object()),this_player()->query_name() +
        //    " breaks out of a snare.\n");
  destruct(this_object());
}


