/* this is the first room in a series about a viking invasion */
inherit "room/room";
int shells;

void reset(int arg)   {
   shells=5;
   if(arg) return 0;

   set_light(1);
   short_desc="A quiet piece of shore";
   long_desc="You're walking on a quiet piece of shore, \n"
           + "heading towards a small bay behind the dunes. \n"
           + "The sun is shining on your face, the birds in the air whistle their tunes. \n"
           + "Shells lie scattered over the beach. The wind blows softly through your hair. \n"
           + "It's a lovely day. What could go wrong? \n";
   dest_dir=({
      "/room/vill_shore4","north",
      "/players/uglymouth/vikings/shallow","east",
      "/players/uglymouth/vikings/dunes_e","south",
      "/players/uglymouth/vikings/dunes_n","west",
      });
   items=({
      "dunes","Small sandy hills covered with long dry grass",
      "grass","It's long and dry. You wouldn't feed it to your horse",
      "birds","Mostly seagulls flying overhead, searching for food",
      "beach","You walk on a lovely white beach",
      "shells","All kinds of shells you can find here",
      });

   }

void init() {
   ::init();
   add_action("search","search");
   }

int search(string str) {
int i;
   if(str!="shells") return 0;
   if(shells <= 0) return 0;
   i=random(10);
   if(i<6) {
      write("You find nothing special. \n");
      return 1; }
   write("You find a shell which shape reminds you of something... \n");
   say(this_player()->query_name()+" searches among the shells and finds a special one.\n",this_player());
   transfer(clone_object("/players/uglymouth/vikings/items/oyster"),this_player());
   shells--;
   return 1;
   }
