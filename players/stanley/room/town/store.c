inherit "room/room";
object baker;
reset(arg) {

   if(!baker) {
      baker=clone_object("/wiz/belboz/mobs/baker");
      move_object(baker,this_object());
   }

   if(arg) return;
   set_light(1);
   short_desc="Bakery";
   long_desc =
   "Though is smells wonderful in here, this shop is not open for business yet\n" +
   "try again soon!\n";

dest_dir=({
   "/wiz/belboz/room/town/road2","west",
});

items=({  });
}
