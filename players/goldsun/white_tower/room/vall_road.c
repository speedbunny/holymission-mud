inherit "/room/room";
#define TP this_player()
#define TPN TP->query_name()

int is_curse, is_open, is_ring;

void no_curse(){ is_curse=0; }

reset(arg){
  is_open=0;
  is_curse=1;
  is_ring=1;

if (!arg){

 set_light(1);
 short_desc=("In the valley");
 long_desc=
   "You are in Moon valley. You can see tall rocky peaks to the north\n"+
   "and south. Valley continues to the east and west. There is a strange\n"+
   "heap at the foot of rocky peaks.\n";

 smell="The air smells dusty here";

 dest_dir=({ "/players/goldsun/white_tower/room/san",   "east",
	     "/players/goldsun/white_tower/room/moon_place", "west" });
 
 items=({ "valley","Moon valley to the east and west",
          "heap","A heap with huge rocky plate on it. It looks like tomb",
          "tomb","@@query_tomb@@",
          "plate","There is written 'Died in services.' on it"});

  }
 ::reset(arg);

}

string query_tomb(){
  if (is_open) return "It is opened";
   return "It is closed";
}


init(){
 ::init();
 add_action("open","open");
 add_action("enter","enter");
 add_action("search","search");

}

int open(string str){
 notify_fail("Open what?\n");
 if (is_open){ 
    write("It's already opened.\n");
    return 1;
 }
 if (str=="tomb" || str=="plate"){
    if (is_curse){
      write("A flash of black cursed power strikes you.\n");
      say(TPN+" tries to open "+str+" and a flash of black cursed power\n"+
           "strikes "+TP->query_possessive()+".\n");
      TP->misc_hit(10,5,0);
      return 1;
    }
    write("You open the tomb.\n");
    say(TPN+" opens a tomb.\n");
    is_open=1;
    return 1;
  }
}

int enter(string str){
  if (str=="tomb"){
    if (is_open){
      write("It is too small for you.\n");
      return 1;
    }
    write("Tomb is closed.\n");
    return 1;
  }
}

int search(string str){
object ring;
  if (str=="tomb"){
      if (is_open){
          if (is_ring){
             ring=clone_object("/players/goldsun/white_tower/obj/ring2");
             write("You search the tomb and find a ring.\n");
 	     say(TPN+" searches a tomb.\n");
             is_ring=0;
             if (transfer(ring,TP)){
                write("You can't carry that much.\n");
                transfer(ring,this_object());
             } 
             return 1;
           }
           write("Someone was faster than you.\n");
           return 1;
      }
      write("Tomb is closed.\n");
      return 1;
  }
}

