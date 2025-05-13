inherit "/room/room";
#define EXCALIBUR "players/goldsun/obj/excalibur"
#define LOC "players/goldsun/obj/location"

reset(arg){

 if (!arg){
 
  set_light(1);
  short_desc="Castle magic room";
  long_desc="You are in the Carmaalot magic room. The walls are made\n"+
	    "of shiny stone. In the middle os the room there is a pedestal\n"+
	    "here. Near the wall you can see the stairs leading up.\n";

 smell="You can smell some mystical smells";

 dest_dir=({ "/players/goldsun/guild/room/magic_shop" ,"up",
	     "/players/goldsun/guild/room/roundtable","south"});

 items=({"walls","The walls are made of shiny stone",
	 "wall","The wall is made of shiny stone",
	 "stairs","The starts leads up to the tower",
	 "stone","Very nice white shiny stone",
	 "shiny stone","Very nice white shiny stone",
	 "pedestal","@@query_pedestal@@"
       });

  }
 ::reset();
}
init(){
 ::init();
add_action("do_take","get");
add_action("do_take","take");
add_action("set_find","set");
}

int set_find(string str){
 if (str=="find" && this_player()->query_name()=="goldsun" ){
   write("Ok. You can take Excalibur now.\n");
   LOC->set_is_lost(0);
   return 1;
 }
}

int do_take(string str){
 
if (str=="sword from pedestal" || str=="sword" || str=="excalibur"
		|| str=="excalibur from pedestal"){

   if (LOC->query_is_lost()==1){
      write("Excalibur is lost by "+LOC->query_loose_who()+".\n");
      return 1;
   }

   if ( EXCALIBUR->query_is_old()){
      write("That is not here.\n");
      return 1;
   }
   if (present("knight_king_sign",this_player()))
     {
       write("You take a mystical sword from pedestal.\n");
       shout("A shiny lightning apears in the sky.\n");
       say(this_player()->query_name()+" takes Excalibur from the pedestal.\n");
       EXCALIBUR->set_is_old(1);
       if (move_object(EXCALIBUR,this_player())){
	     write("You can't carry that much.\n");
         }
       return 1;
      }

     /* not knight_king_sign   */

       write("You are not alloved to take this sword !\n");
       say(this_player()->query_name()+" tries to take Excalibur.\n");
       return 1;
 }
}


string query_pedestal()
 {
   if (!EXCALIBUR->query_is_old() &&
       !LOC->query_is_lost())  return "There is a mystical sword on it";
    else return "A marble pedestal";
 }

