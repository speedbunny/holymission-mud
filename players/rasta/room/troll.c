inherit "room/room";
reset(arg) {
   object troll;
   object stick;
   if (!arg) {
      
      set_light(1);
      short_desc = "A Frozen Icecave";
      no_castle_flag = 0;
      long_desc = "This place is COLD!  You see a small chair sitting next to an even smaller hole.\n"
      + "You also notice a fishingpole next to the hole.  You want to get out of this cold\n";
      dest_dir =
      ({
            "/players/yrgol/toyroom.c", "toyroom",
            "/players/yrgol/firepit.c", "firepit",
       });
      items=
      ({
            "chair", "It looks quite small.",
            "hole", "The hole looks like it was used for fishing.",
            "pole", "It looks very very small",
       });
   }
   
   if(!present("troll",this_object())) {
      troll = clone_object("obj/monster");
      troll->set_name("troll");
      troll->set_alias("fred");
      troll->set_level(12);
      troll->set_short("A little troll with a BIG stick");
      troll->set_hp(110);
      troll->set_ep(3000);
      troll->set_al(200);
      troll->set_long("This little troll has a BIG stick\n");
      troll->set_ac(10);
      troll->set_wc(12);
      troll->set_chance(10);
      troll->load_chat(15, ({"The troll looks at you and says: I just want to fish.\n"}));
      if(!present("stick",this_object())) {
         stick = clone_object("obj/weapon");
         stick->set_name("stick");
         stick->set_short("BIG stick");
         stick->set_long(
            "This is a VERY B I G stick....looks powerful.\n");
         stick->set_weight(2);
         stick->set_class(12);
         stick->set_value(10);
         stick->set_hit_func(this_object());
         stick->weapon_hit(attacker)
{
write("This stick rocks!\n");
return 1000
}
      }
      
      move_object(stick,troll);
      move_object(troll, this_object());
      command("wield stick", troll);}
}
query_light() {
   return 1;
