inherit "room/room";
 
object eagle;

reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A plateau";
    long_desc="A rocky plateau.\n"+
      "All around you are steep rocks.\n"+
      "A ravine leads up between some rocks. There seems to live an eagle here.\n"+
      "There is a nest here.\n";

    dest_dir=({
	"players/bobo/krooms/mountains/plateau","up",
   });

   items=({
     "ravine","It leads up to another plateau",
     "nest","It seems that it is the nest of an eagle"
   });
   
   if(!eagle) {
	eagle=clone_object("players/bobo/kmonster/eagle");
     move_object(eagle,this_object());
   }
}

init() {
  ::init();
  add_action("search","search"); 
}

search(str) {
  if(str!="nest") return;
  say(this_player()->query_name()+" searches in the nest.\n");
  write("You search hard, but you find nothing.\n");
  return 1;
}


