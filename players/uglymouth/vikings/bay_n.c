/* dunno yet... just some simple beach? */
inherit "room/room";

void reset(int arg) {
object ob;

   ob=present("megalith");
   if(ob) {
      tell_room(this_object(),"Suddenly you're caught in a small sand storm. \n");
      destruct(ob);
      }

   if(arg) return;

   set_light(1);
   short_desc="Somewhere north in the bay";
   long_desc="You walk on a sunny beach on the northern side of the bay. \n"
           + "Small waves of the blue sea come rolling in on the sand. \n"
           + "When you look out over the bay, you find dunes north, a \n"
           + "waterfall west and a jungle south. Southeast a dark \n"
           + "cloud disturbs the dreamlike view. To the east lies the clear, blue sea. \n";
   dest_dir=({
              "/players/uglymouth/vikings/bay_ne","northeast",
              "/players/uglymouth/vikings/bay_m","south",
              "/players/uglymouth/vikings/bay_nw","west", });
   items=({
           "beach","You have but one word for it: Paradise..",
           "waves","Watch out, salt slowly eats your boots away",
           "sea","On the clear blue sea a big ship lies at anchor",
           "bay","A calm peace of water giving out to the sea",
           "dunes","Small sandy hills",
           "sand","The wet sand you usually find at a beach near the water",
           "waterfall","It doesn't look so big, but it's very wild",
           "cloud","A dark cloud of smoke, as from burning houses..",
           "crow's nest","There is either a man with a horned helmet, or a horned humanoid",
           "ship","On its bow is a dragonhead carved in wood and on the stern \n"
                + "its tail. Round shields hang in a row on the side. You think \n"
                + "you see some movement in the crow's nest. Are these the \n"
                + "dreaded vikings...? \n",
           });
   }

void init() {
   ::init();
   add_action("search","search");
   add_action("search","dig");
   }

int search(string str) {
object mlith;
   if(str!="sand" && str!="hill") return 0;
   if(present("megalith")) {
      write("You find nothing unusual in the sand. \n");
      return 1;
      }
   write("You scratch your hand on a big black stone. You dig it up completely. \n");
   say(this_player()->query_name()+" digs up a big stone from the sand. \n",this_player());
   mlith=clone_object("/players/uglymouth/vikings/items/megalith");
   mlith->set_long("A tall rectangular stone. It's black and there are vaguely \n"
                 + "the remnants of some inscription visible. \n");
   mlith->set_read("The water has washed away so much that you can't read it anymore. \n");
   transfer(mlith,this_object());
   return 1;
   }

void vikings_leave() {
   items=({
           "beach","You have but one word for it: Paradise..",
           "waves","Watch out, salt slowly eats your boots away",
           "sea","A heavenly blue sea stretches towards the horizon",
           "bay","A calm peace of water giving out to the sea",
           "dunes","Small sandy hills",
           "sand","The wet sand you usually find at a beach near the water",
           "waterfall","It doesn't look so big, but it's very wild",
           "cloud","A dark cloud of smoke, as from burning houses..",
      });
   }

void vikings_arrive() {
   items=({
           "beach","You have but one word for it: Paradise..",
           "waves","Watch out, salt slowly eats your boots away",
           "sea","On the clear blue sea a big ship lies at anchor",
           "bay","A calm peace of water giving out to the sea",
           "dunes","Small sandy hills",
           "sand","The wet sand you usually find at a beach near the water",
           "waterfall","It doesn't look so big, but it's very wild",
           "cloud","A dark cloud of smoke, as from burning houses..",
           "crow's nest","There is either a man with a horned helmet, or a horned humanoid",
           "ship","On its bow is a dragonhead carved in wood and on the stern \n"
                + "its tail. Round shields hang in a row on the side. You think \n"
                + "you see some movement in the crow's nest. Are these the \n"
                + "dreaded vikings...? \n",
      });
   }
