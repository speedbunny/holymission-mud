/* The Cloak of Blade             */
/* Coded on Holy Mission by Blade */
/* Version 12.4.94                */

#define TP this_player()

inherit "/obj/armour";

int f_light_level();
int change_ac(int arg);
int show_damage(string str_arg);
int des_shadow();
int cloak_stat();
int help(string str_arg);
int nohear(string str_arg);
int read(string str_arg);
int call_reset();
int invincible(string str_arg);

int ac_arg;
string color_str;

int call_reset(){
  (environment(this_player()))->reset(1);
  write("reset called");
  return 1;
}

get(){
  if(this_player()->query_immortal()){
    return 1;
  }
  else{
    write("Only Immortals may wear the cloak!  The cloak destroys iteself.\n");
    say(this_player()->query_name()+
	" tries to pick up the WizCloak, but the cloak destroys itself.\n",
	this_player());
    destruct(this_object());
  }
}

int f_light_level() {
  write("The light level in this room is: " + set_light(0) + "\n");
  return 1;
}

int change_ac(int ac_arg) {
int class;

  if(!ac_arg){
    write("Please enter a number.\n");
    return 1;
  }
  if (sscanf(ac_arg,"%d",class)==1){
    if(class>30){write("Warning, AC higher than 30 may cause errors!\n");}
    write(ac_arg+"\n");
    set_ac(class);
    write("Done!\n");
    return 1;
 }
}

int cloak_stat(){
  
  write("The armour class of the cloak is: "+ac_arg+".\n");
  printf("Damage is %s.\n",(this_player()->query_damage_shadow())?"on":"off");
  printf("Invincible is %s.\n",
	 (this_player()->query_invincible_shadow())?"on":"off");
  printf("LickShield is %s.\n",(this_player()->query_lickshield())?"on":"off");
  printf("Nohear is %s.\n",(this_player()->query_nohear())?"on":"off");
  write("The color of the cloak is: "+color_str+"\n");

return 1;
}

int des_shadow() {
  object shad;
  shad = shadow(this_player(), 0);
  if(shad) {
    destruct(shad);
    write("Shadow destructed.\n");
    return 1;
  }
  write("No shadow present.\n");
  return 1;
}

int read(string str_arg){
  if(str_arg=="tag"){
    write("You read:\n"               +
	  "The WizCloak of Blade.\n"  +
	  "Version 12.4.94.\n"       +
	  "Type \"help cloak\" for functions.\n");
    return 1;
  }
  else return 0;
}

short(){
short_desc="A "+color_str+" cloak";
  if(!short_desc) return 0;
  if(worn) {
    if(size)
      return short_desc + " (" + sizes[size] + ") (worn)";
    else
      return short_desc + " (worn)";
  }
  else {
    if(size)
      return short_desc + " (" + sizes[size] + ")";
    else
      return short_desc;
  }
}

int color(string str_arg){
  
  if(!str_arg){
    write("What color would you like?\n");
    return 1;
  }
  else {
    color_str=str_arg;
    write("You have changed the color to: "+str_arg+".\n");
    return 1; 
  }
}

int lickshield(string str_arg){
  if(str_arg=="on"){
    if(this_player()->query_lickshield()){
      write("You have already equipped your LickShield!\n");
      return 1;
    }
    else{
      write("You turn on LickShield.\n");
      clone_object("/players/blade/wiz/lick_shield.c")->start_shad(TP);
      return 1;
    }
  }
  if(str_arg=="off"){
    if(this_player()->query_lickshield()){
      write("You turn off LickShield.\n");
      destruct(this_player()->query_lickshield());
      return 1;
    }
    else{
      write("LickShield is not on!\n");
      return 1;
    }
  }
  this_object()->help("cloak");
}

int show_damage(string str_arg){
  if(str_arg=="on"){
    if(this_player()->query_damage_shadow()){
      write("You have already equipped show damage!\n");
      return 1;
    }
    else{
      write("You turn on show damage.\n");
      clone_object("/players/blade/wiz/damage_shadow.c")->start_shad(TP);
      return 1;
    }
  }
  if(str_arg=="off"){
    if(this_player()->query_damage_shadow()){
      write("You turn off show damage.\n");
      destruct(this_player()->query_damage_shadow());
      return 1;
    }
    else{
      write("Show damage is not on!\n");
      return 1;
    }
  }
  this_object()->help("cloak");
}

int nohear(string str_arg){
  if(str_arg=="on"){
    if(this_player()->query_nohear()){
      write("You have already equipped Nohear!\n");
      return 1;
    }
    else{
      write("You turn on Nohear.\n");
      clone_object("/players/blade/wiz/no_hear_shadow.c")->start_shad(TP);
      return 1;
    }
  }
  if(str_arg=="off"){
    if(this_player()->query_nohear()){
      write("You turn off nohear.\n");
      destruct(this_player()->query_nohear());
      return 1;
    }
    else{
      write("Nohear is not on!\n");
      return 1;
    }
  }
  this_object()->help("cloak");
}

int invincible(string str_arg){
  if(str_arg=="on"){
    if(this_player()->query_invincible_shadow()){
      write("You have already equipped Invincible!\n");
      return 1;
    }
    else{
      write("You turn on Invincible.\n");
      clone_object("/players/blade/wiz/invincible_shadow.c")->start_shad(TP);
      return 1;
    }
  }
  if(str_arg=="off"){
    if(this_player()->query_invincible_shadow()){
      write("You turn off Invincible.\n");
      destruct(this_player()->query_invincible_shadow());
      return 1;
    }
    else{
      write("Invincible is not on!\n");
      return 1;
    }
  }
  this_object()->help("cloak");
}

    

int help(string str_arg){

  if((str_arg!="cloak")) return 0;
  else {
    write("The Cloak of Blade.  Version 11.3.94\n"                            +
         "light_level   -  Shows the light level of a room.  No args.\n"      +
         "change_ac     -  Changes the armour class of the cloak to arg.\n"   +
	 "                 It is suggested that arg be less than 31.\n"       +
	 "show_damage   -  Shows the damage inflicted upon you by monsters.\n"+
         "                 Args are on and off.\n"                            +
         "nohear        -  Turns off shouts and tells to you.\n"              +
	 "                 Args are on and off.\n"                            +
	 "des_shadow    -  Destructs a shadow that is on you.\n"              +
         "cloak_stat    -  Shows status of cloak.\n"                          +
         "color         -  Changes the color of the cloak to arg.\n"          +
	 "                 Coded special for Paprika :)\n"                    +
	 "invincible    -  Makes you immune to attacks.  NOTE: If you wish\n" +
       "                 to use with show_damage, install invincible first.\n"+
	 "call_reset    -  Calls reset(1) in your environment object.\n"      +
	 "lickshield    -  Prevents people from licking you!\n"               +
	 "                 Usage: lickshield on/off\n");

   return 1;
  }
}

reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("cloak");
     set_type("guild");
  
     set_long("The cloak has many pockets, and probably many functions.\n" +
	     "It has a small tag on the inside.\n");
     set_value(0);
     set_weight(0);
     set_alias("dark cloak");

     color_str="dark";
     ac_arg=0;
  }
}

init() {
    ::init();

    add_action("read","read");
    add_action("cloak_stat","cloak_stat");
    add_action("help","help");
    add_action("f_light_level","light_level");
    add_action("change_ac","change_ac");  
    add_action("show_damage","show_damage");
    add_action("nohear","nohear");
    add_action("des_shadow","des_shadow");
    add_action("color","color");
    add_action("invincible","invincible");
    add_action("call_reset","call_reset");
    add_action("lickshield","lickshield");
}












