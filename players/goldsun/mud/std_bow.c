/*  standart bow   Goldsun 130295, valentine's day tomorrow 


*/

inherit "obj/weapon";
#define TP this_player()

int dama;

void set_arrow_damage(int i){ dama=i; }

void set_bow(object ob){ set_hit_func(ob); }

int query_bow(){ return 1; }

void reset(int arg){
 ::reset(arg);
 if (arg) return;
 set_alt_name("bow");
}

weapon_hit(attacker){
object quiver; 
 if (present("quiver_of_arrows",TP))
  { 
	write("You shoot an arrow against your enemy.\n");
	say(TP->query_name()+" shoots an arrow against "+TP->query_possessive()+
             "enemy.\n");
	quiver=present("quiver_of_arrows",TP);
	quiver->dec_arrows(1);
        return dama;
  } else {
        write("You try to swing your enemy with your bow.\n");
        return 2;    /* bow is not good weapon without arrows */
  }

 }
 
