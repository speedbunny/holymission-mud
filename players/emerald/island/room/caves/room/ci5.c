inherit "/room/inherit/std_pub";

void reset(int arg) {
  if(arg) return;
  set_light(1);

  short_desc="In the orc bar";
  long_desc="You are standing in the Orcish pub.  The whole room "+
            "is filled with tables and chairs.  Gurush the bartender "+
            "is cleaning glasses and grunting musically.  There is "+
            "a big wooden sign, written in blood, fixed to the counter.\n";

  set_header("The Orcish Pub ");
  set_waiter("Gurush");

  add_item("elf blood", 8, 2, "soft", 4, "An elf blood");
  add_item("tripe soup", 40, 5,"soft", 30, "A bowl of tripe soup");
  add_item("special", 50, 6, "alco", 20, "The special");
  add_item("gurush blend", 150, 12, "alco", 80, "A Gurush blend");
  add_item("elf stew", 30, 5, "food",15, "An elf stew");

  items=({"pub","Eating here might be hazardous to your health",
          "room","It's rather dingy in here",
          "tables","Most of them are broken",
          "chairs","Some of the legs have been replaced by human bones",
          "gurush","He's incredibly ugly, even for an orc",
          "bartender","Gurush",
          "glasses","The glasses are stained with dried blood",
          "sign","You could read it",
          "blood","The lettering is in blood",
          "counter","It bears evidence of much prior use",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci4","east",
           });

  ::reset(arg);
  replace_program("/room/inherit/std_pub");

}
