inherit "players/redsexy/jedi/areas/island/inherit";
object sandcastle;

reset (arg) {     
if (arg) return;    
set_light(1);     

     short_desc="A sandy sandpit for you to play in!";
     long_desc="The sandpit is pretty much as you would expect it to be, " +
              "just covered in sand!  However, the sand here is more like " +
              "the stuff you would get on a beach than on the desert island " +
              "of Carkoon.  You feel happy in here and decide to play for a while. \n\n";    


items = ({                  
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
	        "ground","Soft sand for you to play with!",
              "sand","Soft sand for you to play with!"
  });
}
void init() {


   ::init();


   add_action("_leave","leave");
   add_action("_build","build");
   add_action("_destroy","destroy");
}

int _leave(string str) {
   if(str!="sandpit") return 0;
   write("You sadly leave the fun sandpit...\n");
   this_player()->move_player("leaves the sandpit, crying.#players/redsexy/jedi/areas/island/other/t3");
   return 1;
}

int _build(string str) {
   if(str!="sandcastle") return 0;
   write("You build a glorious sandcastle...\n");
   sandcastle=clone_object("players/redsexy/jedi/objects/sandcastle");
   move_object(sandcastle,this_object());
   return 1;
}

int _destroy(string str) {
   if(str!="sandcastle") return 0;
   write("You spitefully destroy the sandcastle, then something strange happens..\n");
   destruct (sandcastle);
   this_player()->move_player("crying, after ruining the sandcastle.#/players/redsexy/dimensions/connect/chamber");
   return 1;
}



