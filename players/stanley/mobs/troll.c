inherit "obj/monster";
reset(arg) {
   object money;
   int lvl;
   if(arg) return;
   ::reset(arg);
   set_name("troll");
   lvl=random(5)+24;
   set_level(lvl);
   set_wc(random(6)+16);
   set_hp((lvl*30)+200);
   set_short("An ugly bridge troll");
   set_long("The troll is brown, ugly, and covered with warts. It seems intent on\nkeeping you here for dinner...IT'S dinner!!\n");
   set_al(-400);
   set_gender(1);
   set_aggressive(1);

   money = clone_object("/obj/money");
   money->set_money(random(9000)+1000);
   move_object(money, this_object());
}

attack(arg) {
   int counter;
   counter=random(100); 
   if(query_attack()) {
      write(counter+"\n");
         if(counter<10) {
         tell_room(environment(this_object()),
         "\"MEAT!!!\" The troll snarls!!\nThe troll rushes at you!!\n");
         ::attack();
      }
      if(counter>80) {
         tell_room(environment(this_object()),
         "The troll makes a lunge for you!!!\n");
         ::attack();
      }
      if(counter>20 && counter < 50) {
         tell_room(environment(this_object()),
         "The troll bellows with rage!!!\n");
         ::attack();
      }
      if(counter>50 && counter<80) {
         tell_room(environment(this_object()),
         "The troll's wounds look like they're healing!!!\n");
         this_object()->add_hp(random(10)+10);
         ::attack();
      }
   }
}

second_life(ob) {
   write("The troll screams in anger and falls to the ground!\n");
   if(this_player()->query_level()>19) return 0;
   shout(this_player()->query_name()+" has slain the evil bridge troll!\n");
   ::second_life();   
   return 0; 
}
