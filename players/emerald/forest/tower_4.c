inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);

  short_desc="Top of the tower";
  long_desc="It feels like many hundreds of feet have passed since you " +
            "started climbing this tower, but, finally, you have arrived " +
            "at the top.  And it's certainly worth it, for the view you " +
            "get is fantastic!  You can see down to all of Holy Mission, " +
            "even Warlord's Castle and the Mage Tower are below you.  To " +
            "the east, the bleak masses of the Mountains of Madness can " +
            "be seen.  In this room there are a number of interesting " +
            "items that might be worthy of further attention.  Amongst " +
            "them are a telescope, a roulette wheel and a strange lever.\n";

  dest_dir=({"/players/emerald/forest/tower_3","down",
           });

  items=({"view","As I said, it's fantastic.  Do we have to have an " +
                 "attack of hyperbole?",
        "castle", "Warlord's Castle.  Need to know anything else?",
        "warlord's castle", "Warlord's Castle.  Need to know anything else?",
        "warlords castle", "Warlord's Castle.  Need to know anything else?",
        "mage tower", "It's the Mage Tower.  Geesh you are inquisitive",
        "mountains", "The Mountains of Madness.  That's where you " +
                     "go to solve the Haunter of the Dark quest.  " +
                     "Probably you should be trying it instead of sitting" +
                     "on your butt in here",
        "tower", "Which tower?",
        "items", "I told you what they were",
        "telescope", "Star gazing, anyone?",
        "wheel", "It's a roulette wheel.  Why not spin it?",
        "lever", "There isn't one actually, I just put it in here to " +
                 "see who looks at everything that can be seen in the " +
                 "room.  Your name has now been placed in a log file of " +
                 "everyone who looks at the lever and will be posted " +
                 "some day on the Adventurers Guild Board",
      });


  ::reset();
}

void init() {
  ::init();
  add_action("_spin", "spin");
}

int _spin(string str) {
  int res;
  if(str!="wheel" && str!="roulette wheel" && str!="roulette") {
    notify_fail("Spin what?\n");
    return 0;
  }
  res=random(37);
  write("You spin the wheel and spin a " + res + ".\n");
  say((string)this_player()->query_name() + " spins the wheel and spins a "
        + res + ".\n");
  switch(res) {
    object o, *u;
    string s;
    int i;
    case 0 .. 4:
      o=clone_object("players/emerald/forest/draconian");
      tell_room(this_object(), (string)o->short()
        + " arrives in a puff of smoke.\n");
      move_object(o, this_object());
      break;
    case 5 .. 9:
      write("You are magically transferred somewhere.\n");
      switch(random(10)) {
        case 0: s="room/giant_conf"; break;
        case 1: s="players/moonchild/haunter/waste55"; break;
        case 2: s="players/emerald/town/bu1"; break;
        case 3: s="players/padrone/walker/bridge"; break;
        case 4: s="room/shore/s40"; break;
        case 5: s="room/sub/after_trap"; break;
        case 6: s="players/kelly/rooms/vill/grocery"; break;
        case 7: s="room/church"; break;
        case 8: s="players/emerald/forest/f5-6"; break;
        case 9: s="players/moonchild/cave/c22"; break;
      }
      this_player()->move_player("X#" + s);
      break;
    case 10 .. 13:
      write("A green light starts glowing in the tower.\n");
      shout("A green light flashes through the skies!\n");
      call_out("thunder", 10, 0);
      break;
    case 14 .. 17:
      this_player()->frog_curse(!this_player()->query_frog());
      break;
    case 18 .. 22:
      write("You feel a terrible desire to shout something silly.\n");
      command("chat Foo! Foo! I say Foo!", this_player());
      break;
    case 23 .. 27:
      write("A frisbee appears in your hands.\n");
      move_object(clone_object("players/moonchild/gnome/shop/frisbee"),
         this_player());
      break;
    case 28 .. 29:
      i=set_light(0);
      if(i>0) {
        tell_room(this_object(), "It turns dark.\n");
        set_light(-i);
      }
      else {
        tell_room(this_object(), "You can see again.\n");
        set_light(1);
      }
      break;
    case 30 .. 32:
      o=clone_object("players/moonchild/misc/duckie");
      tell_room(this_object(), (string)o->short() + " says: Quack!\n");
      move_object(o, this_object());
      break;
    case 33 .. 34:
      if(!present("blancmange_curse", this_player()))
        move_object(clone_object("players/emerald/forest/blancmange"),
                this_player());
      write("Suddenly, some pink blancmange flies down from the ceiling " +
            "all over you.\n");
      say("Some pink blancmange falls onto " +
        (string)this_player()->query_name() + ".\n");
      this_player()->set_title("is covered in pink blancmange");
      this_player()->set_smell("You smell icky pink blancmange.");
      break;
    default:
      write("You hear a loud grinding noise, then nothing.\n");
      break;
  }
  return 1;
}

void thunder() {
  write("You hear a mighty crash and thunder. The green light goes out.\n");
  shout("You hear a mighty crash, and thunder.\n");
}
