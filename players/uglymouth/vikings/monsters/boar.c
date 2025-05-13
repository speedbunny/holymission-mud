/* Frej's boar */
inherit "obj/monster";
int j,k;
string msg;

void reset(int arg) {
   ::reset();
   k=0;
   j=0;

   if(!arg) {
      set_name("frej's boar");
      set_alias("boar");
      set_short("Frej's boar");
      set_long("Frej's boar is as big as an elephant, dark as the night \n"
             + "and it has very sharp tusks. It looks you straight in the eyes. \n");
      set_level(10);
      set_al(-300);
      set_race("devine boar");
      }
   }

void init() {
   ::init();
   add_action("jump","jump");
   }

void charge() {
   if(k==0) msg="Frej's boar starts to scrap its hoofs. \n";
   if(k==1) msg="Frej's boar starts to C H A R G E !! \n";
   if(k==2) msg="Frej's boar has moved one third of the distance and it's moving fast. \n";
   if(k==3) msg="Two thirds. Jump away or before it's too late. \n";
   if(k==4) msg="Almost there... be quick! \n";
   if(k<4) {
   tell_room(environment(this_object()),msg);
      call_out("charge",5);
      k=k+1;
      return;
      }
   if(k==4) {
   tell_room(environment(this_object()),msg);
      call_out("charge",5);  /* should be enough time */
      k=k+1;
      return;
      }
   if(k>4) {
   if(j==1) {
      tell_room(environment(this_object()),"You jump away just in time and the boar disappears in the distance. \n"
          + "Loki growls disappointed. \n");
      environment(this_object())->set_busy(0);
      destruct(this_object());
      return;
      }
   tell_room(environment(this_object()),"Aaarrgg! B A N G ! All goes black. \n");
   this_player()->move_player("flying#players/uglymouth/vikings/cave");
   environment(this_object())->set_busy(0);
   environment(this_object())->failed_test();
   destruct(this_object());
   return;
   }
}

int jump(string str) {
   if(!(!str || str=="away" || str=="boar")) return 0;
   if(k<5) {
   write("You jump, but the boar easily manages to change its direction again towards you.\n");
      return 1;
      }
   write("You jump away. \n");
   j=1;
   return 1;
   }
