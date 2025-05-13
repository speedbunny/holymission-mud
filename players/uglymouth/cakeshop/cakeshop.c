/* Here you can buy weddingcakes */
inherit "room/room";
int *choices,cakenr,*value_of_cake;
string bride,groom;
object baker;

reset(arg) {
   if(arg) return;

   set_light(1);
   short_desc="Candy's Confectioner's Shop";
   long_desc="You have entered Candy's Confectioner's Shop. \n"
      + "It's a small shop with a pleasant atmosphere. Candy is specialized in \n"
      + "baking wedding cakes. All along the walls hang pictures of cakes. On a \n"
      + "marble counter lies a sign that explains how to order a wedding cake. \n"
      + "A small round door leads north. \n";
   dest_dir=({
      "/players/uglymouth/newvillage/street6","east",
      });
   hidden_dir=({
      "/players/uglymouth/cakeshop/storeroom","north",
      });
   items=({
      "walls","Pleasantly decorated with yellow wallpaper. Pictures of cakes hang on them",
      "wallpaper","It's yellow with tiny wedding cakes printed on it",
      "pictures","Pictures of the prize winning cakes Candy has baked",
      "counter","A counter of red marble. A tiny imp is hiding under it",
      "imp","An ugly green imp, smiling demonically. \n"
          + "The imp tells you: For 20 coins I'll give you a big, sticky cream pie",
      "sign","A copper plaque engraved with words. Read it",
      });
   smell="The sweetness of delicious cakes fills the shop. \n";
   property=({ "no_teleport","no_fight" });

   baker = clone_object("/players/uglymouth/cakeshop/baker");
   transfer(baker,this_object());
   value_of_cake = allocate(4);
   value_of_cake = ({ 3000,5000,7000,10000 });
   }

init() {
   ::init();
   add_action("east","east");
   add_action("north","north");
   add_action("read_sign","read");
   add_action("order_cake","order");
   add_action("order_cake","buy");
   add_action("choose_it","choose");
   add_action("show_cake","show");
   add_action("bake_cake","bake");
   add_action("cancel_it","cancel");
   add_action("pay_imp","give");
   }

east() {
string prefix;   
   if(present("cake bought by " + this_player()->query_real_name(),baker)) {
      write("Please finish your order before you leave. \n");
      return 1;
      }
   prefix = "Master";
   if(this_player()->query_gender() == 2) prefix = "Mistress";
   write("Candy tells you: Thank you and goodbye, " +prefix+" "+this_player()->query_short_name()+ ". \n"
       + "    I hope I may serve you again one day. \n");
   return;
   }

north() {
   if(!(this_player()->query_immortal())) {
      write("Candy won't let you in. \n");
      return 1;
      }
   write("Candy warns you not to make a mess there. \n");
   return;
   }

read_sign(str) {
   if(str!="sign" && str!="list of materials" && str!="list of designs") return;
   if(str=="sign") {
      write("*** CANDY'S CONFECTIONER'S SHOP *** \n    for all your wedding cakes\n\n"
         + "To serve everybody's purse, you can buy 4 different sizes: \n\n"
         + "1. Two-storey   high wedding cake    -    3000 coins \n"
         + "2. Three-storey high wedding cake    -    5000 coins \n"
         + "3. Four-storey  high wedding cake    -    7000 coins \n"
         + "4. Five-storey  high wedding cake    -   10000 coins \n\n"
         + "Read also our 'list of designs' and 'list of materials'. \n"
         + "Please, 'order cake <number> for <bride> and <groom>'. \n"
         + "Thank you. \n");
      if(this_player()->query_immortal()) {
         write("Wizinfo: Detailed info about this shop can be found in \n"
             + "         /players/uglymouth/cakeshop/cakeshop.doc \n"
             + "         Have fun,   Viking Lord Uglymouth (the manager) \n");
         }
      say(this_player()->query_short_name() + " reads the sign. \n",this_player());
      return 1;
      }
   if(str=="list of designs") {
      write("CANDY'S CONFECTIONER'S SHOP serves the following designs, per storey: \n\n"
      + "1. Glittering layer of material with spirals casting harmless sparks around. \n"
      + "2. Smooth layer of material with dragons breathing wine. \n" 
      + "3. Pie covered with icing with moving wheels on it. \n" 
      + "4. Layer with a waving surface and ships sailing on it. \n\n" 
      + "Once you've ordered a cake, shape it like this: \n"
      + "'Choose design <number> for storey <number>', or 'choose design random'. \n"
      + "Use 'show cake' to see what you've done, and 'bake cake' if you are satisfied \n"
      + "with your choice of designs and materials. Enjoy your cake. \n");
      return 1;
      }
   if(str=="list of materials") {
      write("CANDY'S CONFECTIONER'S SHOP offers the following tasty materials: \n\n"
      + "1. Blue autumn fruits icecream with decorations of silvery sugar. \n"
      + "2. Red fruits jelly with decorations of white cream. \n"
      + "3. Brown chocolate cake with decorations of white chocolate. \n"
      + "4. Mixed nuts cake with decorations of green pistachio. \n\n"
      + "Once you've ordered a cake, shape it like this: \n"
      + "'Choose material <number> for storey <number>', or 'choose material random'. \n"
      + "Use 'show cake' to see what you've done, and 'bake cake' if you are satisfied \n"
      + "with your choice of designs and materials. Enjoy your cake. \n");
      return 1;
      }
   }

order_cake(str) {
int i;
object cake; /* ,baker; */ 
   if(sscanf(str,"cake %d for %s and %s",cakenr,bride,groom)!=3) return;
/*   baker=present("candy, the chief confectioner");  */
   if(!baker) {
      write("Candy is not present right now. Please come back later. \n");
      return 1;
      }
   if(cakenr < 1 || cakenr > 4) {
      write("That cake is not available. Please read the sign for our selection. \n");
      return 1;
      }
   if(present("cake bought by " +this_player()->query_real_name(),baker)) {
      write("You've already ordered a cake. Finish that cake before you order a new one. \n");
      return 1;
      }
   if(present("wedding cake",baker)) {
      write("Candy tells you: A moment of your patience, please, I'm helping another \n"
      + "customer right now. \n");
      return 1;
      }
   if(this_player()->query_money() < value_of_cake[cakenr-1] ) {
      write("Candy tells you: I have a business to run. Please bring enough money. \n");
      return 1;
      }
   cake=clone_object("/players/uglymouth/cakeshop/cake" + cakenr);
   cake->set_alt_name("cake bought by " + this_player()->query_real_name());
   transfer(cake,baker);
   write("You order cake " + cakenr + ". \n"
      + "The chief confectioner starts working. \n"
      + "After a while she stands with a frame in her hands. \n"
      + "Candy tells you: You can tell me the details now. \n");
   say(this_player()->query_short_name() + " orders a cake. \n");
   choices=allocate(cakenr*2+1);
   for(i=0;i<cakenr*2+1;i++) {
      choices[i]=0;
      }
   return 1;
   }

show_cake(str) {
string *dlist,*mlist;
int i,j;
/* object baker; */
   if(str!="cake") return;
/*   baker=present("candy, the chief confectioner");  */
   if(!(present("cake bought by " +this_player()->query_real_name(),baker))) {
      write("You have not ordered a cake. \n");
      return 1;
      }
   dlist=({"*not yet chosen*","spirals","dragons","wheels","ships" });
   mlist=({"*not yet chosen*","icecream      ","fruits jelly  ","chocolate cake","nuts cake     "});
   write("Your cake currently looks like this: \n"
       + "Storey " + (cakenr+1) + ": images of the bride and groom  \n");
   for(i=cakenr*2;i>0;i=i-2) {
      j=i/2;
      write("Storey " + j + ": " +mlist[choices[i-1]]+ " with " +dlist[choices[i]]+ "\n");
      }
   return 1;
   }

choose_it(str) {
int desnr,matnr,stonr,i;
   if(!(present("cake bought by " +this_player()->query_real_name(),baker))) {
      write("You have not ordered a cake. \n");
      return 1;
      }
   if(str=="design random") {
     for(i=1;i < (sizeof(choices)/2+1);i++) {
        choices[i*2] = random(4) + 1;
        }
     write("Candy thinks for a while and then decides on a nice composition. \n");
     return 1;
     }
   if(sscanf(str,"design %d for storey %d",desnr,stonr)==2) {
      if(stonr > cakenr) {
         write("There are not that many storeys in the cake. \n");
         return 1;
         }
      if(desnr < 1 || desnr > 4) {
         write("That design is currently not available.\n");
         return 1;
         }
      if(choices[stonr*2]!=0) {
         write("You change the design. \n");
         choices[stonr*2] = desnr;
         return 1;
         }
      write("You choose a design. \n");
      choices[stonr*2] = desnr;
      return 1;
      }
   if(str=="material random") {
     for(i=1;i < (sizeof(choices)/2+1);i++) {
        choices[i*2 - 1] = random(4) + 1;
        }
     write("Candy thinks for a while and then decides on a nice composition. \n");
     return 1;
     }
   if(sscanf(str,"material %d for storey %d",matnr,stonr)==2) {
      if(stonr > cakenr) {
         write("There are not that many storeys in the cake. \n");
         return 1;
         }
      if(matnr < 1 || matnr > 4) {
         write("That material is currently not available.\n");
         return 1;
         }
      if(choices[stonr*2-1]!=0) {
         write("You change the material. \n");
         choices[stonr*2-1] = matnr;
         return 1;
         }
      write("You choose a material. \n");
      choices[stonr*2-1] = matnr;
      return 1;
      }
   return;
   }

bake_cake(str) {
int i,j;
object cake,store,bill;  /* ,baker; */
   if(str!="cake") return;
/*   baker=present("candy, the chief confectioner");  */
   cake = present("cake bought by " + this_player()->query_real_name(),baker);
   if(!cake) {
      write("Candy tells you: You haven't ordered a cake, so I can't bake it. \n");
      return 1;
      }
   j=0;
   for(i=1;i<(2*cakenr)+1;i++) {
      if(choices[i]==0) j++;
      }
   if(j > 0) {
      write("Candy tells you: You haven't told me all the details yet.\n");
      return 1;
      }
   cake->set_choices();
   cake->set_bride(bride);
   cake->set_groom(groom);
   ("/players/uglymouth/cakeshop/storeroom")->dummy();
   store = find_object("/players/uglymouth/cakeshop/storeroom");
   transfer(cake,store);
   this_player()->add_money( -value_of_cake[cakenr-1] );
   bill = clone_object("/players/uglymouth/cakeshop/bill");
   transfer(bill,this_player());
   write("Candy bakes the cake, whistling a merry melody. \n"
       + "When it's ready the cake really looks like a masterpiece. \n"
       + "Candy puts it safely away in the storeroom, gives you a bill\n"
       + "and collects her money.\n"
       + "Candy tells you: In the room you want it, just type 'bring the cake' and \n"
       + "it will be done. Until then, keep your bill, as it's the only proof you have \n"
           + "that you bought a cake here. \n");
   say("Candy starts baking a cake for " + this_player()->query_short_name() + " , whistling a merry melody. \n"
     + "When it's ready, the cake is put in a storeroom and the bill is paid. \n",this_player());
   return 1;
   }

query_choices(i) {
   return choices[i];
   }

cancel_it(str) {
object cake,store;   
   if(str!="order") return;
   cake=present("cake bought by " + this_player()->query_real_name(),baker);
   ("/players/uglymouth/cakeshop/storeroom")->dummy();
   store = find_object("/players/uglymouth/cakeshop/storeroom");
   if(!cake) {
      if(!(present("cake bought by " + this_player()->query_real_name(),store))) {
         write("Candy says: You haven't ordered a cake, so don't play jokes on me. \n");
         return 1;
         }
      write("Candy sighs disappointedly. \n"
          + "Candy says: Why waste such a delicious cake...? \n"
          + "I think I will invite some friends and have a party tonight. \n"
          + "Candy gives you back some of your money. \n");
      say(this_player()->query_short_name() + " cancels an order for a cake. \n",this_player());
      this_player()->add_money(500);
      return 1;
      }
   write("Candy sighs disappointedly. \n"
       + "Candy says: Too bad... I had such a splendid idea for it, but... \n"
       + "the customer is king in this shop: your order is cancelled. \n");
   say(this_player()->query_short_name() + " cancels an order for a cake. \n",this_player());
   destruct(cake);
   return 1;
   }

pay_imp(str) {
int gold;
object obj;   
   if(sscanf(str,"%d coins to imp",gold)!=1) return;
   if(gold < 20 || this_player()->query_money() < 20) {
      write("The imp says: 20 coins and no less, you miser!! \n"
          + "The imp throws the money rudely back in your face. \n");
      this_player()->add_money( -gold );
      obj = clone_object("/obj/money");
      obj->set_value(gold);
      transfer(obj,this_object());
      return 1;
      }
   write("The imp gives you a big pie, filled richly with cream. \n"
       + "The imp giggles inanely. \n");
   obj = clone_object("/players/uglymouth/cakeshop/pie");
   transfer(obj,this_player());
   this_player()->add_money( gold );
   return 1;
   }

