inherit "/obj/weapon";

#define CP(x) capitalize(x)
#define TP this_player()
#define LOC "players/goldsun/obj/location"

int i, is_old;


int query_is_old(){ return is_old; }

void set_is_old(int i){ is_old=i; }

void reset(int arg) {
 i=1;
 ::reset(arg);

if (arg) return;
    set_name("excalibur");
    set_alias("sword");
    set_short("The Mystical Excalibur");
    set_long("This is ancient Excalibur, the sword of the World's Emperor.\n");
    set_value(30000);
    set_class(19);
    set_weight(5);
    set_type(3);
    set_hit_func(this_object());
    set_light(1); 
    is_old=0;
 }
 
int lastroom(){
  if (LOC->query_location()) {
   move_object(this_object(),LOC->query_location());
   return 1;
  }
 return 0;
}

init(){
 ::init();

 add_action("kil","help");
 add_action("promote","promote");
 add_action("give","give");
 add_action("dump","dump");
}

dump(){

 if (TP && TP->query_level()>30){
   write("Test in excalibur.c >>"+LOC->query_location()+"<<\n");
   return 1;                 
 }
}


int give(string str){
 if (id(str)){
   write("NO! You cannot give it to anybody. Drop it first.\n");
   return 0;
 }
}

promote(str){
 object sign;
 if (str) {
  sign=clone_object("/players/goldsun/obj/king_sign");
  transfer(sign,find_player(str));
  sign=present("knight_king_sign",TP);
  destruct(sign);
  write("You lost your Knith sign.\n");
  say(CP(str)+" is promoted to the Knight king.\n");
  shout("New king of the knights has born.\n");
  }
 return 1;
}
  
get(){
   if (! present("knight_king_sign",this_player() ) ){
    write("You are not strong enought.\n");
    say(this_player()->query_name()+" tries to take the excalibur.\n");
    return 0;
    }
   else {
    return 1;
   }
}

drop(){
 LOC->set_file(file_name(environment(TP)));
 return ::drop();
 }


kil(str){
 if (str=="me") { 
   i=2;
  return 1;
  }
 }

 weapon_hit(attacker){
  if (i==2){ 

   /* will make test for fight */

   i=1;
   return 2000000;
      }
   else
   return 20+random(10);
  }
