inherit "room/room";
 
#define me capitalize(this_player()->query_name())
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
object dog, bone;
int g;
 
reset(arg)
{
     g=0;
	if(!arg) {
     set_light(1);
     long_desc = "Throne room\n\n" +
        "     The king of the world of light has his court here.\n" +
        "     In the center of the room is a HUGE throne. The throne\n" +
        "     is covered with fabulous gem stones. Next to the throne\n" +
        "     sits the King's famous dog, Apollo. He does not look mean, but\n" +
        "     he does not seem to like you.\n\n";
     short_desc = "The throne room";
     dest_dir = ({
        "players/animal/light/light23","up",
     });
     items = ({
          "throne","The throne looks very comfortable",
     });
	}
     extra_reset();
     return;
}
 
query_long() {
    return long_desc;
}
 
query_light() {
    return 1;
}
 
init() {
     ::init();
     add_action("search","search");
     add_action("sit","sit");
     add_action("fear","fear");
	add_action("howl","howl");
}
 
extra_reset()  {
               if (!dog || !living(dog)) {
         dog = clone_object("obj/monster");
         call_other(dog, "set_name", "husky");
         call_other(dog, "set_alias", "apollo");
         call_other(dog, "set_race", "dog");
         call_other(dog, "set_level", 16);
         call_other(dog, "set_hp", 450);
         call_other(dog, "set_al", 700);
         call_other(dog, "set_short", "A beautiful siberian husky");
         call_other(dog, "set_long", "This dog is fine example of the" +
          " breed. His paws are as large as your hands are.\n");
         call_other(dog, "set_ac", 8);
         call_other(dog, "set_wc", 19);
         call_other(dog, "set_aggressive", 0);
         bone = clone_object("obj/treasure");
         call_other(bone, "set_id", "bone");
         call_other(bone, "alt_alias", "bisket");
         call_other(bone, "set_short", "A dog bone");
         call_other(bone, "set_long",
         "This bone is made from pure ivory! It gleams with beauty.\n");
         call_other(bone, "set_weight",3);
         call_other(bone, "set_value", 800);
         call_other(bone, "set_weight", 2);
         transfer(bone, dog);
         move_object(dog, this_object());
          }
}
 
search(str) {
    if (!str) str = "room";
    if (str == "room") {
            write("You find nothing unusual.\n");
          say(me + " searches the room.\n");
            return 1;
          }
     return 0;
}
 
 
sit(str)  {
          if(str == "throne" || str == "on throne") {
if(dog && present(dog)) {
     write("Apollo growls: 'please do not sit on the king's throne.'\n");
     return 1;
     }
   if ((call_other(this_player(), "query_alignment",0) < 0) && g==0) {
   write("The throne senses that you are not pure of heart and throws you" +
 
                  " off.\nYou sail for quite a distance.\n\n");
     say(me+" gets thrown off the throne and HIGH into the air.\n");
   tell_room("players/animal/light/light1",me+" comes sailing into the room!" +
     " They land with a THUMP!\n");
     move_object(this_player(),"players/animal/light/light1");
     call_other(this_player(),"look");
     g=g+1;
     return 1;
     }
  if(call_other(this_player(), "query_alignment",0) < 0) {
  write("You must be stubborn you EVIL person!\n\n");
  write("Since you are the king will now see you! Good luck!\n");
  }
  write("The throne swivels around and you find yourself in another room.\n\n");
  say("The throne swivels around with "+me+" on it.\n");
     tell_room("players/animal/light/light25","A throne appears with "+me+" on it.\n");
     move_object(this_player(),"players/animal/light/light25");
     call_other(this_player(),"look");
     return 1;
     }
     return 0;
}
 
fear(str) {
	if(!dog) return;
          if(!str) str == "dog";
          if(str == "dog" || str == "apollo" || str == "husky") {
          write("Apollo roars: OH YEA????? WELL I WILL 'FEAR' YOU!!!!\n");
          write("Apollo roars: B\n"+
                "               O\n"+
                "                O\n"+
                "                 O\n"+
                "                  O\n"+
                "                   O\n"+
                "                    O\n"+
                "                     !\n"+
                "                      !\n"+
                "                       !\n\n\n");
          write("You get so scared you run all the way to the pub!\n\n");
          say(me+" leaves the room running for his life!\n");
          tell_room("room/pub2",me+" runs into the pub screaming and babbling "+
          "about some BIG dog.\n");
          move_object(this_player(),"room/pub2");
          call_other(this_player(),"look");
          return 1;
          }
return;
}
 
 
realm() { return "NT"; }
