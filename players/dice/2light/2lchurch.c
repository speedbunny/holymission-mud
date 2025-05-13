
inherit "/players/dice/rooms/wakeup.c";
object e_spirit;
int i;
int has_killed;
reset(arg) {
 has_killed = 0;
  if (!arg) {
    set_light(1);
    short_desc="Twilight church";
    long_desc=
        "You are in the twilight church. This church does not have the\n"+
        "service of reviving ghosts !!!\n"+
        "The unholyness of this place seems to be here like a living thing.\n"+
        "You feel really bad being here, and decide not to stay here to\n"+
        "long, as the dark spirits might come to get you\n";
       dest_dir= ({
        "players/dice/2light/2l2","south",
        });
           items =({
            "spirits","An evil and dark spirit, not present at the moment",
            "spirit","An evil and dark spirit, not present at the moment",
            "church","The twilight church",
            "place","A strange church",
            "thing","A strange force, almost a living creature",
             });
 }
}
init()
   {
   ::init();
   add_action("pray","pray");}
pray(){
  if(has_killed == 1){
 write("You pray, and pray, but nothing happens.\n");
 return 1;
 }
 if(!e_spirit){
    for(i=0;i<5;i++){
    e_spirit = clone_object("/players/dice/obj/e_spirit");
    move_object(e_spirit,this_object());
    write("You pray to an evil god, and he hears hears your pray...\n");
 has_killed = 1;
    }
   }
  }
