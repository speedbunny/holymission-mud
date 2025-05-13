inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="The barbershop";

  long_desc="Eeewwww.. there are puddles of blood on the floor and bits " +
            "of mangled flesh lying in the corners.  Yes, this is a " +
            "barbershop.  The unhappy customers are whimpering on a bench " +
            "near the door, cowering in fear.  The barber is happily " +
            "applying leeches to his latest victim.  You think you might " +
            "be sick.\n";

  dest_dir=({"/players/emerald/town/t16","north",
           });

  items=({"puddles","Large puddles of drying blood",
          "flesh","It used to have a body attached to it",
          "blood","It's supposed to be confined to your veins",
          "bench","The customers don't seem to want to move from it",
          "leeches","Ugly creatures bloated with human blood",
          "door","The escape route from this horrible place",
  });
  clone_list=({
    1,1,"barber","obj/monster", ({
      "set_name","barber",
      "set_long","A demonic barber who enjoys his work too much.\n",
      "set_race","human",
      "set_level",50,
      "set_gender",1,
      "set_ac",20,
      "set_wc",16,
      "add_money",2000,
      "set_alignment",-900,
    }),
    2,2,"customer","obj/monster", ({
      "set_name","customer",
      "set_race","human",
      "set_long","A trembling customer who doesn't want to be here.\n",
      "set_level",25,
      "set_gender",1,
      "add_money",300,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
