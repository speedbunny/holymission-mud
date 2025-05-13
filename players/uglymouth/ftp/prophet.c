inherit "/obj/monster";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "prophet" );
  set_short( "A prophet" );
  set_long( "This prophet is an old man clothed in what used to be a "
    + "black garment, but are now not much more than dirty, dark grey rags. "
    + "His voice is louder and more clear than you'd at first expect from "
    + "such an old and wrinkled face. He continuously predicts doom.\n" );
  set_level( 5 );
  set_gender( 1 );
  load_chat( 15, ({
    "Prophet says: Death will reach out a bony hand, straight "
      + "into your chest.\n",
    "The prophet says: It will be a human's number, "
      + "and the number will be 666!\n",
    "The prophet says: Do penance! The Lord will punish you, weary "
      + "pilgrims!\n",
    "The prophet says: The end of the world will be near ... BEHOLD!\n",
    "The propher says: You will feel the ground move below your feet!\n",
    "The prophet says: A crack will appear beneath your feet. Take care!\n",
    "The prophet says: You will be caught in a shower of blood and frogs!\n",
    "The prophet says: The four apocalyptic riders will appear "
      + "on the sky.\n",
    "The prophet says: Fear the antichrist! Fear the antichrist!\n",
    "The prophet says: The Lord will judge us! Cower in fear, "
      + "ye Mortals ...\n",
    "The prophet says: Armageddon will be here to destroy the world!\n",
  }) );
}

