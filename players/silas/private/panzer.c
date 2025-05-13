/*inherit "obj/treasure" | treasures cant move ??? -Arthur*/
inherit "obj/monster";
int n, t, v,id, locked;
object destination, where, environment;
string to;

reset(arg) {
  if (arg) return 1;
   /*set_id("panzer");*/
   set_name("panzer");
   /* set_light(1); not needed, since this moves in a room -Arthur*/
   set_heart_beat(1);
   enable_commands(); /*so it can be found -Arthur*/
   set_living_name("panzer"); /*so it can be found -Arthur*/
   set_short("A German Panzer");
   set_long("Before you stands a thundering Panzer Mark IV.  It looks somewhat battle\n"+
      "damaged, but it is still in relatively good shape.  The engine is still running\n"+
      "and if you can probably 'board panzer' or attempt to 'jimi' the hatch.\n");
      unlock();
/*
   if (where == environment(this_object())) {
      move_object(this_object(), "players/silas/workroom");
     
   }
   where = environment(this_object());
   Causes problems during clone, as it should automaticaly be moved -Arthur
*/
}
query_ghost() { return 1;}
query_npc() {return 0;}  /* so mofo dont kick it into the void */
is_player() { return 1;} /* so i can find the dester */

init() {
   add_action("board", "board");
   add_action("jimi", "jimi");
   add_action("n","fsouth");
}
n() {
  command("south");
  return 1;
  }


board(arg) {
   if (!(arg)) return;
   if (locked == 0) {
      write("You board the Panzer.\n");
      tell_room("players/silas/private/inpanzer", this_player()->query_name() + " enters through the hatch.\n");
      move_object(this_player(), "players/silas/private/inpanzer");
      say(this_player()->query_name() + " boards the Panzer and disappears into the hatch.\n");
      return 1;
   }
   write("The hatch seems to be locked.\n");
   return 1;
}



lock() {
   locked = 1;
   say("The hatch on the Panzer slams shut and clicks.\n");
}
unlock() {
   locked = 0;
   say("The hatch on the Panzer pops open.\n");
}


jimi() {
   int max, occ;
   string enfi, tank, it, ob;
   if (!locked) {
      write("Its already unlocked!\n");
      return 1;
   }
   tank = find_living("panzer");
   enfi = "players/silas/private/inpanzer";
   tell_room("players/silas/private/inpanzer", "You hear a metallic scrabbling on the hatch.\n");
   say(call_other(this_player(), "query_name") + " attempts to jimi open the hatch.\n");
   write("You pry at the hatch with a sharp object.\n");
   occ = 0;
   ob = first_inventory(enfi);
   max = 20;
   while(ob && max > 0) {
      if (call_other(ob, "is_player")) {
         occ = 1;
         }
      max -= 1;
   }
   ob = next_inventory(ob);
   if (!occ) {
      call_other("players/silas/private/inpanzer", "unlock");
      return 1;
   }
   if (random(5) == 3) {
      call_other("players/silas/private/inpanzer", "unlock");
      return 1;
   }
   write("Your attempt fails.\n");
   return 1;
}

short() {
   string thang;
   if (locked) {
      thang = "locked";
   }
   if (!locked) {
      thang = "unlocked";
   }
   return "A German Panzer (" + thang + ")";
}
destruct_signal() {
   /*
   string name;
   name = call_other(this_player(), "query_real_name");
   name = capitalize(name);
   n = random(3);
   if (n== 0) {
      shout(name + " shouts:  I am such an idiot!!\n");
   }
   if (n==1) {
      shout ("The GameDriver thunders:  One more time and you're rm'ed, "+name+"!!!!\n");
      tell_object(this_player(), "The GameDriver thunders:  One more time and you're rm'ed, "+name+"!!!!\n");
   }
   if (n==2) {
      shout(name+" shouts:  Someone dest me quick!  I have a fatal error!!\n");
   }
   destruct("panzer", "hahahahah");
   */
}
