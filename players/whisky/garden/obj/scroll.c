inherit "obj/treasure";
reset(arg) {
if (arg) return;
  set_id("scroll");
  set_short("A magical scroll");
  set_long("There is something written on it\n");
  set_read(
        "To the whole world !!!!!\n\n"+
        "I wrote the scroll as I was a youngster.\n"+
        "This was the time I traveled to the sea.\n"+
        "I was young and I was strong and I killed\n"+
        "a lot of big monsters there. They where really\n"+
        "strong and I had often big luck that I didn't die.\n"+
        "But what I would like to say is that I have gathered\n"+
        "4 magic stars, by killing all the evil creatures there,\n"+
        "to get the best weapon gods ever seen.\n"+
        "It's a magic weapon with some evil power, but believe me\n"+
        "it was worth the price.\n\n\n"+
        "                I hope you will have too my luck Jonny\n");
  set_weight(1);
  set_value(10);
 }
