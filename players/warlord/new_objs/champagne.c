inherit "/players/warlord/new_objs/alco_drink";


reset(arg) {
  name="champagne";
  short_desc="A bottle of best champagne";
  long_desc="You see a label with the inscription.\n"+
            " < Chateau du Whisky > anno 1456   \n";
  drinking_mess=" drinks really the best champagne.\n";
  drinker_mess=" Glurk .. Glurk.. Glonk.. Wow....that's fantastic !!!!\n"; 
  strength=14;
  weight=1;
  ::reset(arg);
  }

init() { ::init(); }
