inherit "obj/weapon";

object wielder;
string owner="";

void reset(int arg){
  ::reset(arg);
    if (arg) return 0;
    set_name("A small dagger");
    set_id("dagger");
    set_short("A small dagger");
    set_long("An ancient dagger.  It is said to\n"
             "contain the power of an evil god.\n");
    set_class(19);
    set_value(10000);
    set_weight(1);
    set_type(3);
}

set_owner(string arg){
  owner=arg;
  return 1;
}

void init(){
  ::init();    
}

get(){
  if(this_player()->query_name()==owner)
    return 1;
  else{
    write("The dagger destroys itself to avoid being wielded by you.\n");
    say(this_player()->query_name()+
        " tries to pick up the dagger, but the dagger destroys itself.\n",
        this_player());
    destruct(this_object());
  }
}

int drop(){
  this_player()->stop_wielding();
  write("You suddenly find yourself unable to drop the dagger.\n");
  if(!this_player()->query_legend_level()){
    present("thiefsoul",this_player())->set_righteous(0);
    write("You have fallen from favor, and the dagger fades away.\n");
    destruct(this_object());
    return 1;
  } 
  return 1;
}

wield(arg){
  int ret;
  ret = ::wield(arg);
  if ( ret && (!wielder)){
    wielder=this_player();
    write("As you wield the dagger, power surges through your body, "+
          "engulfing\nyou in flames!\n");
    say("You see "+this_player()->query_name()+
        " become engulfed in flames as ");
    say(capitalize(this_player()->query_pronoun())+" wields a dagger!\n");
    command("scream",this_player());
  }
  return( ret );
}

un_wield(arg){
  ::un_wield(arg);
    write("You feel the power of the dagger drain out of you.\n");
    say(this_player()->query_name()+" looks a little less powerful.\n");
    command("sigh",this_player());
    wielder = 0;
  }













