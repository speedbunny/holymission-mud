/* Edited by Colossus 030494 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "Base level of the vampire castle";
    long_desc=
    "The main entrance hall of the castle is a grand affair. Decorations\n"+
    "of incredible value make this an exquisite sight to behold. Mother-of-\n"+
    "pearl sheathes the huge supporting pillars and marble serves as tiles\n"+
    "for the floor. A gigantic portrait of some family hangs directly in\n"+
    "front of you and suits of armour line the walls. The whole room is\n"+
    "a grand affair. Even the banisters that go up or down are gold-plated.\n"+
    "Despite all the fancy ornaments and rich ambience, you feel a cold\n"+
    "dread at the bottom of your stomach. You feel the eyes of the picture\n"+
    "stare right at you and follow your every movement even.\n";
    items=({
      "stairs", "The stairs are also marble and their banisters are\n"+
      "made of gold. They allow you to go up or down",
      "banisters", "The banisters are gold-plated and provide support for\n"+
      "those going up or down the stairs",
      "ornaments", "The ornaments are of incalculable worth and while you\n"+
      "would love to loot this place, you do not have the time\n"+
      "or the luxury to do it as anyone could come in while you\n"+
      "are doing so",
      "picture", "The picture is of a large family and they all bear\n"+
      "solemn expressions and their painted faces stare stonily\n"+
      "at you",
      "portrait", "The portrait is of a large family and they all bear\n"+
      "solemn expressions and their painted faces stare stonily\n"+
      "at you",
      "eyes", "It could be your imagination but you feel the eyes on\n"+
      "the picture following your every movement",
      "pillars", "The pillars are graceful and sheathed with mother-of-\n"+
      "pearl",
    });
    dest_dir=({
      "/players/sherman/darkl8","east",
      "/players/sherman/vtower2","up",
      "/players/sherman/vtower6","down"
    });
}
