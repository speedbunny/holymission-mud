/* last bay before the jungle */
inherit "room/room";
int count;

void reset(int arg) {

   count=3;
   if(arg) return;

   set_light(1);
   short_desc="You are just north of a dense jungle";
   long_desc="You are at the most southwestern corner of the bay. \n"
           + "South of you starts a dense jungle. To the north rushes a \n"
           + "waterfall into a pool with great force. The pool gives out \n"
           + "into a stream that carries the overflow to the sea. Very tiny \n"
           + "birds suck nectar out of tropical flowers growing at the edge of the jungle. \n";
   dest_dir=({"/players/uglymouth/vikings/bay_mw","north",
              "/players/uglymouth/vikings/bay_s","east",
              "/players/uglymouth/vikings/jungle_w","south", });
   items=({"bay","A white beach surrounding a calm part of the sea",
           "jungle","A dense jungle, in which you could easily get lost",
           "waterfall","A violent waterfall, at the top disappearing in a cloud",
           "cloud","A white cloud of fog",
           "pool","The waterfall makes it swirling wildly",
           "stream","Too wide to jump, but it has stepping stones to take you across",
           "sea","A calm blue sea",
           "birds","Some hummingbirds flying around",
           "hummingbirds","Some hummingbirds are sucking nectar from flowers",
           "flowers","Some tropical flowers in various colours", });

   clone_list = ({ 1, 3, "hummingbird", "obj/monster",
      ({ "set_name","hummingbird","set_alias","bird","set_level",1 })
      });
   ::reset();
   }

void init() {
   ::init();
   add_action("pick","get");
   add_action("pick","take");
   add_action("pick","pick");
   }

int pick(string str) {
object bird,flower;
int i;
string *colour;
colour=allocate(8);
   if(str!="flower") return 0;
   if(bird=present("hummingbird")) {
      write("A hummingbird pecks at your hand as you try to take its flower. \n");
      return 1;
      }
   if(!count) {
      write("There are no flowers left. \n");
      return 1;
      }
   i=random(8);
   colour=({"white","red","yellow","blue","green","pink","purple","orange",});
   write("You pick a beautiful "+colour[i]+" flower. \n");
   flower=clone_object("/players/uglymouth/vikings/items/flower");
   flower->set_long("It has a crown of long leafs of almost transparant "+colour[i]+". \n");
   transfer(flower,this_player());
   count--;
   return 1;
   }
