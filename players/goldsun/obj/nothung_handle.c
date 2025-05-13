inherit "/obj/treasure";
#define TP this_player()
#define SAY(x) tell_room(environment(TP),x)

void reset(int arg){
 ::reset(arg);

 if (arg) return;
  set_name("handle");
  set_short("An old handle");
  set_long("An old rusty handle. It is made of excelent steel.\n"+
	   "There is written on it: If you have the proper blade, you can\n"+
	   "                         'call goldsun' to get whole sword.\n");
  set_value(100);
  set_weight(1);
}

init(){
 ::init();
add_action("do_call","call");
}
int do_call(string str){
 if (!present(this_object(),TP)) return 0;
 notify_fail("Call what?\n");
 if (str=="goldsun"){
   SAY("Sir Goldsun arrives.\n");
   if (present("goldsun_nothung_blade_12903",TP)){
     SAY("Goldsun takes blade and handle from "+TP->query_name()+".\n");
     SAY("Goldsun mumbles some strange powerful words.\n"+
	 "A shine ray links the handle and the blade.\n"+
	 "Sir Goldsun drops Nothung and says: Good Luck.\n"+
	 "Sir Goldsun disappearsin a puf of smoke.\n");
     destruct(present("goldsun_nothung_blade_12903",TP));
     move_object(clone_object("players/goldsun/obj/nothung.c"),
	environment(TP));
     destruct(this_object());
     return 1;
   }
   SAY("Sir Goldsun says: You haven't blade. Try to find it first.\n"+
	"Sir Goldsun disappears in a puf of smoke.\n");
   return 1;
 }
}
