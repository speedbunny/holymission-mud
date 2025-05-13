#define RELIGION "Mask"
#define RLM "/religion/master"
#define TP this_player()
#include "/obj/lw.h"

inherit "room/room";

int heal_score;

recalc_power_level() { return 20; }

reset(arg) {
  heal_score=40;
  if (!arg) {
    set_light(1);
    short_desc="The Dark Temple";
    long_desc=
 "Darkness covers this room.  Plain black walls surround the room.  A\n"+
 "distorted statue carved out of obsidian stands against the northern wall.\n"+
 "A black altar for sacrificing lies in the center of the room.\n";
    
    dest_dir=({
      "/players/blade/guild/room.c","north", 
      "/players/blade/guild/contest/scroll_room.c","east"
    });
    items=({
      "altar", "A large block of obsidian with a red cloth over it",
        "cloth", "A red cloth that is draped over the altar",
        "wall", "Which of the walls",
        "walls","The walls are a dark black color and carved out of obsidian",
        "west wall", "In the west wall is an exit back to the guild",
        "east wall", "It has a small door to an eastern room",
        "statue","You are afraid of it, and cannot look at it",
      });
    
    property=({ "has_fire" });
    smell="The smell of evil is here.";
  }
}

init() {
  ::init();
    if(this_player()->query_religion()==RELIGION) {
    call_out("kneel_altar",1);
    call_out("stand_up",5);
  }
    add_action("remove_ghost","pray"); 
    add_action("sacrifice","sacrifice");
  }

int sacrifice(string str_arg){
  object sac_item;
  if(!str_arg){
    tell_object(this_player(),"You think about sacrificing something.\n");
    return 1;
  }
  else{
    if(sac_item=present(str_arg,this_player())){
      say(this_player()->query_name()+" sacrifices "+str_arg+
          " upon the altar.\n",this_player());
      write("You sacrifice "+str_arg+" upon the altar.\n");
      destruct(sac_item);
    }
    else{
      write("You notice that you do not have a "+str_arg+" to sacrifice.\n");
    }
  }
  return 1;
}

int kneel_altar(){
  if(present(this_player(),this_object())){
  say(this_player()->query_name()+" kneels before the altar.\n",this_player());
  tell_object(this_player(),
              "You kneel before the altar in reverence of Mask.\n");
}
  return 1;
}

stand_up(){
  if(present(this_player(),this_object())){
    say(this_player()->query_name()+" stands up.\n");
    write("You leave the altar knowing that Mask watches over you.\n");
    if(heal_score){
      this_player()->heal_self(5);
      heal_score-=5;
    }
  }
}

remove_ghost(str) {
  string belief;
  object church;
  
  belief=this_player()->query_religion();
  if(!belief) {
    write("You now know that Mask is the true God.\n");
    this_player()->set_religion(RELIGION);
    return 1;
  }
  if(belief!=RELIGION) {
    church = RLM->query_church(TP->query_religion());
    if(church->leave_religion(belief)) {
      write("You begin to see the power of the God Mask.\n");
      command("grin demonically");
      this_player()->set_religion(RELIGION);
      return 1;
    }
  }
  if(!this_player()->remove_ghost()){
    write("You pray before the altar of Mask.\n");
    call_out("stand_up",5);
    return 1;
  } 
this_player()->set_smell("Smells as if just returned from the fires of hell.");
  return 1;
}

try_attack(ob) {
  
  tell_object(ob,"Mask does not want thieves to fight one another.\n");
  say("Mask becomes angry at "+ob->query_name()+".\n",ob);
  return 1;
}

int leave_religion(string preli) {
  if(TP->query_religion() != "Mask") return 0;
  return 1;
}



















