inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Island";
  long_desc="You are on a beautiful island in the middle of a peaceful lake.\n"+
            "The lake is surrounded by large snow covered mountains, while the\n"+
            "island is warm and you can feel a gentle breeze blowing. You are\n"+
            "standing on the beach the water gently lapping up against the shore.\n"+
              "Behind you is a thick forest with lush trees and other colorful flora.\n"+
            "You can hear the calls from the tropical birds. You feel relaxed and\n"+
            "peaceful here far, far, away from the troubles of the world.\n";
  items=({
          "trees","The trees are tropical in nature, and sway gently in the warm breeze",
          "water","The water is a clear aqua-marine color and looks very inviting",
           "mountains","The mountains loom in the background and it appears there is no way over them",
           "snow","The snow is far distant and gives the mountains a regal appearance",
           "birds","Various birds of tropical species. They are all various types and colors"
    });
   property=({
     "no_teleport","no_hide"
    });
}
