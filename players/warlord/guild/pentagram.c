/* 12-SEP-93 Galadriel: bug in bastard() fixed */
#define MONK "guild/master"->query_number("monk")
inherit "obj/treasure";

string owner;
string alias;

reset(arg) {
   if(!arg) {
      set_id("pentagram");
      set_short("A pentagram");
      set_long("A small pentagram, just read it for help.\n");
   }
}

init() {
  if (!this_player()->query_player()) return;
   if(this_player()->query_guild()!=MONK && 
     this_player()->query_real_name()!=owner)  {
           write("Suddenly the pentagram disappears from your hands.\n");
           destruct(this_object());
           return 1;
           }
   call_out("bastard",8);
   add_action("read","read");
   if(this_player()->query_guild()==MONK)
   add_action("owner","owner");
   /* it was a turn */
}
  
owner(str) {
   if(!str) {
      write("The current owner is now "+owner+".\n");
      return 1;
   }
   owner=str;
   write("The current owner is now "+owner+".\n");
   alias=this_player()->query_real_name();
   return 1;
}


 read(str)  { 
   if (str=="pentagram" && owner) {
    write("You see a small pentagram the current owner is: "+owner+"\n"+
          "This small magic item gives you a free entrance to the\n"+
          "monks-guild. You can go to the guild or just type 'turn pentagram'\n"+
          "to teleport there. But the turn will cost you some power.\n");
   return 1;
   }
   if (str=="pentagram" && !owner) {
    write("You see a small pentagram.\n");
   return 1;
   }
  return 1;
} 
  bastard() {
   object tp,vic,shit;
   int i;
   tp=environment();
/* 12-SEP-93 Galadriel: next line gave bad arg to environment() */
/*   shit=all_inventory(environment(this_player())); */
   shit=all_inventory(environment(tp));
    if (tp && (vic=tp->query_attack()) && (vic->query_player())) {
      tell_room(environment(environment()),
      "\n\n"+
      "K A W UUUUUUUUUUUUU MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\n"+
      "THE PENTAGRAM EXPLODES WUMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n\n");
      for (i=0;i<sizeof(shit);i++)
      if (living(shit[i])) { 
      tell_room(environment(environment()),
      shit[i]->query_name()+
      " IS BADLY HURT  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
      shit[i]->hit_player(random(20)); 
      }  
      if (vic->query_level()>20 && tp->query_level()>20 ) {
       tp->reduce_hit_point(tp->query_max_hp()/2);
       vic->reduce_hit_point(vic->query_max_hp()/2);
  }
      destruct(this_object());
     return 1;
     }   
    call_out("bastard",8);
    return 1;
   }
 drop() {
   if (this_player()->query_guild()==MONK && owner) return;
   return 1;
  }
  turn(arg) {
   if (arg!="pentagram") return;
   if (!owner) {
      write("You are not the owner !\n"); 
   return 1;
   }
    if (this_player()->query_spell_points()<240) { /* never use that */

      write("You are too low on power to turn the pentagram !\n");
   return 1; 
   }
   tell_room(environment(this_player()),
   ""+this_player()->query_name()+" turns "+this_player()->query_possessive()+
   " pentagram and fades away !\n");
   this_player()->move_player("through a magic door#players/whisky/guild/room/c10");
   this_player()->restore_spell_points(-40);
   return 1;
  }
   

