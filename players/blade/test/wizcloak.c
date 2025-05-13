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
object dam_shadow, nohear_shadow, invin_shadow;
string color_str;

int call_reset(){
  (environment(this_player()))->reset(1);
  write("reset called");
  return 1;
}

int show_damage(string str_arg){
  
switch(str_arg){
  case "on" : {
    if(dam_shadow) {
      write("Show_damage is already on!\n");
      return 1;
    }
    else {
      (dam_shadow = 
	clone_object("/players/blade/wiz/damage_shadow.c"))->start_shad(TP);
      write("You turn show_damage on.\n"); 
      return 1; 
    }
  }

 case "off" : {
   if(dam_shadow){
     destruct(dam_shadow);
     write("You turn show_damage off.\n");
     dam_shadow=0;
   }
   return 1;
 }
  }
}

int nohear(string str_arg){

switch(str_arg){
  case "on" : {
    if(nohear_shadow) {
      write("Nohear is already on!\n");
      return 1;
    }
    else {
      (nohear_shadow = 
	clone_object("/players/blade/wiz/no_hear_shadow.c"))->start_shad(TP);
      write("You turn nohear on.\n"); 
      return 1; 
    }
  }

 case "off" : {
   if(nohear_shadow){
     destruct(nohear_shadow);
     write("You turn nohear off.\n");
     nohear_shadow=0;
   }
   return 1;
 }
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
  if(dam_shadow)    write("Show_damage is on.\n");
  else              write("Show_damage is off.\n");
  if(nohear_shadow) write("Nohear is on.\n");   
  else              write("Nohear is off.\n");  
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

int invincible(string str_arg){  
switch(str_arg){
  case "on" : {
    if(invin_shadow) {
      write("Invincible is already on!\n");
      return 1;
    }
    else {
      (invin_shadow = 
	clone_object("/players/blade/wiz/invincible_shadow.c"))->start_shad(TP);
      write("You turn invincible on.\n"); 
      return 1; 
    }
  }

 case "off" : {
   if(invin_shadow){
     destruct(invin_shadow);
     write("You turn invincible off.\n");
   }
   return 1;
 }
  }
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
     "                 to use with show_damage, install invincible first.\n");

   return 1;
  }
}

reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("cloak");
     set_type("guild");
  
     set_size(3);
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
}












