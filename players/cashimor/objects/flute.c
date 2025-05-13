inherit "players/cashimor/inherit/music";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("flute");
    set_short("A beautiful flute");
    set_long("This is a beautiful flute. I think it's easy to play on it.\n");
    set_2nd_com("blow");
    set_write_snd("You play a nice tune on the flute...\n");
    set_say_snd("plays a beautiful tune on a flute!\n");
  }
}
