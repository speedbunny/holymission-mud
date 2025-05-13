inherit "/room/room";
#define TP this_player()

int i;
reset(arg){
 i=1;
 if (!arg){
 set_light(0);
 short_desc=("Secret room");
 long_desc="You are in the secret room. Whole room is very dusty.\n";
 
  smell="Hachooo. You smell dust.";
  no_obvious_msg="";

 items=({ "wall","It looks strange. Maybe you can push it",
	  "dust","A lot of dust. It can hide something and nobody would find it"
        });

 }
 ::reset(arg);
}

init(){
 ::init();
 add_action("push","push");
 add_action("hide","hide");
 add_action("search","search");
}

int hide(string str){
string what;

 if (!str) return 0; /* for thiefs */
 notify_fail("Hide what where ?\n");
 if (sscanf(str,"%s in dust",what)==1){
  if (present(what,TP)){
     destruct( present(what,TP) );
     write("You hide "+str+".\n");
  }  else write("You haven't "+what+".\n");
  return 1;
 }
 return 0;
}
 
int search(string str){
 notify_fail("Search what ?\n");
 if (str=="dust"){
     write("You search the dust.\n");
    say(TP->query_name()+" searches the dust.\n");
   if (i){
    write("You find a small diamond.\n");
    i=0;                                                        /* ??? */
    say(TP->query_name()+" searches the dust.\n");
    move_object(clone_object("/players/goldsun/nottingham/obj/d"),this_object());
   }
  return 1;
 }
 return 0;
}

int push(string str){
 notify_fail("Push what ?\n");
 if (str=="west wall"){       /*  !!! */
   TP->move_player("suddenly#/players/goldsun/nottingham/room/castle/tower3");
   return 1;
 }
 return 0;
}
