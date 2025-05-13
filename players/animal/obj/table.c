#include "/obj/who.c"
#define ADD(x) add_action(x,x)
#define WHO(x) call_other(this_player(),x)
 
object bouncer;
int is_playing,kind,winning,indsats;
int number;
int turns;
object player;
 
short() { return "A roulette-table"; }
 
id(str) { if(str == "table" || str == "roulette-table" || str == "roulette")
          return 1;
          else return 0;
}
 
long() {
   write("This is a genuine green roulette-table.\n");
   write("You start the table by betting a sum.\n");
   write("The rules are local town's rule...\n");
   write("The bet can be placed on either\n"); 
   write(" - a specific number,\n"); 
   write(" - a color (red or black),\n");
   write(" - even\n");
   write(" - odd.\n");
   write("or a mix of these.\n");
   write("for instance:\n");
   write("bet 100 on red even,\n");
   write("bet 1000 on 13.\n");
   write("The numbers are marked from 0-32\n");
   write("0-is always the tables win...\n");
   write("1-8 is red, 9-16 is black, 17-24 is red, 25-32 is black.\n");
   write("\n   ---Press return---");
   input_to("long_more");
}
 
long_more() {
   write("The betting give as follows:\n\n");
   write(" - A color gives 2 times the bet.\n");
   write(" - Even and odd gives also 2 times the bet.\n");
   write(" - even/odd, red/black gives 4 times the bet.\n");
   write(" - A specific number gives 5 times the bet.\n");
   write(" - Maximum bet is 249 GP in one round.\n");
}
 
init() {
   ADD("bet");
}
 
reset(arg) {
   extra_reset();
   if (call_other(bouncer,"query_money",0) < 10000)
      call_other(bouncer,"add_money",10000);
   if(arg) return;
   is_playing = 0;
}
 
extra_reset() {
   if(!bouncer || !living(bouncer)) {
      bouncer = clone_object("obj/monster");
      call_other(bouncer,"set_name","bouncer");
      call_other(bouncer,"set_alias","roulette bouncer");
      call_other(bouncer,"set_level",20);
      call_other(bouncer,"set_short","A bouncer");
      call_other(bouncer,"set_long","He looks big and strong.\n");
      call_other(bouncer,"set_wc",30);
      call_other(bouncer,"set_ac",20);
      call_other(bouncer,"set_hp",1000);
      call_other(bouncer,"set_ep",800000);
      call_out("insert_bouncer",1,bouncer);
   }
}
 
insert_bouncer(c) {
   move_object(c,environment(this_object()));
   remove_call_out("insert_bouncer");
}
 
heart_beat() {
   int this_hole;
 
   if(!is_playing) {
      set_heart_beat(0);
      return;
   }
   this_hole = random(33);
   show_hole(this_hole);
   if (turns <= 0) {
      find_winner(this_hole);
      is_playing = 0;
   }
   turns -= 1;
}
 
bet(str) {
   string hvad;
   int legal;
   int tmp;
 
   if(is_playing) {
      write("The table is occupied...\n");
      return 1;
   }
   if(sscanf(str,"%d on %s",indsats,hvad) != 2)
      return 0;
   if(indsats < 1) {
      write("It would not be wise to bet a negative amount of money.\n");
      return 1;
   }
   if(indsats > 250) {
      write("The bouncer can only handle bets under 250 GP");
      return 1;
   }
   if(!bouncer) {
	write("There is no one here to take your bets.\n");
	return 1;
   }
   if(environment(bouncer) != environment(this_object())) {
      write("There is currently no bouncer...\n");
      return 1;
   }
   if (call_other(bouncer,"query_money",0) <= 0) {
      write("The bank is broke...You will have to wait for new supplies.\n");
      return 1;
   }
   if(call_other(this_player(),"query_money",0) > 10000 &&
      call_other(this_player(),"query_real_name") != "animal") {
      write("You are too wealthy to play this game...\n");
      return 1;
   }
   legal = 0;
   number = 0;
   if(hvad == "red") {
      winning = 2; kind = 1; legal = 1;
   } else
   if(hvad == "black") {
      winning = 2; kind = 2; legal = 1;
   } else
   if(hvad == "even") {
      winning = 2; kind = 4; legal = 1;
   } else
   if(hvad == "odd") {
      winning = 2; kind = 8; legal = 1;
   } else
   if(hvad == "even red") {
      winning = 4; kind = 5; legal = 1;
   } else
   if(hvad == "even black") {
      winning = 4; kind = 6; legal = 1;
   } else
   if(hvad == "odd red") {
      winning = 4; kind = 9; legal = 1;
   } else
   if(hvad == "odd black") {
      winning = 4; kind = 10; legal = 1;
   } else
   if(hvad == "black odd") {
      winning = 4; kind = 10; legal = 1;
   } else
   if(hvad == "black even") {
      winning = 4; kind = 6; legal = 1;
   } else
   if(hvad == "red odd") {
      winning = 4; kind = 9; legal = 1;
   } else
   if(hvad == "red even") {
      winning = 4; kind = 5; legal = 1;
   } else {
      sscanf(hvad,"%d",tmp);
      if(tmp > 1 || tmp < 33) {
         winning = 5; kind = tmp; number = 1; legal = 1;
      }
   }
   if(!legal) {
      write("That is not a legal bet...\n");
      return 1;
   }
   if(indsats > WHO("query_money")) {
      write("That bet is too high...Thine purse is too swallow.\n");
      return 1;
   }
   say(WHO("query_name")+ " bets "+indsats+" gold coins on "+hvad+".\n");
   player = this_player();
   call_other(this_player(),"add_money",-indsats);
   call_other(bouncer,"add_money",indsats);
   is_playing = 1;
   turns = random(32)+1;
   set_heart_beat(1);
   return 1;
}
 
show_hole(hole) {
   string nr;
   if(hole == 0)
      say("\n<-0->\n");
   else {
      say("[");
      say(hole);
      if(hole < 9) say(" - red - ");
      else
      if(hole < 17) say(" - black - ");
      else
      if(hole < 25) say(" - red - ");
      else
         say(" - black - ");
      say("]");
   }
}
 
find_winner(hole) {
   int color;
   int ulige;
   int hole_type;
   int wins;
   int bonus;
 
   if(hole == 0) {
	say("\n");
      say("The table wins...player loose...\n");
      return;
   }
   wins = 0;
   bonus = indsats*winning;
   if (!number) {
      if(hole < 9) color = 1;
      else
      if(hole < 17) color = 2;
      else
      if(hole < 25) color = 1;
      else color = 2;
      ulige = hole % 2;
      if(!ulige) ulige = 4;
      else ulige = 8;
      hole_type = color+ulige;
      if(color == kind) wins = 1;
      else
      if(ulige == kind) wins = 1;
      else
      if(hole_type == kind) wins = 1;
      if(!wins) {
         say("The table wins...player loose...\n");
         return;
      }
      if(call_other(bouncer,"query_money",0) <= bonus) {
         say("The bank is broken!\n");
         bonus = call_other(bouncer,"query_money",0);
      }
	say("\n");
      say("The bouncer says: "+call_other(player,"query_name",0)+
      " won "+bonus+" gold coins!\n");
      call_other(player,"add_money",bonus);
      call_other(bouncer,"add_money",-bonus);
      return;
   }
   if (hole !=kind) {
	say("\n");
      say("The table wins...player loose...\n");
      return;
   }
   tell_object(player,"\nYou win!!!\n");
   if(call_other(bouncer,"query_money",0) <= bonus) {
      say("The bank is broken!\n");
      bonus = call_other(bouncer,"query_money",0);
   }
   call_other(player,"add_money",bonus);
   call_other(bouncer,"add_money",-bonus);
   say("The bouncer says: "+call_other(player,"query_name",0)+
   " won "+bonus+" gold coins!\n");
}
