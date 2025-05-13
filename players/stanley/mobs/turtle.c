inherit "obj/monster";
reset(arg)  {
   object shell;
   ::reset(arg);
   set_name("turtle");
   set_alias("snapping turtle");
   set_level(12);
   set_hp(200);
   set_short("A huge snapping turtle");
   set_long("Your luck seems to have deserted you...this huge snapping turtle\nsees you as a threat to it's habitat!!\n");
   set_al(-150);
   set_gender(1);
   set_aggressive(1);
   shell = clone_object("/players/stanley/obj/shell");
   move_object(shell,this_object());
}

attack(arg) {
   int counter;
   counter=random(100); 
   if(query_attack()) {
      write(counter+"\n");
      if(counter<10) {
      tell_room(environment(this_object()),
      "\"HISS!!!\" The turtle snaps at you!!\n");
      ::attack();
   }
   if(counter>80) {
      tell_room(environment(this_object()),
      "The turtle extends it's neck and bites at your leg!!\n");
      ::attack();
      }
   }
}
