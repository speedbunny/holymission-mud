inherit "obj/treasure";
   reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name("confectioner's bill");
      set_alt_name("bill");
      set_alias("cakebill");
      set_short("A confectioner's bill");
   set_long("A bill from: Candy's Confectioner's shop. \n"
          + "Type 'bring the cake' in the room you want to offer the wedding cake \n"
          + "to the happy couple. We hope you enjoy it. \n");
      set_value(0);
      }
   }

init() {
   ::init();
   add_action("bring","bring");
   }

bring(str) {
object cake,store;
   if(str!="cake" && str!="the cake") return;
   ("/players/uglymouth/cakeshop/storeroom")->dummy();
   store = find_object("/players/uglymouth/cakeshop/storeroom");
   cake = present("cake bought by " + this_player()->query_real_name(),store);
   if(!cake) {
      write("This bill does not belong to you. Go buy a cake yourself. \n");
      return 1;
      }
   transfer(cake,environment(this_player()));
   tell_room(environment(this_player()),this_player()->query_short_name() + " claps in his hands and the doorway lightens up. \n"
      + "Four servents bring in a big wedding cake and put in the centre of the room. \n"
      + "Then they leave again and the doorway darkens to normal. \n");
   write("On their way out, the servants take your bill. \n");
   destruct(this_object());
   return 1;
   }
