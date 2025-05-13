inherit "room/room";
int found;
reset (arg) {
if (arg) return;
set_light (1);
short_desc="In the stands.";
long_desc=
"It looks like some major fighting broke out in this area.\n"+
"Wether it was over betting or who's favorite combatant was\n"+
"better isn't apparent but what is apparent is that this\n"+
"area of the stands is deserted.  The area is full of refuse\n"+
"and rotting corspes.\n";
dest_dir=({
        "players/bobo/arena/s7.c","northeast",
        "players/bobo/arena/s9.c","southwest",
});
items=({
        "area","This portion of the stands is covered in refuse and blood",
        "combatant","There are still many battle going on in the arena",
        "stands","Big stone speps double as seats for the crowds",
        "refuse","A large quantity of trash blankets the stand in this area",
        "corpses","Many dead bodies litter the ground in this area",
});
found=0;
}
init () {
::init();
add_action("search","search");
}

search(arg) {
   if(!arg=="refuse") return 0;
   if(found) {
      write("Someone already picked through the refuse");
      say(this_player()->query_name()+" picks through the trash.\n");
      return 1;
   }
write("You found a dagger.\n");
say(this_player()->query_name()+" searches the trash for a bite to eat.\n");
move_object(clone_object("/players/bobo/obj/gdagger.c"),this_player());
found=1;
return 1;
   if(!arg=="corpses") return 0;
   write("These bodies looked to be picked clean by quicker scavengers.\n");
   return 1;
}
