inherit "obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
 set_id("ring");
 set_type("ring");
 set_short("A golden ring");
 set_long("A golden ring. It looks very expensive but there is something missing "+
   "\non it.\n");
 set_ac(1);
 set_value(1000);
 set_weight(1);
 }

init(){
 ::init();
 add_action("put","put");
}

int put(string str){
 if (str=="diamond in ring"){
   if (present("nottingham diamond",this_player())){
	 write("You put a diamond in the ring.\n");
	 destruct(present("nottingham diamond",this_player()));
	 move_object(clone_object("/players/goldsun/nottingham/obj/d_ring"),
	   this_player());
	 destruct(this_object());
	 return 1;
   }
   write("You haven't proper diamond.\n");
  return 1;
 }
}
