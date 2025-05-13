/* the last puzzle in Walhalla */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   property = "no_teleport";
   short_desc="A circular room, entirely made of ash wood";
   long_desc="This is a high and wide circular room. It's entirely made of ash wood. \n"
           + "Small particles in the air glow and give the room a warm reddish brown light. \n"
           + "Evenly divided over the circular wall there are nine doors, each with a \n"
           + "small bronze plaquette on it. In the centre a shield is floating in the air. \n";
   items=({
      "wood","The wood must be ancient, considering its structure",
      "structure","It's a very dence and crude structure",
      "particles","Small dust particles, giving off a reddish brown light",
      "air","It's filled with glowing particles",
      "light","A warm reddish brown light",
      "doors","Ash wooden turning doors, numbered 1 to 9",
      "plaquette","There's an inscription engraved in each one",
      "shield","A viking shield. There's something written on it",
      });
   smell="The dusty smell of old wood fills your nose. \n";
   }

void init() {
   ::init();
   add_action("enter","enter");
   add_action("read","read");
   add_action("list","list");
   }

int enter(string str) {
string thing,destworld,destfile;
int number;
   if(sscanf(str,"%s %d",thing,number)!=2) return 0;
   if(thing!="portal" && thing!="door") return 0;
   if(number<1 || number>9) {
      write("Which door do you want to enter? \n");
      return 1;
      }
   if(number==1) {
      destworld="Alfheim";
      destfile="/players/patience/tree_city1/oelm";
      ("/players/uglymouth/vikings/walhalla")->failed_test();
      }
   if(number==2) {
      destworld="Muspelheim";
      destfile="/players/ted/fire/gate";
      ("/players/uglymouth/vikings/walhalla")->failed_test();
      }
   if(number==3) {
      destworld="Jotunheim";
      destfile="/room/giant_conf";
      ("/players/uglymouth/vikings/walhalla")->failed_test();
      }
   if(number==4) {
      destworld="Swergheim";
      destfile="/room/mine/tunnel16";
      ("/players/uglymouth/vikings/walhalla")->failed_test();
      }
   if(number==5) {
      destworld="Svartalfheim";
      destfile="/players/herp/orc/u4";
      ("/players/uglymouth/vikings/walhalla")->failed_test();
      }
   if(number==6) {
      destworld="Midgard";
      destfile="/players/uglymouth/vikings/camp2";
      ("/players/uglymouth/vikings/walhalla")->failed_test();
      }
   if(number==7) {
      destworld="Asgard";
      destfile="/players/uglymouth/vikings/walhalla";
      }
   if(number==8) {
      destworld="Niflheim";
      destfile="/players/ted/frost/base";
      ("/players/uglymouth/vikings/walhalla")->failed_test();
      }
   if(number==9) {
      destworld="Hel";
      destfile="/players/patience/shadows/gy4";
      ("/players/uglymouth/vikings/walhalla")->failed_test();
      }
   write("Prepare, my friend! You've chosen the portal to " + destworld + " \n\n");
   this_player()->move_player("X#" + destfile);
   return 1;
   }

int read(string str) {
string thing,msg;
int number;
   if(!str) return 0;
   if(str=="shield") {
      write("The runic inscription reads: \n"
         + "From this room portals lead to all of the nine worlds. Some are good, \n"
         + "some bad and some are in between. Type 'list worlds' for more detail. \n"
         + "Only one portal leads back to the realm of the Gods. The statement on that \n"
         + "door is true. The other portals lead either to evil places, or to neutral \n"
         + "worlds. The doors leading to the former portals contain a false statement, \n"
         + "the statement on the doors to the latter portals can be true or false. \n"
         + "Choose the door that leads back to Asgard. Know that people have done it \n"
         + "before, although not often. Do not despair! \n\n"
         + "Note: The text on doors 8 and 9 are considered false only if both statements \n"
         + "on that door are not true. \n");
      return 1;
      }
   if(sscanf(str,"%s %d",thing,number)!=2) return 0;
   if(thing!="door" && str!="portal") return 0;
   if(number<1 || number>9) {
      write("Which door do you want to read? \n");
      return 1;
      }
   if(number==1) msg="The portal to Asgard can only be accessed by a door with an odd number. \n";
   if(number==2) msg="The portal beyond this door leads to a neutral world. \n";
   if(number==3) msg="At least one of these statements is true: \n   Door 5 speaks truth. \n   Door 7 speaks not truth. \n";
   if(number==4) msg="Door 1 tells lies. \n";
   if(number==5) msg="At least one of these statements is true: \n   Door 2 does not lie. \n   Door 4 does not lie. \n";
   if(number==6) msg="Door 3 does not give a correct statement. \n";
   if(number==7) msg="The portal beyond Door 1 does not bring you to Asgard. \n";
   if(number==8) msg="This portal leads to an evil world and Door 9 leads to a neutral world. \n";
   if(number==9) msg="This portal leads to an evil world and Door 6 is not true. \n";
   write(msg);
   return 1;
   }

int list(string str) {
   if(str!="worlds") return 0;
   write("Summary on the Nine Worlds: \n"
      + "   Asgard       - home of the Gods (good) \n"
      + "   Muspelheim   - home of the Fire Giants (evil) \n"
      + "   Niflheim     - home of the Frost Giants (evil) \n"
      + "   Hel          - home of the Queen of the Undead (evil) \n"
      + "   Svartalfheim - home of the Dark Elves and their relatives (evil) \n"
      + "   Jotunheim    - home of the Giants and their relatives (neutral) \n"
      + "   Alfheim      - home of the elves and their relatives (neutral) \n"
      + "   Swergheim    - home of the Dwarves and their relatives (neutral) \n"
      + "   Midgard      - home of the Humans (neutral) \n"
      + "...As noted by Father Odin, in his wisdom. \n");
   return 1;
   }
