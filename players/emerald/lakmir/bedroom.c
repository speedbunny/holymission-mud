inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="Lakmir's bedroom";
  long_desc="You have entered the bedroom of the Druid Lakmir.  The decor " +
            "is classic druidic - everything is made of oak.  The great " +
            "Druid Lakmir himself is perched in the large, luxurious bed, " +
            "screaming for something to eat.\n",

  dest_dir=({"/players/emerald/lakmir/sittingroom","west",
          });

  items=({"decor","You feel like you are inside an oak tree"
          "bedroom","It contains a bed and an irate druid",
          "bed","Quite large, with soft down covers",
        });
  
  clone_list=({
    1,1,"lakmir","/players/emerald/lakmir/lakmir",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
