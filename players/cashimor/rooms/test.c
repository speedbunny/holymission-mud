inherit "players/cashimor/inherit/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Test";
    long_desc="This is a test room of Ethereal cCashimor. "
            + "Although there could be lots of typo's in here, it "
            + "hopefully still works. This is the third ending line.\n";
    set_light(1);
  }
}
