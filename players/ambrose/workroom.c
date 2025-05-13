#define NAME "ambrose"
#define RN this_player()->query_real_name()
inherit "room/room";
int shield;
string who;
#define CNAME capitalize(NAME)

int i;
reset(arg){
  if(arg) return;
    set_light(1);
    short_desc="The workroom of Ambrose.",
    long_desc=
    "You are in Ambroses workroom.  It is on top of a round tower in\n"
   +"the northwest section of Avalon.  There are 4 windows looking out\n"
   +"at the city and surrounding wilderness.  The remaining wall space\n"
   +"is taken up bookcases crammed with all kind of tomes and scrolls.\n"
   +"There are several low couches to relax on, and a large desk with\n"
   +"a strange rectangular device on top.  In the very center of the\n"
   +"room is a pentagram which seems to burn with a eldritch blue fire.\n"
   +"There is a spiral stairway leading down by the desk.\n";

    dest_dir=({
      "/players/ambrose/avalon/entrance/entran1","entrance",
      "room/bank","bank",
      "room/main_shop","shop",
      "room/post","post",
      "room/church","church",
      "room/adv_guild","advguild",
      "/players/whisky/magic/mages_bar","magebar",
     });
   items=({
      "shelves","These shelves are crammed with books of a arcanic lore.",
      "books","These are Ambrose's books, DON'T TOUCH!",
      "book","These are Ambrose's books, DON'T TOUCH!",
      "pentagram","A glowing pentagram on the floor, it scares you.",
      "couches","They look well used and comfy.",
      });
   
    smell="This room smells like old books.";
  }

init(){
   ::init();
   add_action("set_shield","shield");
   add_action("expel","expel");
   check();
  }

set_shield(str){
 if((RN !="ambrose") && (RN !="sonja")) return;
 if(!str) {
   write("Shield is currently " + shield +".\n");
   return;
  }
if(str == "on"){
    write("You cast a spell and put a shield around the room.\n");
    say("Ambrose waves his hands and the windows glow.\n");
    shield=1;
    return 1;
  }
  if(str=="off"){
    write("You cast a spell and shut the shield down.\n");
    say("Ambrose waves his hands and windows stop glowing.\n");
    shield=0;
    return 1;
   }
 }

check(){
  if(shield && (RN !="ambrose") && (RN !="sonja") && (RN !="moriarty")){
   write("You failed to enter Ambrose's workroom.\n");
   say(this_player()->query_name() +
  "tries to enter but is blocked by the shield.\n");
   move_object(this_player(),"/room/void");
  }
  return 1;
}

expel(arg){
  object player;
  if((RN !="ambrose") && (RN !="sonja")) return;
  if(!arg){
     write("Expel whom?\n");
     return 1;
   }
   player = present(arg, this_object());
   if(!player){
     write("That player is not here.\n");
     return 1;
   }
   write("You expel" + player->query_name() +".\n");
   player->move_player("to the church#/room/church");
   tell_room(this_object(), player->query_name() +
    "got expelled to the church.\n");
   return 1;
}
