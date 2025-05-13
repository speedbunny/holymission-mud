inherit "/room/inherit/std_bank";
 
void reset(int flag) {
  ::reset(flag);
  if(flag) return;
 
  set_light(1);
  short_desc = "In the bank of the monk's guild";
 
  long_desc = 
    "You are in a small room next to the visitor place of "+
    "the monks guild. In front of you is a huge brown desk "+
    "where 'Wuli' a brown robed monk is sitting, calculating and "+
    "counting money. A small sign is hanging on the wall "+
    "and a big note on the desk reading: Shaolin Bank\n";
 
  items = ({
    "bottom","The bottom is made of brown earth",
    "desk","It's an oak-wooden desk",
    "sign","There is something written on it",
    "wuli","You see a noble looking monk sitting behind the desk",
    "wall","They are made of spruce wooden lathes",
    "walls","They are made of spruce wooden lathes",
    "lathes","Spruce wooden lathes"
  });
 
  clerk = "Wuli";
  taxes = 1;
  save_file = "/players/whisky/guild/room/broker";
  dest_dir = ({
    "players/whisky/guild/room/visit", "south"
  });
  ::daily_taxes();
}
