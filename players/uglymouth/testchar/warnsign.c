inherit "obj/thing";

void reset(int arg) {
  if(arg) return 0;

  set_name("WARNING SIGN");
  set_alias("warning sign");
  set_alt_name("sign");
  set_short("WARNING SIGN");
  set_long("A BIG WARNING SIGN! READ IT!!\n");
  set_read("WARNING!!\n"
    + "Tonight I am doing some recoding of my area, to make it\n"
    + "consume less cpu-time (less lag!). You might therefore\n"
    + "encounter some rooms that are temporarily not accessable.\n"
    + "Some rooms might be renewed more often than usual.\n"
    + "It's only TEMPORARY and should not cause you much trouble.\n"
    + "But my excuses for some inconveniences you might encounter.\n"
    + "\n                           Viking Lord Uglymouth\n");
  set_can_get(0);
  }
