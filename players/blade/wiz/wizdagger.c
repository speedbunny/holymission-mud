inherit "obj/weapon";

int magic_hit_power;
int poison_level;
object wielder;

void reset(int arg){
  ::reset(arg);
    if (arg) return 0;
    set_name("A small dagger");
    set_id("dagger");
    set_short("A small dagger");
    set_long("An ancient dagger.  It is said to\n"
	     "contain the power of an evil god.\n"
	     "Type help dagger for instructions.\n");
    set_value(10000);
    set_weight(0);
    set_type(3);
    set_hit_func(this_object());
    magic_hit_power=0;
    poison_level=0;
}

int magic_hit(object victim){
  write("You deftly stab "+victim->query_name()+" in the back.\n");
  return magic_hit_power;
}

void init(){
  ::init();
    
    add_action("change_wc","change_wc");
    add_action("change_mh","change_mh");
    add_action("change_po","change_po");
    add_action("dagger_stat","dagger_stat");
    add_action("help","help");
  }

get(){
  if(this_player()->query_immortal()){
    return 1;
  }
  else{
write("Only Immortals may wield the dagger!  The dagger destroys iteself.\n");
    say(this_player()->query_name()+
        " tries to pick up the WizDagger, but the dagger destroys itself.\n",
        this_player());
    destruct(this_object());
  }
}
 

int weapon_hit(object attacker) {
  if(poison_level){
    write("You watch as your attacker chokes on the poison.\n");
    attacker->add_poison(poison_level);
  }
  return 1;
}

int help(string arg) {
  if(!(arg=="dagger")) { return 0; }
  else{
    write("change_wc x - Changes the Weapon Class of the weapon to x.\n"    +
	  "change_mh x - Changes the Magic Hit of the weapon to x.\n"       +
	  "change_po x - Changes the Poison Level of the weapon to x.\n"    +
	  "dagger_stat - Shows the current levels of the dagger.\n")        ;
    return 1;
  }  
}

int dagger_stat() {
  write("The Weapon Class of this dagger is: "+set_class()+"\n"   +
	"The Magic Hit of this dagger is: "+magic_hit_power+"\n"  +
        "The Poison Level of this dagger is: "+poison_level+"\n") ;   
  return 1;
}

int change_po(int arg)
{
  if(sscanf(arg, "%d", poison_level)==1) {
    write("Poison Level changed to "+arg+"\n");
    return 1;
  }
}

int change_mh(int arg) {
  if(!arg) {
    write("What would you like to change the magic hit power to?\n");
    return 1;
  }
  if(sscanf(arg, "%d", magic_hit_power)==1) {
    write("Magic hit power is now "+arg+"\n");
    return 1;
  }
}

int change_wc(int arg){
  int class;
  
  if(!arg){
    write("What would you like to change the wc to?\n");
    return 1;
  }
  if(sscanf(arg, "%d", class) == 1){
    write("Weapon class is now "+arg+"\n");
    set_class(class);
    return 1;
  }
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
    say(capitalize(this_player()->query_pronoun())+" wields the dagger!\n");
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





