/* just a way to get back to the known world */
inherit "obj/thing";
int i;

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("mead");
      set_alias("supermead");
      set_short("A big mug of mead");
      set_long("A big mug of mead. It smells real strong. \n");
      set_value(0);
      }
   }

void init() {
   ::init();
   add_action("drink","drink");
   add_action("smell","smell");
   add_action("look","look");
   }

int smell(string str) {
   if(str!="mead" && str!="mug of mead") return 0;
   write("Your head almost starts spinning as you only smell this strong honey brew. \n");
   return 1;
   }

int drink(string str) {
   if(str!="mead" && str!="mug of mead") return 0;
   write("Your throat burns, but gets cooled by soft honey. \n"
       + "You feel the brew almost immediately enter your bloodstream and warm your body. \n"
       + "You feel sleepy. \n");
   call_out("hallucinate",5);
   return 1;
   }

void hallucinate() {
string msg;
   i++;
   if(i==1) msg="Suddenly your head seems to explode. \n";
   if(i==2) msg="Everyone around you seems to turn into spiders. \n";
   if(i==3) msg="The spiders turn into some green goo. \n";
   if(i==4) msg="The green goo slowly drips out of your eyes and everything becomes clear again. \n";
   if(i<4) {
      write(msg);
      call_out("hallucinate",5);
      return;
      }
   write(msg);
   this_player()->move_player("X#players/uglymouth/vikings/rock");
   destruct(this_object());
   return;
   }

int look(string str) {
string item;
   if(!str) {
      if(i==0) return 0;
      if(i==1) {
         write("You see fireworks explode from here to eternity. \n");
         return 1;
         }
      if(i==2) {
         write("There are dirty, hairy spiders all around you. \n");
         return 1;
         }
      if(i==3) {
         write("You find yourself in a huge pool of bright green, sticky goo. \n");
         return 1;
         }
      }
   if(sscanf(str,"at %s",item)!=1) return 0;
   if(present(item,this_player())) return 0;
   if(i==0) return 0;
   if(i==1) {
      write("With a loud 'BANG!!' it explodes in your hand. \n");
      return 1;
      }
   if(i==2) {
      write("It's turned into a big hairy spider and climbs up your leg... \n");
      return 1;
      }
   if(i==3) {
      write("It's turned into sticky, bright green goo that drips from your fingers. \n");
      return 1;
      }
   }
