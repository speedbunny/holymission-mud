inherit "/obj/weapon";
#define CP(x) capitalize(x)
#define TP this_player()

object kf;
string env;
int i;       

reset(arg) {
 i=1;
 ::reset(arg);

if (arg) return;
    set_name("Excalibur");
    set_id("excalibur");
    set_alias("sword");
    set_short("The Mystical Excalibur");
    set_long("This is ancient Excalibur, the sword of the World's Emperor.\n");
    set_value(30000);
    set_class(20); 
    set_weight(5);
    set_type(3);
    set_hit_func(this_object());
    set_light(1); 
 }
 
init(){
 ::init();
 add_action("kil","help");
 add_action("promote","promote");
}


give(){
 write("NO. You cannot give it to anybody. Drop it first.\n");
 return 0;
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
   /* make test for fight */

   i=1;
   return 2000000;
      }
   else
   return 20+random(10);
  }
