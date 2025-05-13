inherit "/room/room";
void reset(int flag) {
   int all;
   all = sizeof(all_inventory(this_object()));
   if(all<5) {
      move_object(clone_object("/players/whisky/obj/bark_scroll"),
      this_object());
      move_object(clone_object("/players/whisky/obj/firesh_scroll"),
      this_object());
      move_object(clone_object("/players/whisky/obj/res_scroll"),
      this_object());
   }
   ::reset(flag);
   if(flag==0) {
      set_light(1);
      short_desc = "In the Snail's Sleeping Place";
      long_desc =
        "You are standing at the end of the big snail Cave. The walls\n"+
        "are made of wet earth and the bottom is covered with wet, green\n"+
        "moss. In the northern edge is a big hole, which looks like the\n"+
        "Snail's sleeping place.\n";
      property = ({"no_teleport"});
      dest_dir=({
        "/players/tatsuo/ezo/snail_hole","south",
       });
      items=({
         "walls","The walls are wet and earthy",
         "moss","Green wet moss",
       });
   }
}
