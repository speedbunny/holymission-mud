#define TP this_player()
inherit "/obj/treasure";

int create(string str) {

  object burst, red, blue, green;

  if(str!="starburst") return 0;

  if (present("blue star",TP)
            && present("green star",TP)
            && present("red star",TP)) {
    write("The red star shoots a lousy little spark to heaven.\n");
    write("The blue star shoots a lousy little spark to heaven.\n");
    write("The green star shoots a lousy little spark to heaven.\n");
    write("But suddenly the silver star explodes in the air and melts\n");
    write("all four stars and the little Starburst appears in your hands.\n");

    say(TP->query_name()+" makes a magical gesture and suddenly a\n"+
        "ball of fire explodes into the heavens and merges four colored\n"+
        "stars to form the little Starburst.\n");

    burst =clone_object("players/whisky/seaworld/obj/starburst");
    /* Galadriel: now it adds weight for the little starburst correct */
    red = present("red star",TP);
    blue = present("blue star",TP);
    green = present("green star",TP);
    destruct(red);
    destruct(blue);
    destruct(green);
    transfer(burst,TP);
    destruct(this_object());
    return 1;
  }
}

void reset(int arg) {

  ::reset(arg);
  if (arg) return;

  set_id("star");
  set_alias("silver star");
  set_short("The silver star");
  set_long("The last part of the little Starburst or the fourth part\n"+
           "of the mighty one. Quest for the final part of the mighty\n" +
           "burst or just <create> the little burst now !!\n");
  set_value(800);
}

void init() {

  ::init();
  add_action("create","create");
}

