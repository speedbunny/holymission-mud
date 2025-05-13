inherit "/room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Sands of Time";
  long_desc =
    "    A harsh yellow sun beats mercilessly down upon the desert.\n" +
    "The seemingly endless sands reflect the burning sunlight in all\n" +
    "directions, and the heat causes the landscape on the horizon to\n" +
    "dizzyingly blur and shimmer.\n";

  items = ({
    "sun", "DAMN! You just really messed up your eyes!",
    "desert", "The desert seems to spread out forever",
    "sand", "Endless yellow sand stretching to the horizon",
    "sands", "Sparkling sands reflecting the light of the sun",
    "landscape", "All you can see is bleak terrain for miles",
    "horizon", "You can see a shape far off in the distance",
  });
}
