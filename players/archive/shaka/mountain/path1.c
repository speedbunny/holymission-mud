inherit "room/room";
object goat;
reset(arg) {
  goat=find_living("goat");
  if (!goat)
   {
    goat=clone_object("/players/shaka/monsters/goat");
    transfer(goat,this_object());
   }
  if(arg) return;
  set_light(1);
  short_desc="Mountain path";
  long_desc="You are walking on a small mountain path leading \n"+
            "up into the steep and rocky mountains rising in front \n"+
            "of you\n";
  dest_dir=({"/players/shaka/mountain/path2","south",
             "/room/giant_lair","north",});
  items = ({"path","very small and going steep up",
            "mountains","they seem very tall"});
}
