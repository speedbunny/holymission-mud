inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="A hidden passage";

  long_desc="The unhealthy colour of green slime mingled with the foul "+
            "reek rising from the standing water gives the cavern an "+
            "appalling atmosphere.  The cavern takes a sharp bend here, "+
            "leading further into darkness to the west and south.\n";

  items=({"colour","It's a really nasty shade of green",
          "slime","Unappetizing green slime",
          "water","Mildly acidic, kneedeep water",
          "cavern","A cramped, hidden passage through the volcano",
          "bend","The cavern leads to the west and south",
          "darkness","Oppressive blackness carrying a foul scent",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/c6","south",
             "/players/emerald/island/room/caves/room/c8","west",
           });

  ::reset(arg);
  replace_program("/room/room");

}
