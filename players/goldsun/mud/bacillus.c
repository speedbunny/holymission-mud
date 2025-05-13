/***************************************************************************/
/*              B A C I L L U S						  */
/****************************************************************************/

inherit "/obj/monster";

#define TO this_object()
#define TP this_player()
#define env(x) environment(x)

int    *range, counter, freq, const, i, weight;
object victim;

void set_range( int *p){ range=p;}

void set_freq(int f){ freq=f;}

void set_victim(object ob){ victim=ob; }

object query_victim(){ return victim; }

int query_weight(){ return weight; }


void dead(){ destruct(TO); }

reset(arg){
 ::reset(arg);

 if (arg) return;
 set_name("bacillus");
 set_long("Bacillus (invisible for players)\n");
 set_level(5); 
 counter=0;
 is_invis=30;
 freq=1;
 weight=0;
 const=1;
 i=0;
}

 heart_beat(){
  ::heart_beat();
/*  
  counter++;


  if (counter==freq){
      counter=0;
      if (victim){
         victim->reduce_hit_point(range[i]);
         i+=const;
         if (i==sizeof(range)) const=-1;
         if (i==0) const=1;
      }
   } 
*/
 }

init(){

 ::init();

 if (TP)
  if (!present("bacillus",env(TP))){ 
       transfer(TO,TP);
  }
}	

get(){
 return 1;
}
