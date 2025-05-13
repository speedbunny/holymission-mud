#define NAME "bobo"
inherit "room/room";
int shield;
string who;
int i;
#define CNAME   capitalize(NAME)
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc="Bobo's Place";
   long_desc=
	"You have been invited, or just vome to Bobo's workroom.  It's been\n"+
	"known to include many things. Just what is in here is hard to ssay\n"+
	"because of the the fact that there are many different facets to\n"+
	"bobo and so at any one time there could be many different things in\n"+
	"the room. In whatever he does though there is always one constant.\n"+
	"Music. His CD player is in the corner and is playing something\n"+
	"awesome.\n";
   dest_dir=({
	"/room/church","church",
	"/players/tatsuo/guild/room","guild",
	"/room/post","post",
	"/players/matt/newworld/city/rooms/votebooth","vote",
   });
   items=({
	"cd player","It's just a small boombox but it plays fairly well",
	"air","It's very thin up here",
        "floor","The floor is dirty",
   });
   property=({
	"no_teleport","no_sneak","no_steal",
   });
   smell="It smells faintly of chlorine...";
}

init() {
  ::init();
   add_action("set_shield","shield");
   add_action("expel","expel");
   check();
}

set_shield(str) {
   if(this_player()->query_real_name() !="bobo") return;
   if(!str) {
      write("Shield is currently "+shield+".\n");
      return;
   }
   if(str == "on") {
      write("You seal the room off from people on the outside.\n");
      say("Bobo seals the room from other visitors.\n");
      shield=1;
      return 1;
   }
   if(str == "off") {
      write("You allow people to teleport back in here if they desire\n");
      say("Bobo allows people to enter and exit as they wish.\n");
      shield=0;
      return 1;
   }
}

check() {
   if(shield && (this_player()->query_real_name() != "bobo")) {
      write("Fuck off and go away.");
      say(this_player()->query_name()+" tried to come in.\n");
   }
   return 1;
}

expel(arg) {
   object player;
   if(!arg) {
       write("Who's that again?\n");
       return 1;
   }
   player = present(arg, this_object());
   if(!player) {
      write("They're not here.\n");
      return 1;
   }
   write("You give "+this_player()->query_name()+" the boot.\n");
   player->move_player("to be incinerated#/players/whisky/garden/room/oven");
   tell_room(this_object(), this_player()->query_name()+ "got the boot.\n");
   return 1;
}
