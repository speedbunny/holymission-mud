inherit "obj/weapon";

object wielder=0;
int is_berzerk=0, move_count=0;

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

    set_name("Sword of rage");
    set_alias("sword");
    set_short("sword");
 set_long("This sword is of excellent craftsmanship.  A vein of blood\n"+
          "red metal runs the length of the tatsuo.\n");
    set_class(19);
    set_value(10000);
    set_weight(4);
    enable_commands();
    //    this_object()->set_wield_funct(this_object());
}


int wield(string arg){
  int ret; 

  write("entering ::wield\n");
  ret = ::wield(arg);
  write("ret == "+ret+"\n");
  write("wield == "+wielder+"\n");
  write(environment(this_object())->query_name()+"\n");
  write("arg "+arg+"\n");
  write("ret&&!wielder =="+ (ret && (!wielder))+"\n");
  if ( ret && (!wielder)){
    wielder=this_player();
    write("As you wield the sword, power and rage surge through your body, "+
          "engulfing\nyou in flames!\n");
    say("You see "+this_player()->query_name()+
        " become engulfed in flames as ");
say(capitalize(this_player()->query_pronoun())+" wields the Sword of Fury!\n");
    command("scream",this_player());

    this_object()->reset_move_count();
    this_object()->berzerk();
  }
  return( ret );
}

un_wield(arg){
  ::un_wield(arg);
    write("You feel the rage of the sword drain out of you.\n");
    this_object()->set_berzerk(0);
    say(this_player()->query_name()+" looks much less angry.\n");
    command("sigh",this_player());
    wielder = 0;
    return 1;
}

int _filter(string str){
  if(str=="ds") destruct(this_object());
  if(this_object()->query_berzerk()){
    write("You try to control yourself, but you are too angry.\n");
    return 1;
  }
  else return 0;
}

init(){
  ::init();

  add_action("_filter","",1);
  return 1;
}

catch_tell(string arg){
  string name;

  if(sscanf(arg,"%s died.\n",name)==1){
    write(arg);
    if(this_object()->query_wielded())
      call_out("berzerk",1);
    return 1;
  }
  return 0;
}
 
void set_berzerk(int arg){  is_berzerk = arg;  }
int query_berzerk(){  return is_berzerk;  }
int reset_move_count(){ move_count = 0; }
int inc_move_count(){ move_count++; }
int query_move_count(){ return move_count; }

int berzerk(){
  object *room_inv;
  int i, j;

  this_object()->set_berzerk(1);

  room_inv=all_inventory(environment(this_player()));
//  write("checking current room.\nsizeof inv ="+sizeof(room_inv)+"\n");
  for(i=sizeof(room_inv)-1;i>=0;i--){
    if(room_inv[i]->query_living() && room_inv[i]!=this_player() &&
       room_inv[i]->query_npc()){
      write("You attack "+room_inv[i]->query_name() + " in a blind fury!\n");
      say(this_player()->query_name()+" attacks "+room_inv[i]->query_name()+
          " in a blind fury!\n",this_player());
      this_player()->attack_object(room_inv[i]);
      this_player()->attack();
      this_object()->reset_move_count();
      return 1;
    }
  }
  if(query_move_count()<4){
    call_out("random_move",1);
    return 1;
  }
  this_object()->un_wield("sword");
  return 1;
}

int random_move(){
  string *dest_dir_;
  string *dest_hdir_;
  int dd, dhd, td;
  int destination;

  dest_dir_ = (string *)(environment(this_player())->query_room("dest_dir"));
  dest_hdir_=(string *)(environment(this_player())->query_room("hidden_dir"));
  dd = sizeof(dest_dir_);
  dhd = sizeof(dest_hdir_);
  td = dhd + dd;
//  write("size dest = "+dd+"\nsize hdest = "+dhd+"\n");
//  write(dest_dir_[0]);
  destination = random(td/2);

  if(!td){
    destruct(this_object());
    return 1;
  }

  this_object()->inc_move_count();

  if(destination*2 > dd){
    this_player()->move_player(dest_hdir_[destination*2-dd+1], 
                               dest_hdir_[destination*2-dd]);
    write("You run "+dest_hdir_[destination*2-dd+1]+
          " in a search for something to kill.\n");
  }
  else{ 
    this_player()->move_player(dest_dir_[destination*2+1],
                               dest_dir_[destination*2]);
    write("You run "+dest_dir_[destination*2+1]+
          " in a search for something to kill.\n");
  }
  this_object()->berzerk();
  return 1;
}





