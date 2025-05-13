inherit "room/room";

#define TPN this_player()->query_name()
#define TR tell_room
void reset(int arg) {

  if(arg) return;

  set_light(1);

  long_desc="The King of the World of Light has his court here.  In the " +
            "centre of the room is a HUGE throne. The throne is covered " +
            "with fabulous gem stones. Next to the throne sits the King's " +
            "famous dog, Apollo. He does not look mean, but he does not " +
            "seem to like you.\n";

  short_desc="The throne room";

  dest_dir=({"players/emerald/good/light/light23","up",
           });

  items=({"throne","The throne looks very comfortable",
          "room","A pleasant, comfortable room",
          "stones","Rubies, emeralds, sapphires, and topaz",
        });

  clone_list=({
    1,1,"dog","obj/monster", ({
      "set_name", "husky",
      "set_alias", "apollo",
      "set_race", "dog",
      "set_level", 16,
      "set_hp", 450,
      "set_al", 700,
      "set_short", "A beautiful siberian husky",
      "set_long", "This dog is fine example of the" +
                  " breed.  His paws are as large as you hands are.  "+
                  "His large, intellient eyes are watching you carefully.\n",
      "set_ac", 8,
      "set_wc", 19,
    }),      
    -1,1,"bone","obj/thing", ({
      "set_name","bone",
      "alt_alias", "biscuit",
      "set_short", "A dog bone",
      "set_long","This bone is made from pure ivory! It gleams with beauty.\n",
      "set_weight",3,
      "set_value", 800,
      "set_weight", 2,
    }),
  });

::reset();

}

void init() {
  ::init();
  add_action("_sit","sit");
}
_sit(str) {
object dog;

  dog=present("dog",this_object());
  switch (str) {
    case "throne" :
    case "on throne" :
    if(dog && present(dog)) {
      write("Apollo growls: Please do not sit on the king's throne.\n");
      return 1;
    }
    if (this_player()->query_alignment() < 0) {
      write("The throne senses that you are not pure of heart.\n" +
            "It throws you off.\n" +
            "You sail for quite a distance.\n");
      say(TPN+" gets thrown off the throne and HIGH into the air.\n");
      TR("players/emerald/good/light/light1",TPN+
         "comes sailing into the room!  They land with a THUMP!\n");
      this_player()->move_player("away#players/emerald/good/light/light1");
      return 1;
    }
    if(this_player()->query_alignment() >0) {
      write("You must be stubborn you EVIL person!\n" +
            "Since you are, the king will now see you!  Good luck!\n");
    }
    write("The throne swivels around and you find yourself in another room.\n");
    say("The throne swivels around with "+TPN+" on it.\n");
    TR("players/emerald/good/light/light25",TPN+" arrives on the throne.\n");
    this_player()->move_player("around#players/emerald/good/light/light25");
    return 1;
    default :
      notify_fail("Sit on what?\n");
      return 0;
  }
}
