inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Rules on coding";
  long_desc = "Rules on coding.\n\n"
    + "Now you know the basics that the mud is built on, you may want to\n"
    + "know more about what the things are that you can code. Actually\n" 
    + "there's only one limit, and that's your fantasy. However, to prevent\n"
    + "the mud from becoming a total chaos, there are some limitations.\n"
    + "Thematically, you should code things that fit the general theme of\n"
    + "the mud: a somewhat medieval world, where anything from legends of\n"
    + "old can come true, and magical wonders can happen. Things from modern\n"
    + "or future times should be left out.\n"
    + "Concerning the power of the things you would want to code, you can\n"
    + "find things like the maximum armour class for each type of armour,\n"
    + "maximum healing to be sold in pubs, etc. in the docs. Be sure you\n"
    + "know them, because we don't like to be hunting illegal code. But\n"
    + "then again, I'm sure you won't walk that path ;-)\n";
  dest_dir = ({
    "/players/uglymouth/appr/appr6", "next",
    "/players/uglymouth/appr/appr4", "previous",
    "/players/airborne/new/station", "leave",
  });
}

